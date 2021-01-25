:: @echo off

set cc=g++
set std=-std=c++2a
set idir=-I.\include\
set ldir=-L.\winlib\
set libs=-lglfw3 -lgdi32
set exe=game.exe

:: compatibility with linux
set /p sfilesstring=<srcfiles.txt
set %sfilesstring%
set sourcefiles=%sourcefiles:"=%
echo %sourcefiles%

%cc% -g %std% -o %exe% %idir% %ldir% %sourcefiles% %libs%
