#include <iostream>
using namespace std;


void printFibonacci(int n, int a = 0, int b = 1) {
    if (n < 0) return; 
    if (n == 0) {
        cout << a << " "; 
        return;
    }
    if (n == 1) {
        cout << a << " " << b << " "; 
        return;
    }
   
    cout << b << " "; 
    printFibonacci(n - 1, b, a + b); 
}

int main() {
    int N;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> N;

    cout << "Fibonacci numbers up to " << N << " are: " << endl;
    printFibonacci(N);

    return 0;
}
