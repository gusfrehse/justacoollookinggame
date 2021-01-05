cc="g++"
std="-std=c++17"
idir="-I./include/"
ldir=""
libs="-lglfw3 -ldl -lpthread"
exe="game"
sourcefiles="./src/main.cpp ./src/shader.cpp ./src/shader_program.cpp ./src/gl3w.c"

$cc -g $std -o $exe $sourcefiles $idir $ldir $libs
