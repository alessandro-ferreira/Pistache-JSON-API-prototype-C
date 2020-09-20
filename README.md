## __Title: Palladris-JSON-API-prototype-Test-C++__
#### Author:
- Alessandro dos Santos Ferreira

**NOTE**: This script requires Docker installation ( more info on https://docs.docker.com/engine/install/ ).

## How to Install
- Test your Docker installation
```
$ docker --version
$ docker run hello-world
```
- If Docker is correctly installed, execute the following commands:
```
$ cd docker
```
```
$ ./build.sh
```
## How to use:
- Execute the following command to start the server :
```
$ ./deploy.sh
```
## How to test (using curl):
- Chart - Endpoint /market-data/chart
```
$ curl -X GET http://127.0.0.1:8080/market-data/chart -d '{"providers": ["CBOE"]}'
$ curl -X GET http://127.0.0.1:8080/market-data/chart -d '{"providers": ["CBOE", "UBS"], "pair": "EUR/GBP", "start" : "2019-10-05 18:00:00", "end": "2020-06-08 21:17:00"}'
```
- Table - Endpoint /blotter/table
```
$ curl -X GET http://127.0.0.1:8080/blotter/table -d '{"pairs": ["EUR/GBP"]}'
$ curl -X GET http://127.0.0.1:8080/blotter/table -d '{"pairs": ["EUR/GBP", "EUR/USD", "GBP/USD"], "min_price": 0.4138, "max_price": 1.8444, "min_qty": 59922123, "max_qty": 82820689, "start" : "2019-11-18 00:37:00", "end": "2020-07-09 00:32:00"}'
```
- Chart details - Endpoint /market-data/details/id
```
curl -X GET http://127.0.0.1:8080/market-data/details/123 -d '{"providers": ["CBOE", "UBS"]}'
```
