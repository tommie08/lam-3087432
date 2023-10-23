#include <iostream>
#include <fstream>
#include <iomanip>

const int MAX = 100;

// Function to read matrix data from a file and store it in a 2D array.
void readFileMatrices(int matrix1[MAX][MAX], int matrix2[MAX][MAX], int &size, const std::string & filename) {
    std::ifstream MyFile(filename);
    if (!MyFile) {
        std::cerr << "Error opening file: " << filename << std::endl;
        exit(1);
    }

    MyFile >> size; // Reading the first character.

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
    MyFile.close();
}

// Function to display a matrix.
void printMatrix(const int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cout << std::setw(3) << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to add two matrices and store the result in a third matrix.
void addMatrices(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function for matrix multiplication and store the result in a third matrix.
void multiplyMatrices(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = 0;
            for (int k = 0; k < size; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

// Function to subtract one matrix from another and store the result in a third matrix.
void subtractMatrices(const int matrix1[MAX][MAX], const int matrix2[MAX][MAX], int result[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

int main() {
    int matrix1[MAX][MAX];
    int matrix2[MAX][MAX];
    int matrixSum[MAX][MAX];
    int matrixProduct[MAX][MAX];
    int matrixDifference[MAX][MAX];
    int size;

    // Read matrices from the file
    readFileMatrices(matrix1, matrix2, size, "matrix_input.txt");

    // Display matrices
    std::cout << "Tommy Lam" << std::endl;
    std::cout << "Lab #6: Matrix manipulation" << std::endl;

    std::cout << "Matrix A:" << std::endl;
    printMatrix(matrix1, size);

    std::cout << "Matrix B:" << std::endl;
    printMatrix(matrix2, size);

    // Add matrices
    addMatrices(matrix1, matrix2, matrixSum, size);
    std::cout << "Matrix Sum (A + B):" << std::endl;
    printMatrix(matrixSum, size);

    // Multiply matrices
    multiplyMatrices(matrix1, matrix2, matrixProduct, size);
    std::cout << "Matrix Product (A * B):" << std::endl;
    printMatrix(matrixProduct, size);

    // Subtract matrices
    subtractMatrices(matrix1, matrix2, matrixDifference, size);
    std::cout << "Matrix Difference (A - B):" << std::endl;
    printMatrix(matrixDifference, size);

    return 0;
}