#include <iostream>

using namespace std;

class HashTable {
private:
    static const int SIZE = 7;
    int table[SIZE];
    bool occupied[SIZE];

    int hashFunction(int member_id) {
        return member_id % SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int member_id) {
        int index = hashFunction(member_id);
        int original_index = index;
        
        while (occupied[index]) {
            if (table[index] == member_id) {
                return;
            }
            index = (index + 1) % SIZE;
            if (index == original_index) {
                cout << "Hash Table is full, cannot insert member " << member_id << endl;
                return;
            }
        }

        table[index] = member_id;
        occupied[index] = true;
    }

    string search(int member_id) {
        int index = hashFunction(member_id);
        int original_index = index;

        while (occupied[index]) {
            if (table[index] == member_id) {
                return "Member ID " + to_string(member_id) + " found at index " + to_string(index);
            }
            index = (index + 1) % SIZE;
            if (index == original_index) {
                break;
            }
        }
        return "Member ID " + to_string(member_id) + " not found";
    }

    string deleteMember(int member_id) {
        int index = hashFunction(member_id);
        int original_index = index;

        while (occupied[index]) {
            if (table[index] == member_id) {
                table[index] = -1;
                occupied[index] = false;
                return "Member ID " + to_string(member_id) + " deleted";
            }
            index = (index + 1) % SIZE;
            if (index == original_index) {
                break;
            }
        }
        return "Member ID " + to_string(member_id) + " not found";
    }

    void display() {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < SIZE; i++) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    HashTable club;

    club.insert(10);
    club.insert(20);
    club.insert(30);
    club.insert(40);
    club.insert(50);
    club.insert(60);

    club.display();

    cout << club.search(30) << endl;
    cout << club.search(50) << endl;
    cout << club.search(70) << endl;

    cout << club.deleteMember(20) << endl;
    cout << club.deleteMember(40) << endl;

    club.insert(70);
    club.insert(80);

    club.display();

    return 0;
}
