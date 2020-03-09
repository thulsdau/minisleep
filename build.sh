#!/bin/sh

#test if musl libc is availalbe
#using musl libc will result in significantly smaller binary
#on ubnuntu install via: apt install musl musl-dev musl-tools
#see https://musl.libc.org
which musl-gcc >/dev/null

if [ $? -eq 0 ] ; then
	compiler=musl-gcc
else
	compiler=cc
fi
	
$compiler sleep.c -o sleep -static -s -Wall -Os
