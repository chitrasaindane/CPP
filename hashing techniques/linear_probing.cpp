#include <iostream>
using namespace std;

#define SIZE 10 // Size of hash table

class HashTable {
private:
    int table[SIZE];
public:
    HashTable() {
        for (int i = 0; i < SIZE; i++)
            table[i] = -1; // -1 indicates an empty slot
    }

    // Hash function
    int hashFunction(int key) {
        return key % SIZE;
    }

    // Insert function using Linear Probing
    void insert(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) { // Find the next available slot
            index = (index + 1) % SIZE;
            if (index == startIndex) {
                cout << "Hash Table is full!" << endl;
                return;
            }
        }
        table[index] = key;
    }

    // Search function using Linear Probing
    bool search(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key)
                return true;
            index = (index + 1) % SIZE;
            if (index == startIndex)
                return false;
        }
        return false;
    }

    // Display function 
    void display() {
        for (int i = 0; i < SIZE; i++)
            cout << i << ": " << table[i] << endl;
    }
};

int main() {
    HashTable ht;
    ht.insert(10);
    ht.insert(20);
    ht.insert(30);
    ht.insert(40);
    ht.insert(50);
    ht.insert(60);
    ht.insert(70);
    ht.insert(80);
    ht.insert(90);
    ht.insert(100);
    ht.display();
    cout << "Search 50: " << (ht.search(50) ? "Found" : "Not Found") << endl;
    cout << "Search 25: " << (ht.search(25) ? "Found" : "Not Found") << endl;
    
    return 0;
}
