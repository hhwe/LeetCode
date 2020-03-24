g++ -o ./build/solution.o -c ./solution/src/generate_parentheses.cpp  -I ./solution/include/

g++ -o ./build/test.o -c ./test/src/generate_parentheses.cpp -I ./ -I ./solution/include/

g++ -o ./build/main.o -c ./gtest/main/main.cpp -I ./

g++ -o ./build/a.out ./build/*.o -I./include -L./gtest/lib -lgtest -lpthread
