#!/bin/bash

if [ -z $1 ]
then
  tag="minisleep"
else
  tag=$1
fi

if [ ! -d "Dockerimage" ]
then
  mkdir Dockerimage
fi

docker build --tag $tag .
docker save $tag | gzip >Dockerimage/$tag.tar.gz
