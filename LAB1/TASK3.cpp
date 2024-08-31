#include <iostream>
#include <cstring> // For strcpy, strlen, and strcmp
using namespace std;
class Document {
char* content; // Pointer to dynamically allocated text content
public:
// Constructor
Document(const char* initialContent) {
if (initialContent) {
content = new char[strlen(initialContent) + 1];
strcpy(content, initialContent);
} else {
content = new char[1];
content[0] = '\0';
}
}
// Destructor
~Document() {
delete[] content;
}
// Copy Constructor (Deep Copy)
Document(const Document& other) {
content = new char[strlen(other.content) + 1];
strcpy(content, other.content);
}
// Copy Assignment Operator (Deep Copy)
Document& operator=(const Document& other) {
if (this != &other) { // Check for self-assignment
delete[] content; // Free existing resource
content = new char[strlen(other.content) + 1];
strcpy(content, other.content);
}
return *this;

}
// Method to set content
void setContent(const char* newContent) {
delete[] content; // Free existing resource
content = new char[strlen(newContent) + 1];
strcpy(content, newContent);
}
// Method to get content
const char* getContent() const {
return content;
}
// Method to display content
void display() const {
cout << "Document Content: " << content << endl;
}
};
// Sample program
int main() {
// Create an original document
Document doc1("This is the original document.");
cout << "Original Document:" << endl;
doc1.display();
// Create a copy using the copy constructor
Document doc2 = doc1;
cout << "\nCopied Document (Using Copy Constructor):" << endl;
doc2.display();
// Create another document and use the copy assignment operator
Document doc3("Temporary content.");
cout << "\nDocument before Copy Assignment:" << endl;
doc3.display();
doc3 = doc1; // Copy assignment
cout << "\nDocument after Copy Assignment:" << endl;
doc3.display();

// Modify the original document
doc1.setContent("This is the updated original document.");
cout << "\nOriginal Document after modification:" << endl;
doc1.display();
cout << "\nCopied Document (Using Copy Constructor) after Original modification:"
<< endl;
doc2.display();
cout << "\nDocument after Copy Assignment after Original modification:" << endl;
doc3.display();
return 0;
}
