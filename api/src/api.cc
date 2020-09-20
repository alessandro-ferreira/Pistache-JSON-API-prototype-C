#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "endpoints.h"

using namespace Pistache;

Rest::Router router;

void setupRoutes() {
    Rest::Routes::Get(router, "/market-data/chart", Rest::Routes::bind(ChartEndpoint::get));
    Rest::Routes::Get(router, "/market-data/details/:id", Rest::Routes::bind(DetailsEndpoint::get));
    Rest::Routes::Get(router, "/blotter/table", Rest::Routes::bind(TableEndpoint::get));
}

int main() {
    std::shared_ptr<Http::Endpoint> endpoints;

    Address addr(Ipv4::any(), Port(9080));
    endpoints.reset(new Http::Endpoint (addr));
    
    auto opts = Http::Endpoint::options()
        .threads(1)
        .flags(Tcp::Options::ReuseAddr);
    endpoints->init(opts);
    
    setupRoutes();
    endpoints->setHandler(router.handler());
    endpoints->serve();
    
    return 0;
}


// #include <pistache/endpoint.h>
// 
// #include "hello_handler.h"
// 
// int main() {
//     
//     Http::listenAndServe<HelloHandler>(Pistache::Address("*:9080"));
// }
