#include <iostream>
#include <stdexcept>

class Node {
public:
    int value;
    Node* next;

    Node(int value) : value(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        clear();
    }

    void add_to_end(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void insert(int index, int value) {
        if (index < 0) {
            throw std::out_of_range("out of range");
        }
        Node* newNode = new Node(value);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!temp) throw std::out_of_range("out of range");
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void remove(int index) {
        if (index < 0 || !head) {
            throw std::out_of_range("out of range or list is empty");
        }

        if (index == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1; ++i) {
            if (!temp || !temp->next) throw std::out_of_range("out of range");
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    void replace(int index, int value) {
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            if (!temp) throw std::out_of_range("out of range");
            temp = temp->next;
        }
        temp->value = value;
    }

    int find_by_index(int index) {
        Node* temp = head;
        for (int i = 0; i < index; ++i) {
            if (!temp) throw std::out_of_range("out of range");
            temp = temp->next;
        }
        return temp->value;
    }

    void print() const {
        Node* temp = head;
        while (temp) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

class Stack : public LinkedList {
public:
    void push(int value) {
        insert(0, value);
    }

    void pop() {
        remove(0);
    }

    int top() {
        return find_by_index(0);
    }
};

class Queue : public LinkedList {
public:
    void enqueue(int value) {
        add_to_end(value);
    }

    void dequeue() {
        remove(0);
    }

    int front() {
        return find_by_index(0);
    }
};

int main() {
    LinkedList list;
    list.add_to_end(1);
    list.add_to_end(2);
    list.add_to_end(3);
    list.print();

    list.insert(1, 10);
    list.print();

    list.replace(1, 20);
    list.print();

    list.remove(1);
    list.print();

    std::cout << "Эл в индекс 1: " << list.find_by_index(1) << std::endl;

    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    std::cout << "Top: " << stack.top() << std::endl;
    stack.pop();
    std::cout << "" << stack.top() << std::endl;

    Queue queue;
    queue.enqueue(100);
    queue.enqueue(200);
    queue.enqueue(300);
    std::cout << "" << queue.front() << std::endl;
    queue.dequeue();
    std::cout << "" << queue.front() << std::endl;

    return 0;
}