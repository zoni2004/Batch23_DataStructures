#include <iostream>
using namespace std;

int dfs(char arr[][5], int n, int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n || arr[x][y] == 'W') {
        return 0;
    }
  
    arr[x][y] = 'W'; 
    
    int count = 1; 
    count += dfs(arr, n, x + 1, y); 
    count += dfs(arr, n, x - 1, y); 
    count += dfs(arr, n, x, y + 1); 
    count += dfs(arr, n, x, y - 1); 
    
    return count; 
}


int largestForestSize(char arr[][5], int n) {
    int largestSize = 0; 
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 'T') { 
                int currentSize = dfs(arr, n, i, j);
                if (currentSize > largestSize) {
                    largestSize = currentSize;
                }
            }
        }
    }
    
    return largestSize;
}

int main() {
    char arr[5][5] = {
        {'T', 'T', 'T', 'W', 'W'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'W', 'T', 'T'},
        {'T', 'W', 'T', 'T', 'T'},
        {'W', 'W', 'T', 'T', 'T'}
    };

    cout << "Size of the largest forest: " << largestForestSize(arr, 5);

    return 0;
}
