#include <iostream>
#include <queue>
using namespace std;

struct Book {
    int id;
    string name ;
    bool issued ;
};

struct Node {
    Book data;
    Node* next ;
};

Node* head = NULL;
queue<int> waitQ ;

void addBook() {
    Book b;
    cout << "Enter Book ID: " ;
    cin >> b.id;
    cout << "Enter Book Name: " ;
    cin.ignore();
    getline(cin, b.name);
    b.issued = false ;

    Node* n = new Node ;
    n->data = b;
    n->next = head;
    head = n;

    cout << "Book added successfully!\n";
}

void displayBooks() {
    if (head == NULL) {
        cout << "No books available!\n"  ;
        return;
    }

    Node* temp = head;
    cout << "\nID\tName\t\tStatus\n" ;
    while (temp != NULL) {
        cout << temp->data.id << "\t"
             << temp->data.name << "\t"
             << (temp->data.issued ? "Issued" : "Available") << endl;
        temp = temp->next;
    }
}

Node* searchBook(int id) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data.id == id)
            return temp;
        temp = temp->next;
    }
    return NULL;
}

void issueBook() {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;

    Node* b = searchBook(id);
    if (b == NULL) {
        cout << "Book not found!\n";
        return;
    }

    if (b->data.issued) {
        cout << "Book already issued. Added to waiting queue.\n";
        waitQ.push(id);
    } else {
        b->data.issued = true;
        cout << "Book issued successfully!\n";
    }
}

void returnBook() {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;

    Node* b = searchBook(id);
    if (b == NULL || b->data.issued == false) {
        cout << "Invalid return!\n";
        return;
    }

    if (!waitQ.empty()) {
        int next = waitQ.front();
        waitQ.pop();
        cout << "Book issued to next request (ID: " << next << ")\n";
    } else {
        b->data.issued = false;
        cout << "Book returned successfully!\n";
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n Library Management System-\n";
        cout << "1. Add Book\n";
        cout << "2. Display the Books\n" ;
        cout << "3. Search Book\n" ;
        cout << "4. Issue Book\n"  ;
        cout << "5. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addBook();
        else if (choice == 2)
            displayBooks();
        else if (choice == 3) {
            int id;
            cout << "Enter Book ID: ";
            cin >> id;
            Node* b = searchBook(id);
            if (b)
                cout << "Found: "<< b->data.name << endl;
            else
                cout << "Book not found!\n";
        }
        else if (choice==4)
            issueBook();
        else if (choice==  5)
            returnBook();
        else if (choice== 0) {
            cout<<"Exit\n";
            break;
        }
        else
            cout<<"Invalid choice!\n";
    }

    return 0;
}
