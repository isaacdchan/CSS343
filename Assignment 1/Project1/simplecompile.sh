date

echo "* compiling with clang++ to create an executable called myprogram"
g++ .cpp -o myprogram

echo " running myprogram"
./myprogram > output.txt 2>&1

# valgrind will detect memory leaks
echo " running with valgrind"
valgrind ./myprogram.exe

echo " cleaning up, deleting myprogram"
rm myprogram

date