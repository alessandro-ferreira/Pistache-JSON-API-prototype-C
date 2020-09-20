
#include "chart_endpoint.h"

void ChartEndpoint::get(const Rest::Request& request, Http::ResponseWriter response) {
    // ṕrint headers
    const auto headers = request.headers().rawList();
    for(const auto header : headers) {
        std::cout << "< " << header.first << ": " << header.second.value() << std::endl;
    }
    
    // extract json body
    const auto json_body = request.body();
    if (!json_body.size()) {
        response.send(Http::Code::Bad_Request, "JSON body not found");
        return ;
    }
    
    // parse json body using rapidjson
    Document data;
    data.Parse(json_body.c_str());
    
    // validate filters
    if(!data.HasMember("providers")) {
        response.send(Http::Code::Bad_Request, "Field providers not found");
        return ;
    }
    if(!data["providers"].IsArray() || data["providers"].GetArray().Empty()) {
        response.send(Http::Code::Bad_Request, "Invalid field providers");
        return ;
    }
    const auto providers = data["providers"].GetArray();
    
    if(data.HasMember("pair") && !data["pair"].IsString()) {
        response.send(Http::Code::Bad_Request, "Invalid field pair");
        return ;
    }
    const std::string pair = (data.HasMember("pair")) ? data["pair"].GetString() : "";
    
    if(data.HasMember("start") && !data["start"].IsString()) {
        response.send(Http::Code::Bad_Request, "Invalid field start");
        return ;
    }
    const std::string start = (data.HasMember("start")) ? data["start"].GetString() : "2000-01-01 00:00:00";
    
    if(data.HasMember("end") && !data["end"].IsString()) {
        response.send(Http::Code::Bad_Request, "Invalid field end");
        return ;
    }
    const std::string end = (data.HasMember("end")) ? data["end"].GetString() : "2020-09-15 23:59:59";
    
    // create rapidjson response document
    Document json_response;
    json_response.SetArray();
    Document::AllocatorType& allocator = json_response.GetAllocator();
    
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    
    // for each provider generate random values
    for(const auto& provider : providers) {
        for(const std::string suffix : std::vector<std::string>({"feed", "vwap"})) {
            Value item;
            item.SetObject();
            
            std::string name = provider.GetString() + std::string(" ") + suffix;
            item.AddMember("name", Value().SetString(name.c_str(), name.length(), allocator), allocator);
            
            Value points;
            points.SetArray();
            
            std::uniform_int_distribution<> dist(1, 10); // define the range
            int npoints = dist(gen); // generate the numbers
            for(int idx = 0; idx < npoints; idx++) {
                Value point;
                point.SetObject();

                char random_date[21];
                std::snprintf(random_date, 21, "%04d-%02u-%02u %02u:%02u:%02u", 2019, rand()%12+1, rand()%30+1, rand()%24, rand()%60, rand()%60);
                point.AddMember("date", Value().SetString(random_date, strlen(random_date), allocator), allocator);
                
                std::uniform_real_distribution<double> distd(0, 2);
                point.AddMember("price", distd(gen), allocator);
                
                points.PushBack(point, allocator);
            }
            
            item.AddMember("points", points, allocator);
            
            json_response.PushBack(item, allocator);
        }
    }
    
    // Dump rapidjson document into a string
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    writer.SetMaxDecimalPlaces(4);
    
    json_response.Accept(writer);
    
    std::cout << "> HTTP/1.1 200 OK" << std::endl;
    std::cout << buffer.GetString() << std::endl;
    
    response.send(Http::Code::Ok, buffer.GetString(), MIME(Application, Json));
}
