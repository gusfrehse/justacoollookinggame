:: @echo off

set cc=g++
set std=-std=c++2a
set idir=-I.\include\
set ldir=-L.\lib\
set libs=-lglfw3 -lgdi32
set exe=game.exe
set sourcefiles=.\src\main.cpp .\src\shader.cpp .\src\shader_program.cpp .\src\gl3w.c

%cc% %std% -o %exe% %sourcefiles% %idir% %ldir% %libs%
