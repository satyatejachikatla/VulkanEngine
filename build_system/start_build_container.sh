#!/bin/bash

THIS_FILE_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
TOPDIR=$(realpath $THIS_FILE_DIR/../)
DOCKER_COMPOSE_FILE=$TOPDIR/build_system/docker-compose.yml

echo "--------------"
echo TOPDIR:$TOPDIR
echo DOCKER_COMPOSE_FILE:$DOCKER_COMPOSE_FILE
echo "--------------"


docker-compose -f $DOCKER_COMPOSE_FILE build 
docker-compose -f $DOCKER_COMPOSE_FILE up &

printf "Wating to start  "
DOCKER_ID="CONTAINER"
while [ $DOCKER_ID == "CONTAINER" ]; do
    DOCKER_ID=`docker ps -f "name=build" | awk '{print $1}' | head -2 | tail -1`
    printf "."
    sleep 2
done
echo

docker exec -it $DOCKER_ID /bin/bash

docker-compose -f $DOCKER_COMPOSE_FILE down
