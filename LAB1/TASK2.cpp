#include <iostream>
#include <cstring> // For strlen and strcpy
class Exam {
private:
char* studentName;
char* examDate;
int score;
public:
// Constructor
Exam(const char* name, const char* date, int scoreValue) {
studentName = new char[strlen(name) + 1];
strcpy(studentName, name);
examDate = new char[strlen(date) + 1];
strcpy(examDate, date);
score = scoreValue;
}
// Destructor
~Exam() {
delete[] studentName;
delete[] examDate;
}
// Method to set attributes
void setAttributes(const char* name, const char* date, int scoreValue) {
delete[] studentName;
delete[] examDate;
studentName = new char[strlen(name) + 1];
strcpy(studentName, name);
examDate = new char[strlen(date) + 1];
strcpy(examDate, date);
score = scoreValue;
}
// Method to display exam details

void displayDetails() const {
std::cout << "Student Name: " << studentName << std::endl;
std::cout << "Exam Date: " << examDate << std::endl;
std::cout << "Score: " << score << std::endl;
}
};
// Function to demonstrate shallow copy issue
void demonstrateShallowCopy() {
Exam original("John Doe", "2024-08-20", 95);
Exam copy = original; // This will perform a shallow copy
std::cout << "Original Exam Details:" << std::endl;
original.displayDetails();
std::cout << "Copied Exam Details:" << std::endl;
copy.displayDetails();
// Modifying the original object
original.setAttributes("Jane Doe", "2024-08-21", 85);
std::cout << "Modified Original Exam Details:" << std::endl;
original.displayDetails();
std::cout << "Copied Exam Details after Original is Modified:" << std::endl;
copy.displayDetails();
}
int main() {
demonstrateShallowCopy();
return 0;
}
