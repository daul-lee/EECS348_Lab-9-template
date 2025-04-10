CC := g++

Matrix.exe: matrix.cpp main.cpp
	$(CC) $^ -o $@