#include <iostream>
using namespace std;

class Stack{
    private:
        int *arr;
        int top;
        int size;

    public:
        Stack(int s){
            size = s;
            arr = new int[size];
            top = -1;
        }

        void push(int value){
            if (top == size - 1){
                cout << "Stack is full" << endl;
            }else{
                arr[++top] = value;
                cout << value << " pushed" << endl;
            }
        }

        void pop(){
            if (top == -1){
                cout << "Stack is empty" << endl;
            }else{
                cout << arr[top--] << " popped" << endl;
            }
        }

        void displayTop(){
            if (top == -1){
                cout << "Stack is empty" << endl;
            }else{
                cout << "Top element: " << arr[top] << endl;
            }
        }

        void isEmpty(){
            if (top == -1){
                cout << "Stack is empty" << endl;
            }else{
                cout << "Stack is not empty" << endl;
            }
        }

        void isFull(){
            if (top == size - 1){
                cout << "Stack is full" << endl;
            }else{
                cout << "Stack is not full" << endl;
            }
        }

        void cleanUp(){
            delete[] arr;
        }
};

int main(){

    int size;
    cout << "Enter stack size :- ";
    cin >> size;

    Stack s(size);
    int choice, value;

    do{
        cout << endl << "-------- Stack menu --------" << endl;
        cout << "Press 1 for Push." << endl;
        cout << "Press 2 for Pop." << endl;
        cout << "Press 3 for Top." << endl;
        cout << "Press 4 for Empty." << endl;
        cout << "Press 5 for Full." << endl;
        cout << "Press 0 for Exit." << endl;

        cout << "Enter your choice :- ";
        cin >> choice;

        switch (choice){
        case 1:
            cout << "Enter value :- ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.displayTop();
            break;
        case 4:
            s.isEmpty();
            break;
        case 5:
            s.isFull();
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice " << endl;
        }
    } while (choice != 0);

    s.cleanUp();

    return 0;
}