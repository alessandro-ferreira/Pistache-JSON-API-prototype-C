#ifndef __DETAILS_ENDPOINT_H
#define __DETAILS_ENDPOINT_H

#include <pistache/endpoint.h>
#include <pistache/router.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

#include <iostream>
#include <random>
#include <string>
#include <vector>

using namespace Pistache;
using namespace rapidjson;

class DetailsEndpoint {
    
    public:
        static void get(const Rest::Request& request, Http::ResponseWriter response);

};

#endif
