#include <iostream>
#define MAX 15
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* hashTable[MAX];

void modHashing(int bil)
{
    int index = bil % MAX;
    Node* newNode = new Node;
    newNode->data = bil;
    newNode->next = nullptr;

    if (hashTable[index] == nullptr) {
        hashTable[index] = newNode;
        cout << "Data " << bil << " disimpan pada index ke " << index << endl;
    } else {
        Node* temp = hashTable[index];
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << "Data " << bil << " disimpan pada index ke " << index << " dengan chaining" << endl;
    }
}

void searchData(int bil)
{
    int index = bil % MAX;
    if (hashTable[index] != nullptr) {
        Node* temp = hashTable[index];
        while (temp != nullptr) {
            if (temp->data == bil) {
                cout << "Data " << bil << " ditemukan pada index ke " << index << endl;
                return;
            }
            temp = temp->next;
        }
    }
    cout << "Data " << bil << " tidak ditemukan" << endl;
}

void deleteData(int bil)
{
    int index = bil % MAX;
    if (hashTable[index] != nullptr) {
        Node* currNode = hashTable[index];
        Node* prevNode = nullptr;

        while (currNode != nullptr && currNode->data != bil) {
            prevNode = currNode;
            currNode = currNode->next;
        }

        if (currNode != nullptr) {
            if (prevNode == nullptr) {
                hashTable[index] = currNode->next;
            } else {
                prevNode->next = currNode->next;
            }
            delete currNode;
            cout << "Data " << bil << " dihapus dari index ke " << index << endl;
            return;
        }
    }
    cout << "Data " << bil << " tidak ditemukan" << endl;
}

void displayTable()
{
    cout << "Hash Table:" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "[" << i << "]: ";
        if (hashTable[i] != nullptr) {
            Node* temp = hashTable[i];
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int choice, data;
kembali:
    system("cls");
    cout << "Program Hash Table" << endl;
    cout << "1. Insert element into the table" << endl;
    cout << "2. Search element from the key" << endl;
    cout << "3. Delete element at a key" << endl;
    cout << "4. Exit" << endl;
    cout << "Masukkan pilihan Anda: ";
    cin >> choice;

    switch (choice) {
    case 1:
        cout << "Masukkan data yang ingin disimpan: ";
        cin >> data;
        modHashing(data);
        displayTable();
        cin.ignore();
        cin.get();
        goto kembali;
        break;
    case 2:
        cout << "Masukkan data yang ingin dicari: ";
        cin >> data;
        searchData(data);
        cout << endl;
        cin.ignore();
        cin.get();
        goto kembali;
        break;
    case 3:
        cout << "Masukkan data yang ingin dihapus: ";
        cin >> data;
        deleteData(data);
        displayTable();
        cin.ignore();
        cin.get();
        goto kembali;
        break;
    case 4:
        return 0;
    default:
        cout << "Pilihan tidak valid!" << endl;
        goto kembali;
    }
    return 0;
}
