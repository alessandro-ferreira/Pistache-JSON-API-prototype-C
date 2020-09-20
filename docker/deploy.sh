#!/bin/bash

case $1 in
    start|"")
        echo "Starting container..." 
        docker start palladris
        ;;
    stop)
        echo "Stopping container..." 
        docker stop palladris
        ;;
    restart)
        echo "Restarting container..." 
        docker restart palladris
        ;;
    remove)
        echo "Removing container..." 
        docker rm --force palladris
        ;;
    logs)
        echo "Showing container logs..." 
        docker logs -f palladris --tail 20
        ;;
    bash)
        echo "Accessing container bash..." 
        docker exec -it palladris /bin/bash
        exit
        ;;
    *) 
        printf "Usage: ./deploy [OPTION]\n\nOPTIONS: start | stop | restart | remove | logs | bash \n" 
        exit
        ;;
esac

docker ps -a --no-trunc --filter name=^/palladris$
