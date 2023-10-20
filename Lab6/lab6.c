#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomainp>

void readMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int &size, const std::string & filename);
void printMatrix(int result[MAX][MAX]);
void addMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX]);
void mutiplyMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX]);
void minusMatrix(int matrix1[MAX][MAX], int matrix2[MAX][MAX]);

int main() {
    int matrix1[MAX][MAX];
    int matrix2[MAX][MAX];
    int result[MAX][MAX];
    int size;

    read(matrix1, matrix2, size, "matrix_input.txt");
}

void read(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int &size, const std::string & filename) {
    std::ifstream MyFile(filename); // Function body
    if (!MyFile) {
        std::cerr << "Error opening file: " << filename << std::end1;
        exit(1);
    }

    MyFile >> size; // Reading the first character

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            MyFile >> matrix1[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            MyFile >> matrix2[i][j];
        }
    }
}    