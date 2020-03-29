g++ -o ./build/solution.o -c ./solution/src/$1  -I./solution/include/

g++ -o ./build/test.o -c ./test/src/$1 -I./test/include/ -I./solution/include/ -I./gtest/include/

g++ -o ./build/main.o -c ./gtest/main/main.cpp -I./gtest/include/

g++ -o ./build/a.out ./build/*.o -I./include -L./gtest/lib -lgtest -lpthread
