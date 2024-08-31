#include <iostream>
using namespace std;

void multiplyMatrices(const int A[][10], const int B[][10], int C[][10], int m, int n, int p) {
    // Initialize matrix C with zeros
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }

    // Perform matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    // Define matrices A and B
    const int m = 2, n = 3, p = 2;
    int A[m][10] = { {1, 2, 3}, {4, 5, 6} };
    int B[n][10] = { {7, 8}, {9, 10}, {11, 12} };
    int C[m][10]; // Result matrix

    // Multiply matrices A and B
    multiplyMatrices(A, B, C, m, n, p);

    // Print the result matrix C
    std::cout << "Resultant matrix C:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            std::cout << C[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
