date

echo "* compiling with g++ to create an executable called myprogram"
g++ --version
g++ -std=c++14 -Wall -Wextra -Wno-sign-compare *.cpp -g -o myprogram

# valgrind will detect memory leaks
echo " running with valgrind"
valgrind ./myprogram

echo " cleaning up, deleting myprogram"
rm myprogram

date
