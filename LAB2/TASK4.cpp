/*You are tasked with developing a program to manage and display the Grade Point Average (GPA) for the
core courses offered in the first semester of four departments: Software Engineering (SE), Artificial Intelligence
(AI), Computer Science (CS), and Data Science (DS). Each department offers a distinct number of core courses
for this semester: SE has 3 core courses, AI has 4 core courses, CS has 2 core courses, and DS has 1 core course.
To efficiently store and present this data, which type of array structure would you employ?

I would make use of jagged array for  aset number of rows and a different number of columns
*/
#include <iostream>
using namespace std;

int main(){
    int **coreCourses = new int*[4];
    int size[4];
    for(int i=0; i<4; i++){
        cout<<"\nEnter the number of columns of row "<<i+1<< " ";
        cin>>size[i];
        coreCourses[i] = new int[size[i]];
    }
    
    //taking user input
    for(int i=0; i<4; i++){
        for(int j=0; j<size[i]; j++){
            cout<<"\nEnter element for row "<<i+1<<" and column "<<j+1<<" ";
            cin>>coreCourses[i][j];
        }
    }
 
    //printing 
    cout<<"\nPrinting the GPA of core courses";
    cout<<"{\n";
    for(int i=0; i<4; i++){
        for(int j=0; j<size[i]; j++){
            cout<<coreCourses[i][j]<<"\t";
        }
    cout<<"\n";
    }
    cout<<"}\n";
    
return 0;
}
