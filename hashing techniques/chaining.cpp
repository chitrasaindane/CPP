#include <iostream>
#include <list>
using namespace std;

class HashTable {
private:
    int TABLE_SIZE; // Size of hash table
    list<int>* table; // Array of linked lists

    int hashFunction(int key) {
        return key % TABLE_SIZE; // Simple modulo-based hash function
    }

public:
    HashTable(int size) {
        TABLE_SIZE = size;
        table = new list<int>[TABLE_SIZE];
    }

    ~HashTable() {
        delete[] table;
    }

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    void remove(int key) {
        int index = hashFunction(key);
        table[index].remove(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int value : table[index]) {
            if (value == key)
                return true;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Bucket " << i << ": ";
            for (int value : table[i]) {
                cout << value << " -> ";
            }
            cout << "NULL" << endl;
        }
    }
};

int main() {
    int size;
    cout << "Enter the size of the hash table: ";
    cin >> size;
    
    HashTable hashTable(size);
    hashTable.insert(15);
    hashTable.insert(25);
    hashTable.insert(35);
    hashTable.insert(10);
    hashTable.insert(20);
    hashTable.insert(12);
    hashTable.insert(18);
    hashTable.insert(88);
    hashTable.insert(164);
    
    cout << "Hash table after insertion:" << endl;
    hashTable.display();
    
    cout << "Searching for 25: " << (hashTable.search(25) ? "Found" : "Not Found") << endl;
    
    hashTable.remove(25);
    cout << "Hash table after deletion of 25:" << endl;
    hashTable.display();
    
    return 0;
}
