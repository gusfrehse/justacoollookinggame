:: @echo off

set cc=g++
set std=-std=c++17
set idir=-I.\include\
set ldir=-L.\winlib\
set libs=-lglfw3 -lgdi32
set exe=game.exe
set sourcefiles=.\src\main.cpp .\src\shader.cpp .\src\shader_program.cpp .\src\gl3w.c

%cc% -g %std% -o %exe% %sourcefiles% %idir% %ldir% %libs%
