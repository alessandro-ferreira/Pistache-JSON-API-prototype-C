#!/bin/bash
  
BASEDIR=$(dirname "$0")
cd $BASEDIR

tar -C ../api -cf api.tar.gz .

docker build --tag palladris:1.0 . 

rm -f api.tar.gz

docker create --publish 8080:9080 --name palladris palladris:1.0
