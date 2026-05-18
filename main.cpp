#include <iostream>
#include <vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float marks;

    void input() {
        cout << "Enter Roll Number: ";
        cin >> roll;

        cout << "Enter Name: ";
        cin >> name;

        cout << "Enter Marks: ";
        cin >> marks;
    }

    void display() {
        cout << "\nRoll Number: " << roll;
        cout << "\nName: " << name;
        cout << "\nMarks: " << marks << endl;
    }
};

vector<Student> students;

void addStudent() {
    Student s;
    s.input();
    students.push_back(s);

    cout << "\nStudent Added Successfully!\n";
}

void viewStudents() {
    if (students.empty()) {
        cout << "\nNo Student Records Found!\n";
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        cout << "\nStudent " << i + 1 << endl;
        students[i].display();
    }
}

void searchStudent() {
    int roll;

    cout << "Enter Roll Number to Search: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll == roll) {
            cout << "\nStudent Found!\n";
            students[i].display();
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

void deleteStudent() {
    int roll;

    cout << "Enter Roll Number to Delete: ";
    cin >> roll;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].roll == roll) {
            students.erase(students.begin() + i);

            cout << "\nStudent Deleted Successfully!\n";
            return;
        }
    }

    cout << "\nStudent Not Found!\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== SCHOOL MANAGEMENT SYSTEM =====\n";

        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                addStudent();
                break;

            case 2:
                viewStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nExiting Program...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);

    return 0;
}
