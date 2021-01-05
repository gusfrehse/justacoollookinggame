:: @echo off

set cc=g++
set std=-std=c++17
set idir=-I.\include\
set ldir=-L.\winlib\
set libs=-lglfw3 -lgdi32
set exe=game.exe

call .\sourcefiles.txt

%cc% -g %std% -o %exe% %sourcefiles% %idir% %ldir% %libs%
