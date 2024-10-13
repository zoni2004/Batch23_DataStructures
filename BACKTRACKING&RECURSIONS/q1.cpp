#include <iostream>
using namespace std;

string findPaths(int arr[][4], int n, int x, int y, string path){
    if(x == n-1 && y == n-1){
        cout << path << " ";
        return path;
    }
    else{
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0, -1}};
        if(arr[x][y] == 0 || x>n-1 || y>n-1 || x<0 || y<0){
            return path;
        }
        else{
            arr[x][y] = 0;
            findPaths(arr, n, x + 1, y, path + "D");
            findPaths(arr, n, x - 1, y, path + "U");
            findPaths(arr, n, x, y + 1, path + "R");
            findPaths(arr, n, x, y - 1, path + "L");
            arr[x][y]= 1;
        }
    }
return path;
}

void ratInMaze(int arr[][4], int n) {
    if (arr[0][0] == 0 || arr[n-1][n-1] == 0) {
        return;
    }
    findPaths(arr, n, 0, 0, "");
}

int main(){
    int matrix[][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 1, 1, 1}
    };
    
    ratInMaze(matrix, 4);

    return 0;
}
