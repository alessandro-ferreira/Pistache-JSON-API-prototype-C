
#include "details_endpoint.h"

void DetailsEndpoint::get(const Rest::Request& request, Http::ResponseWriter response) {
    auto id = request.param(":id").as<int>();
    
    response.send(Http::Code::Ok, "In development,,,");
}
