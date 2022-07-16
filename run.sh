echo "Ready?"
gcc -c filter.c 
gcc -c helpers.c 
gcc filter.o helpers.o -o filt.exe
rm filter.o
rm helpers.o
echo "Type \"./filt.exe [filter] inputfile outputfile \" to run the executable"