g++ -o generate_parentheses.o -c ./solution/src/generate_parentheses.c  -I ./solution/include/

g++ -o test_generate_parentheses.o -c ./tests/src/generate_parentheses.cpp -I ./ -I ./solution/include/

g++ -o main.o -c ./gtest/main/main.cpp -I ./

g++ -o a.out *.o -I./include -L./gtest/lib -lgtest -lpthread
