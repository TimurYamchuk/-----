#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    // Вставка элемента в заданную позицию
    void insert(int value, int position) {
        Node* newNode = new Node(value);

        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        for (int i = 0; current != nullptr && i < position - 1; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Позиция вставки превышает длину списка." << endl;
            delete newNode;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    // Поиск заданного элемента
    int search(int value) {
        Node* current = head;
        int position = 0;

        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }

        // Элемент не найден
        return -1;
    }
};

int main() {
    LinkedList list;
    list.insert(1, 0); // Вставка элемента 1 в начало
    list.insert(2, 1); // Вставка элемента 2 в позицию 1
    list.insert(3, 0); // Вставка элемента 3 в начало
    list.insert(4, 2); // Вставка элемента 4 в позицию 2

    // Поиск элемента 2
    int position = list.search(2);
    if (position != -1) {
        cout << "Элемент 2 найден на позиции " << position << endl;
    } else {
        cout << "Элемент 2 не найден." << endl;
    }

    // Поиск элемента 5 (не существует)
    position = list.search(5);
    if (position != -1) {
        cout << "Элемент 5 найден на позиции " << position << endl;
    } else {
        cout << "Элемент 5 не найден." << endl;
    }

    return 0;
}
