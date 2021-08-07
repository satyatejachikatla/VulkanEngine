### Dependencies

* docker : https://docs.docker.com/engine/install/
* docker-compose : https://docs.docker.com/compose/install/

## Build Debug

### Start build container

```
docker-compose build
docker-compose up
```

### Start build terminal
```
DOCKER_ID=`docker ps -f "name=build" | awk '{print $1}' | head -2 | tail -1`
docker exec -it $DOCKER_ID /bin/bash
```

### Stop build container

```
docker-compose down
```