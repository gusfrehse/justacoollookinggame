#!/bin/bash

set -x

cc="g++"
std="-std=c++2a"
idir="-I./include/"
ldir=""
libs="-lglfw -ldl -lpthread"
exe="game"

cat ./srcfiles.txt | sed 's/\\/\//g' > tmpsrcfilesunix.txt
source ./tmpsrcfilesunix.txt
rm ./tmpsrcfilesunix.txt

cmd="$cc -g $std -o $exe $sourcefiles $idir $ldir $libs"
$cmd
