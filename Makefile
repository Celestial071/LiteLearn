CC = clang++ -std=c++17
optimization = -O2

SOURCE = main.cpp tensor.cpp operation.cpp

all:
	$(CC) $(optimization) $(SOURCE) -o main
