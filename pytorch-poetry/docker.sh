#!/bin/bash
# https://github.com/RUB-SysSec/GANDCTAnalysis/blob/master/docker.sh

# usage ----------------------------------------------
# bash docker.sh build  # build image
# bash docker.sh shell  # run container as user
# bash docker.sh root  # run container as root
# ----------------------------------------------------

DATASET_DIRS="$HOME/dataset"
DATA_DIRS="$HOME/data"

TORCH_VERSION="torch-1.9.0"
DOCKERFILE_NAME="Dockerfile.cu111"

build()
{
    docker build . -f docker/$DOCKERFILE_NAME --target $TORCH_VERSION --build-arg USER_UID=`(id -u)` --build-arg USER_GID=`(id -g)` -t $TORCH_VERSION
}

shell() 
{
    docker run --rm --gpus all --shm-size=16g -it -v $(pwd):/app -v $DATASET_DIRS:/dataset -v $DATA_DIRS:/data $TORCH_TAG /bin/bash
}

root()
{
    docker run --rm --gpus all --shm-size=16g --user 0:0 -it -v $(pwd):/app -v $DATASET_DIRS:/dataset -v $DATA_DIRS:/data $TORCH_TAG /bin/bash
}

help()
{
    echo "usage: bash docker.sh [build|shell|root|help]"
}


if [[ $1 == "build" ]]; then
    build $2
elif [[ $1 == "shell" ]]; then
    shell 
elif [[ $1 == "root" ]]; then
    root
elif [[ $1 == "help" ]]; then
    help
else
    help
fi
