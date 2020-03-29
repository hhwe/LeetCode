g++ -g -o ./build/solution.o -c ./solution/src/$1  -I./solution/include/

g++ -g -o ./build/test.o -c ./test/src/$1 -I./test/include/ -I./solution/include/ -I./gtest/include/

g++ -g -o ./build/main.o -c ./gtest/main/main.cpp -I./gtest/include/

g++ -g -o ./build/a.out ./build/*.o -I./include -L./gtest/lib -lgtest -lpthread
