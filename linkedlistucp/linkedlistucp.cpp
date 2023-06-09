#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    int rollNumber;
    string name;
    Node* next;
};

class CircularLinkedList {
private:
    Node* LAST;

public:
    CircularLinkedList() {
        LAST = NULL;
    }

    void addNode();
    bool search(int rollno, Node** previous, Node** current);
    bool listEmpty();
    bool delNode();
    void traverse();
};

void CircularLinkedList::addNode() {
    // Daftar awal
    Node* new_node = new Node();
    new_node->rollNumber = 3; // Ganti dengan nama blakang
    new_node->name = "selaamt datang"; // Ganti dengan nama depan

    if (LAST == NULL) {
        LAST = new_node;
        LAST->next = LAST;
        return;
    }

    //Antara dua node dalam daftar
    Node* Happy = LAST->next;
    Node* Putra = NULL;
    while (Happy->rollNumber < new_node->rollNumber && Putra != LAST) {
        Putra = Happy;
        Happy = Happy->next;
    }

   

    // Akhir dari daftar
    if (Happy == LAST) {
        LAST = new_node;
    }
}

bool CircularLinkedList::search(int rollno, Node** Putra, Node** current) {
    *Putra = LAST->next;
    *Happy = LAST->next;
    while (*Happy != LAST) {
        if (rollno == (*Happy)->rollNumber) {
            return true;
        }
        *previous = *Happyt;
        *Happy = (*Happy)->next;
    }
    if (rollno == LAST->rollNumber) {
        return true;
    }
    else {
        return false;
    }
}

bool CircularLinkedList::listEmpty() {
    return LAST == NULL;
}

bool CircularLinkedList::delNode() {
    if (listEmpty()) {
        cout << "List is empty" << endl;
        return false;
    }

    int rollno;
    cout << "Enter the roll number of the record to delete: ";
    cin >> rollno;

    Node* Putra, * Happy;
    if (search(rollno, &previous, &Happy)) {
        // aftar awal
        if (current == LAST->next) {
            if (LAST->next == LAST) {
                LAST = NULL;
                return true;
            }
            LAST->next = Happy->next;
            delete current;
            return true;
        }

        // daftar akhir
        if (current == LAST) {
            previous->next = LAST->next;
            LAST = previous;
            delete current;
            return true;
        }

        // Antara dua node dalam daftar
        Node* temp = LAST;
        while (temp->next != LAST) {
            temp = temp->next;
        }
        temp->next = current->next;
        delete current;
        return true;
    }
    else {
        cout << "Record not found" << endl;
        return false;
    }
}

void CircularLinkedList::traverse() {
    if (listEmpty()) {
        cout << "List is empty" << endl;
    }
    else {
        cout << "Records in the list are:" << endl;
        Node* currentNode = LAST->next;
        while (currentNode != LAST) {
            cout << currentNode->rollNumber << " " << currentNode->name << endl;
            currentNode = currentNode->next;
        }
        cout << LAST->rollNumber << " " << LAST->name << endl;
    }
}

int main() {
    CircularLinkedList obj;

    while (true) {
        try {
            cout << "\nMenu" << endl;
            cout << "1. Tambahkan catatan anda" << endl;
            cout << "2. Hapus dari daftar catatan" << endl;
            cout << "3. Lihat semua yang ada dalam daftar" << endl;
            cout << "4. Keluar" << endl;
            cout << "\nMasukkan pilihan anda (1-4): ";
            char ch;
            cin >> ch;

            switch (ch) {
            case '1': {
                obj.addNode();
                break;
            }
            case '2': {
                obj.delNode();
                break;
            }
            case '3': {
                obj.traverse();
                break;
            }
            case '4': {
                return 0;
            }
            default: {
                cout << "Invalid option" << endl;
                break;
            }
            }
        }
        catch (exception& e) {
            cout << e.what() << endl;
        }
    }

    return 0;
}
