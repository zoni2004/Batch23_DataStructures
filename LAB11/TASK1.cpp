#include <iostream>

using namespace std;

class HashTable {
private:
    static const int SIZE = 10;
    struct Node {
        int book_id;
        Node* next;
    };
    Node* table[SIZE];

    int hashFunction(int book_id) {
        return (book_id / 10) % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(int book_id) {
        int index = hashFunction(book_id);
        Node* new_node = new Node;
        new_node->book_id = book_id;
        new_node->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = new_node;
        } else {
            Node* temp = table[index];
            while (temp != nullptr) {
                if (temp->book_id == book_id) {
                    delete new_node;
                    return;
                }
                temp = temp->next;
            }
            new_node->next = table[index];
            table[index] = new_node;
        }
    }

    string search(int book_id) {
        int index = hashFunction(book_id);
        Node* temp = table[index];
        while (temp != nullptr) {
            if (temp->book_id == book_id) {
                return "Book " + to_string(book_id) + " found at index " + to_string(index);
            }
            temp = temp->next;
        }
        return "Book " + to_string(book_id) + " not found";
    }

    string deleteBook(int book_id) {
        int index = hashFunction(book_id);
        Node* temp = table[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->book_id == book_id) {
                if (prev == nullptr) {
                    table[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return "Book " + to_string(book_id) + " deleted";
            }
            prev = temp;
            temp = temp->next;
        }
        return "Book " + to_string(book_id) + " not found";
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* temp = table[i];
            while (temp != nullptr) {
                cout << temp->book_id << " ";
                temp = temp->next;
            }
            cout << endl;
        }
    }
};

int main() {
    HashTable catalog;

    catalog.insert(101);
    catalog.insert(102);
    catalog.insert(103);
    catalog.insert(201);
    catalog.insert(202);
    catalog.insert(301);
    catalog.insert(302);
    catalog.insert(303);
    catalog.insert(304);

    catalog.display();

    cout << catalog.search(101) << endl;
    cout << catalog.search(202) << endl;
    cout << catalog.search(999) << endl;

    cout << catalog.deleteBook(101) << endl;
    cout << catalog.deleteBook(202) << endl;

    catalog.display();

    return 0;
}

