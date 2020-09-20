
#include "table_endpoint.h"

void TableEndpoint::get(const Rest::Request& request, Http::ResponseWriter response) {

    response.send(Http::Code::Ok, "In development,,,");
}
