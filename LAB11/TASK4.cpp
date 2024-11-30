#include <iostream>

using namespace std;

class HashTable {
private:
    int* table;
    bool* occupied;
    int size;

    int primary_hash(int account_id) {
        return account_id % size;
    }

    int secondary_hash(int account_id) {
        return 7 - (account_id % 7);
    }

public:
    HashTable(int table_size) : size(table_size) {
        table = new int[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int account_id) {
        int index = primary_hash(account_id);
        int step = secondary_hash(account_id);

        int original_index = index;
        while (occupied[index]) {
            if (table[index] == account_id) {
                return;
            }
            index = (index + step) % size;
            if (index == original_index) {
                return;
            }
        }

        table[index] = account_id;
        occupied[index] = true;
    }

    string search(int account_id) {
        int index = primary_hash(account_id);
        int step = secondary_hash(account_id);

        int original_index = index;
        while (occupied[index]) {
            if (table[index] == account_id) {
                return "Account " + to_string(account_id) + " found at index " + to_string(index);
            }
            index = (index + step) % size;
            if (index == original_index) {
                break;
            }
        }

        return "Account " + to_string(account_id) + " not found";
    }

    string deleteAccount(int account_id) {
        int index = primary_hash(account_id);
        int step = secondary_hash(account_id);

        int original_index = index;
        while (occupied[index]) {
            if (table[index] == account_id) {
                table[index] = -1;
                occupied[index] = false;
                return "Account " + to_string(account_id) + " deleted";
            }
            index = (index + step) % size;
            if (index == original_index) {
                break;
            }
        }

        return "Account " + to_string(account_id) + " not found";
    }

    void display() {
        cout << "Hash Table (size " << size << "):" << endl;
        for (int i = 0; i < size; i++) {
            if (occupied[i]) {
                cout << "Index " << i << ": " << table[i] << endl;
            } else {
                cout << "Index " << i << ": Empty" << endl;
            }
        }
    }
};

int main() {
    HashTable bank(11);

    bank.insert(101);
    bank.insert(111);
    bank.insert(121);
    bank.insert(131);
    bank.insert(141);
    bank.insert(151);

    bank.display();

    cout << bank.search(111) << endl;
    cout << bank.search(141) << endl;
    cout << bank.search(161) << endl;

    cout << bank.deleteAccount(111) << endl;
    cout << bank.deleteAccount(131) << endl;

    bank.insert(161);
    bank.insert(171);

    bank.display();

    return 0;
}
