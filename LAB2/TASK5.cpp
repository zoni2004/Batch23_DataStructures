#include <iostream>
using namespace std;

int main() {
    int rows;
    cout<<"\nEnter the number of rows: ";
    cin>>rows;
    
    string **arr = new string*[rows];
    int size[rows];
    for (int i = 0; i < rows; ++i) {
        cout<<"\nEnter the number of seats for each row: ";
        cin>>size[i];
        arr[i] = new string[size[i]];
        std::cout << "Enter the names for row " << i + 1 << ": " << std::endl;
        for (int j = 0; j < size[i]; ++j) {
            std::cout << "Seat " << j + 1 << ": ";
            std::cin >> arr[i][j];
        }
    }
    
  
     for (int i = 0; i < rows; ++i) {
        delete[] arr[i]; 
    }
    delete[] arr; 

    return 0;
}
