#include <iostream>
using namespace std;

const int MIN_NR = 10, MAX_NR = 99;
const int MIN_LS = 5, MAX_LS = 20;

const string names[] = {"Billy", "Nanny", "Dolly", "Ginger", "Nibbles",
                         "Poppy", "Daisy", "Biscuit", "Chester", "Coco",
                         "Gizmo", "Smokey", "Whiskey", "Lucky", "Shadow"};

const string colors[] = {"Brown", "Black", "White", "Spotted", "Golden",
                          "Grey", "Tan", "Cream", "Sable", "Red",
                          "Blue", "Mauve", "Yellow", "Peach", "Coral"};

class Goat {
private:
    int age;
    string name;
    string color;

public:
    Goat() {
        age = rand() % 20 + 1; 
        name = names[rand() % 15]; 
        color = colors[rand() % 15]; 
    }

    Goat(int a, string n, string c) : age(a), name(n), color(c) {}

    void display() const {
        cout << name << " (" << color << ", " << age << ")";
    }
};

class DoublyLinkedList {
private:
    struct Node {
        Goat data;
        Node* prev;
        Node* next;
        Node(const Goat& val, Node* p = nullptr, Node* n = nullptr)
            : data(val), prev(p), next(n) {}
    };
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    void push_back(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    void push_front(const Goat& goat) {
        Node* newNode = new Node(goat);
        if (!head) { 
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    void print() const {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = head;
        while (current) {
            current->data.display();
            cout << endl;
            current = current->next;
        }
    }

    void print_reverse() const {
        if (!tail) {
            cout << "List is empty" << endl;
            return;
        }
        Node* current = tail;
        while (current) {
            current->data.display();
            cout << endl;
            current = current->prev;
        }
    }

    ~DoublyLinkedList() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0))); 

    DoublyLinkedList list;
    int size = rand() % (MAX_LS - MIN_LS + 1) + MIN_LS; 

    for (int i = 0; i < size; ++i) {
        Goat newGoat; 
        list.push_back(newGoat); 
    }

    cout << "Forward:" << endl;
    list.print();

    cout << "Backward:" << endl;
    list.print_reverse();

    return 0;
}
