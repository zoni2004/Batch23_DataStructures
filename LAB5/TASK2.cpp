#include <iostream>
using namespace std;

int TailFact(int n){
    if(n==0 || n==1){
        return 1;
    }
    else{
        return n*TailFact(n-1);
    }
}

int nonTailFact(int n){
    if(n>=1){
        return n*nonTailFact(n-1);
    }
    else{
        return 1;
    }
}

int main() {
    int num;
    cout<<"Enter the number you want the factorial for";
    cin>>num;
    cout << "The factorial using tail recursion is: " << TailFact(num) << endl;
    cout << "The factorial using non-tail recursion is: " << nonTailFact(num) << endl;

    return 0;
}
