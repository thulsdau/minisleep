#!/bin/sh

#Smallest binary size with dietlibc
#Install on Ubuntu via: apt install dietlibc-dev
#See also: https://www.fefe.de/dietlibc/

#Second smallest binary size with musl libc
#Install on Ubuntu via: apt install musl musl-dev musl-tools
#See https://musl.libc.org

if [ -x "`which diet`" ] ; then
	compiler="diet gcc"
elif [ -x "`which musl-gcc`" ] ; then
	compiler="musl-gcc"
else
	compiler="cc"
fi

cmd="$compiler -Wl,-z,noseparate-code -pipe -s -fno-ident -Wl,-z,norelro -Wl,--build-id=none -static -Os -Wall -o sleep sleep.c"
echo $cmd
${cmd}
cmd="strip -x -R .comment -R .note sleep"
echo $cmd
${cmd}
