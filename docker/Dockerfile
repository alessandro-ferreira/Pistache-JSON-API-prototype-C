FROM ubuntu:20.04

# avoid interactive dialog when configuring tzdata
ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update --fix-missing
# RUN apt-get install cmake -y 
RUN apt-get install build-essential -y
RUN apt-get install software-properties-common -y 

RUN add-apt-repository ppa:pistache+team/unstable
RUN apt-get update --fix-missing
RUN apt-get install libpistache-dev -y

# RUN apt-get install libssl-dev
# RUN apt-get install libcurl4-openssl-dev
# RUN apt-get install libnet

RUN mkdir -p /opt/palladris
WORKDIR /opt/palladris

ADD api.tar.gz .

RUN make

EXPOSE 8080

CMD ["bin/api"]
