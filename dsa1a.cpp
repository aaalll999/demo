#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

struct Student {
    int id;
    char name[50];
    float cgpa;
};

void addStudent(Student*& students, int& size) {
    Student* temp = (Student*)realloc(students, (size + 1) * sizeof(Student));

    if (temp == NULL) {
        cout << "Memory allocation failed! Exiting program." << endl;
        free(students);
        exit(1);
    }
    students = temp;

    cout << "--- Adding New Student ---\n";
    cout << "Enter Student ID: ";
    cin >> students[size].id;

    cout << "Enter Student Name: ";
    cin.ignore();
    cin.getline(students[size].name, 50);

    cout << "Enter Student CGPA: ";
    cin >> students[size].cgpa;

    size++;
    cout << "Student added successfully.\n";
}

void displayStudent(const Student& s) {
    cout << "ID: " << s.id << ", Name: " << s.name << ", CGPA: " << s.cgpa << endl;
}

void linearSearch(Student* students, int size, int searchID) {
    cout << "\n--- Searching for ID " << searchID << " (Linear Search) ---\n";
    for (int i = 0; i < size; i++) {
        if (students[i].id == searchID) {
            cout << "Student Found: ";
            displayStudent(students[i]);
            return;
        }
    }
    cout << "Student not found.\n";
}

int compareByID(const void* a, const void* b) {
    const Student* s1 = (const Student*)a;
    const Student* s2 = (const Student*)b;
    return s1->id - s2->id;
}

void binarySearch(Student* students, int size, int searchID) {
    if (size == 0) {
        cout << "Database is empty. Cannot search.\n";
        return;
    }

    qsort(students, size, sizeof(Student), compareByID);

    cout << "\n--- Searching for ID " << searchID << " (Binary Search) ---\n";

    int low = 0, high = size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (students[mid].id == searchID) {
            cout << "Student Found: ";
            displayStudent(students[mid]);
            return;
        } else if (students[mid].id < searchID) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    Student* students = NULL;
    int size = 0;
    int choice, id;

    do {
        cout << "\n================================\n";
        cout << "--- Student Database Menu ---\n";
        cout << "1. Add Student\n2. Linear Search by ID\n3. Binary Search by ID\n4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Clearing input and exiting." << endl;
            break;
        }

        switch (choice) {
            case 1:
                addStudent(students, size);
                break;
            case 2:
                if (size == 0) {
                    cout << "The database is empty. Add students first.\n";
                    break;
                }
                cout << "Enter ID to search (Linear): ";
                cin >> id;
                linearSearch(students, size, id);
                break;
            case 3:
                if (size == 0) {
                    cout << "The database is empty. Add students first.\n";
                    break;
                }
                cout << "Enter ID to search (Binary): ";
                cin >> id;
                binarySearch(students, size, id);
                break;
            case 4:
                cout << "Exiting program and freeing memory..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again (1-4)." << endl;
        }
    } while (choice != 4);

    free(students);
    students = NULL;

    return 0;
}
