#include <iostream>

using namespace std;

class HashTable {
private:
    int* table;
    bool* occupied;
    int size;
    int current_size;
    float load_factor_threshold;

    int hashFunction(int student_id) {
        return student_id % size;
    }

    void resize() {
        int new_size = size * 2;
        int* new_table = new int[new_size];
        bool* new_occupied = new bool[new_size];

        for (int i = 0; i < new_size; i++) {
            new_table[i] = -1;
            new_occupied[i] = false;
        }

        for (int i = 0; i < size; i++) {
            if (occupied[i]) {
                int new_index = hashFunction(table[i]) % new_size;
                while (new_occupied[new_index]) {
                    new_index = (new_index + 1) % new_size;
                }
                new_table[new_index] = table[i];
                new_occupied[new_index] = true;
            }
        }

        delete[] table;
        delete[] occupied;
        size = new_size;
        table = new_table;
        occupied = new_occupied;
    }

public:
    HashTable(int initial_size, float load_factor = 0.75) : size(initial_size), load_factor_threshold(load_factor), current_size(0) {
        table = new int[size];
        occupied = new bool[size];
        for (int i = 0; i < size; i++) {
            table[i] = -1;
            occupied[i] = false;
        }
    }

    void insert(int student_id) {
        if ((float)current_size / size >= load_factor_threshold) {
            resize();
        }

        int index = hashFunction(student_id);
        int original_index = index;

        while (occupied[index]) {
            if (table[index] == student_id) {
                return;
            }
            index = (index + 1) % size;
            if (index == original_index) {
                return;
            }
        }

        table[index] = student_id;
        occupied[index] = true;
        current_size++;
    }

    string search(int student_id) {
        int index = hashFunction(student_id);
        int original_index = index;

        while (occupied[index]) {
            if (table[index] == student_id) {
                return "Student ID " + to_string(student_id) + " found at index " + to_string(index);
            }
            index = (index + 1) % size;
            if (index == original_index) {
                break;
            }
        }

        return "Student ID " + to_string(student_id) + " not found";
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
    HashTable portal(7);

    portal.insert(12);
    portal.insert(22);
    portal.insert(32);
    portal.insert(42);
    portal.insert(52);
    portal.insert(62);

    portal.display();

    cout << portal.search(22) << endl;
    cout << portal.search(42) << endl;
    cout << portal.search(72) << endl;

    portal.insert(72);
    portal.insert(82);

    portal.display();

    return 0;
}
