#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <limits>

using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n = "") {
        name = n;
    }
};

class Student : public Person {
private:
    int id;
    double gpa;
    set<string> courses;

public:
    Student(int i, string n, double g) : Person(n) {
        id = i;
        gpa = g;
    }

    int getId() { return id; }
    string getName() { return name; }
    double getGpa() { return gpa; }

    void enrollCourse(string course) {
        courses.insert(course);
    }

    void showCourses() {
        if (courses.empty()) {
            cout << "No courses enrolled.\n";
            return;
        }
        for (string c : courses)
            cout << "- " << c << "\n";
    }

    void display() {
        cout << "ID: " << id << ", Name: " << name << ", GPA: " << gpa << "\n";
    }
};

vector<Student> students;

int findStudentIndexById(int id) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

bool idExists(int id) {
    return findStudentIndexById(id) != -1;
}

void addStudent() {
    int id;
    string name;
    double gpa;

    cout << "Enter ID: ";
    cin >> id;

    if (idExists(id)) {
        cout << "ID already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);

    cout << "Enter GPA: ";
    cin >> gpa;

    if (gpa < 0.0 || gpa > 4.0) {
        cout << "Invalid GPA!\n";
        return;
    }

    students.push_back(Student(id, name, gpa));
    cout << "Student added successfully.\n";
}

void removeStudent() {
    int id;
    cout << "Enter ID to remove: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    students.erase(students.begin() + index);
    cout << "Student removed.\n";
}

void searchStudent() {
    int id;
    cout << "Enter ID: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    students[index].display();
}

void displayAll() {
    if (students.empty()) {
        cout << "No students available.\n";
        return;
    }
    for (int i = 0; i < students.size(); i++)
        students[i].display();
}

void enrollCourse() {
    int id;
    string course;

    cout << "Enter Student ID: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    cout << "Enter Course Name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, course);
    students[index].enrollCourse(course);
    cout << "Course added.\n";
}

void showCourses() {
    int id;
    cout << "Enter Student ID: ";
    cin >> id;

    int index = findStudentIndexById(id);
    if (index == -1) {
        cout << "Student not found.\n";
        return;
    }

    students[index].showCourses();
}

bool compareByGpa(Student first, Student second) {
    return first.getGpa() > second.getGpa();
}

void sortByGPA() {
    sort(students.begin(), students.end(), compareByGpa);
    cout << "Students sorted by GPA.\n";
}

int main() {
    int choice = 0;

    while (true) {
        // Main menu
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Remove Student\n";
        cout << "3. Search Student\n";
        cout << "4. Display All Students\n";
        cout << "5. Enroll Student in Course\n";
        cout << "6. Show Student Courses\n";
        cout << "7. Sort Students by GPA\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: removeStudent(); break;
            case 3: searchStudent(); break;
            case 4: displayAll(); break;
            case 5: enrollCourse(); break;
            case 6: showCourses(); break;
            case 7: sortByGPA(); break;
            case 8:
                cout << "Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }

        // Pause so user can read output before returning to menu
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}