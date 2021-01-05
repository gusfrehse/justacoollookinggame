cc="g++"
std="-std=c++17"
idir="-I./include/"
ldir=""
libs="-lglfw3 -ldl -lpthread"
exe="game"

cat ./srcfiles.txt | sed 's/\\/\//g' > tmpsrcfilesunix.txt
source ./tmpsrcfilesunix.txt
rm ./tmpsrcfilesunix.txt

cmd="$cc -g $std -o $exe $sourcefiles $idir $ldir $libs"
echo $cmd
$cmd
