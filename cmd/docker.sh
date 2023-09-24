#!/bin/bash

# usage ------------------------------------------------------------------------
# bash docker.sh build  # build image
# bash docker.sh shell  # run container as user
# bash docker.sh root  # run container as root
# ------------------------------------------------------------------------------

DATASET_DIRS="$HOME/dataset"
DATA_DIRS="$HOME/data"

build()
{
    docker build . -f docker/nvc/Dockerfile --build-arg USER_UID=`(id -u)` --build-arg USER_GID=`(id -g)` -t pytorch
}

shell() 
{
    docker run --rm --gpus all --shm-size=16g -it -v $(pwd):/app -v $DATASET_DIRS:/dataset -v $DATA_DIRS:/data pytorch /bin/bash
}

root()
{
    docker run --rm --gpus all --user 0:0 --shm-size=16g -it -v $(pwd):/app -v $DATASET_DIRS:/dataset -v $DATA_DIRS:/data pytorch /bin/bash
}


if [[ $1 == "build" ]]; then
    build
elif [[ $1 == "shell" ]]; then
    shell 
elif [[ $1 == "root" ]]; then
    root
else
    echo "error: invalid argument"
fi
