// Online C++ compiler to run C++ program online
#include <iostream>
#include <string>

using namespace std;

void commonFrnds(bool matrix[5][5]){
     for(int i=0; i<5; i++){
        for(int k=i+1; k<5; k++){
            for(int j=0; j<5; j++){
                 if((matrix[i][j] == true) && (matrix[i][j] == matrix[k][j])){
                cout<<"\n"<<i<<" and "<<k<<" have a common friend "<< j;
            }
            }
        }
    }
}
int main() {
    bool arr[5][5]= {
        {false, true, false, true, true}, 
        {true, false, true, false, true}, 
        {false, true, false, false, false}, 
        {true, false, false, false, true}, 
        {true, true, false, true, false}  
    };

    cout<<"{\n";
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            if(arr[i][j] == true){
                cout<<"*\t";
            }
            else{
                cout<<" \t";
            }
        }
    cout<<"\n";
    }
    cout<<"}";
    
    commonFrnds(arr);
    
    return 0;
}
