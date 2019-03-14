#!/bin/bash
# Simple script to build pyalpm against pacman-git from a checkout

CWD=$(pwd)
PACMAN_DIR=$(pwd)/pacman
TMP_DIR=$(mktemp --suffix pacman -d)


if [ -d $PACMAN_DIR ]; then
  cd $PACMAN_DIR && git pull --ff-only
else
  git clone https://git.archlinux.org/pacman.git/ $PACMAN_DIR
fi

cd $PACMAN_DIR

./autogen.sh

./configure --prefix=/usr

make -C lib/libalpm DESTDIR=${TMP_DIR} install-libLTLIBRARIES install-includeHEADERS

cd $CWD
CC=gcc CPATH=$TMP_DIR/usr/include LD_LIBRARY_PATH=$TMP_DIR python3 setup.py build
