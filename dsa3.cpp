#include <iostream>
using namespace std;
#define SIZE 5
class CircularQueue {
int arr[SIZE];
int front, rear;
public:
CircularQueue() {
front = -1;
rear = -1;
}
bool isFull() {
return ((front == 0 && rear == SIZE - 1) || (rear + 1 == front));
}
bool isEmpty() {
return (front == -1);
}
void enqueue(int value) {
if (isFull()) {
cout << "Queue is FULL! Cannot insert " << value << endl;
return;
}
if (front == -1)
front = 0;
rear = (rear + 1) % SIZE;
arr[rear] = value;
cout << "Inserted: " << value << endl;
}
void dequeue() {
if (isEmpty()) {
cout << "Queue is EMPTY! Cannot delete." << endl;
return;
}
cout << "Deleted: " << arr[front] << endl;
if (front == rear) {
front = -1;
rear = -1;
} else {
front = (front + 1) % SIZE;
}
}
void display() {
if (isEmpty()) {
cout << "Queue is EMPTY!" << endl;
return;
}
cout << "Queue elements: ";
int i = front;
while (true) {
cout << arr[i] << " ";
if (i == rear)
break;
i = (i + 1) % SIZE;
}
cout << endl;
}
};
int main() {
CircularQueue q;
int choice, value;
do {
cout << "\n--- Circular Queue Menu ---\n";
cout << "1. Enqueue (Insert)\n";
cout << "2. Dequeue (Delete)\n";
cout << "3. Display\n";
cout << "4. Exit\n";
cout << "Enter choice: ";
cin >> choice;
switch (choice) {
case 1:
cout << "Enter value to insert: ";
cin >> value;
q.enqueue(value);
break;
case 2:
q.dequeue();
break;
case 3:
q.display();
break;
case 4:
cout << "Exiting program..." << endl;
break;
default:
cout << "Invalid choice! Try again." << endl;
}
} while (choice != 4);
return 0;
}
