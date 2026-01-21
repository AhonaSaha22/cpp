#include <iostream>
#include <stack>
using namespace std;

struct Student {
    int id;
    string name;
    float cgpa;
};

Student s[100];
int n = 0;
stack<Student> undoStack;

void addStudent() {
    cout << "Enter ID: ";
    cin >> s[n].id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s[n].name);
    cout << "Enter CGPA: ";
    cin >> s[n].cgpa;
    n++;
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (n == 0) {
        cout << "No students found!\n";
        return;
    }
    cout << "\nID\tName\tCGPA\n";
    for (int i = 0; i < n; i++) {
        cout << s[i].id << "\t"
             << s[i].name << "\t"
             << s[i].cgpa << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            cout << "Found: " << s[i].name
                 << " | CGPA: " << s[i].cgpa << endl;
            return;
        }
    }
    cout << "Student not found!\n";
}

void deleteStudent() {
    int id, pos = -1;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < n; i++) {
        if (s[i].id == id) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
        cout << "Student not found!\n";
        return;
    }

    undoStack.push(s[pos]);

    for (int i = pos; i < n - 1; i++) {
        s[i] = s[i + 1];
    }
    n--;

    cout << "Student deleted (Undo available).\n";
}

void undoDelete() {
    if (undoStack.empty()) {
        cout << "Nothing to undo!\n";
        return;
    }

    s[n] = undoStack.top();
    undoStack.pop();
    n++;

    cout << "Undo successful!\n";
}

void sortByCGPA() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i].cgpa < s[j].cgpa) {
                swap(s[i], s[j]);
            }
        }
    }
    cout<< "Sorted by CGPA (Descending).\n";
}
int main() {
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << " 1. Add Student\n"  ;
        cout << " 2. Display Students\n"  ;
        cout << "3. Search Student\n" ;
        cout << "4. Delete Student\n";
        cout << "5. Undo Delete\n";
        cout << "6. Sort by CGPA\n"  ;
        cout << "0. Exit\n";
        cout << "Enter choice: " ;
        cin >> choice;

        switch (choice) {
            case 1:
                 addStudent();
                  break;
            case 2:
                 displayStudents();
                 break;
            case 3:
                 searchStudent();
                 break;
            case 4:
                deleteStudent();
                 break;
            case 5:
                 undoDelete();
                  break;
            case 6:
                sortByCGPA();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default: cout << "Invalid choice!\n";
        }

    }
     while (choice!=0);

    return 0;
}
