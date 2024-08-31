#include <iostream>
using namespace std;
class BankAccount{
int balance;
public:
//default constructor
BankAccount(){
cout<<"\nDefault constructor called";
balance = 3000;
}
//parametrized constructor
BankAccount(int balance){
cout<<"\nParametrized constructor called";
this -> balance = balance;
}
//copy constructor
BankAccount (const BankAccount& other){
cout<<"\nCopy constructor called";
balance = other.balance;
}
//overloading = operator for copying whole class onto another
BankAccount& operator = (const BankAccount & other){
if (this != &other){
balance = other.balance;
}
return *this;
}
//deducting 200 from balance
int deduct(){
balance = balance - 200;

return balance;
}
//printing
void print(){
cout<<"\nThe balance is: "<<balance;
}
};
int main() {
BankAccount account1;
account1.print();
cout<<"\nBefore copying account 2 onto account 3";
BankAccount account2(1000);
cout<<"\nAccount 2:";
account2.print();
cout<<"\nAccount 3:";
BankAccount account3;
account3 = account2; //copied using overloading assignment operator
account3.print();
cout<<"\nAfter copying acount 2 onto account 3";
cout<<"\nAccount 2:";
account2.print();
cout<<"\nAccount 3:";
account3.print();
account3.deduct();
cout<<"\nAfter deducting 200 from account 3";
cout<<"\nAccount 2:";
account2.print();
cout<<"\nAccount 3:";
account3.print();
return 0;
}
