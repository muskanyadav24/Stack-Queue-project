#include <iostream>
using namespace std;

class Queue {
private:
    int* arr;
    int front;
    int rear;
    int size;

public:
    Queue(int s) {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            if (front == -1) front = 0;
            arr[++rear] = value;
            cout << value << " enqueued" << endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << arr[front++] << " dequeued" << endl;
            if (front > rear) {
                front = -1;
                rear = -1;
            }
        }
    }

    void displayFront() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }

    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == size - 1;
    }

    void showEmpty() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
        } else {
            cout << "Queue is not empty" << endl;
        }
    }

    void showFull() {
        if (isFull()) {
            cout << "Queue is full" << endl;
        } else {
            cout << "Queue is not full" << endl;
        }
    }

    void cleanUp() {
        delete[] arr;
    }
};

int main() {
    int size;
    cout << "Enter queue size :- ";
    cin >> size;

    Queue q(size);
    int choice, value;

    do {
        cout << endl << "-------- Queue Menu --------" << endl;
        cout << "Press 1 for Enqueue." << endl;
        cout << "Press 2 for Dequeue." << endl;
        cout << "Press 3 for Front." << endl;
        cout << "Press 4 for Empty." << endl;
        cout << "Press 5 for Full." << endl;
        cout << "Press 0 for Exit." << endl;

        cout << "Enter your choice :- ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value :- ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.displayFront();
                break;
            case 4:
                q.showEmpty();
                break;
            case 5:
                q.showFull();
                break;
            case 0:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 0);

    q.cleanUp();
    return 0;
}
