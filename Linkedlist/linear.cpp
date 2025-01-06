#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
private:
    Node *first;
    Node *last;

public:
    LinkedList()
    {
        this->first = nullptr;
        this->last = nullptr;
    };

    void insert_last(int data);
    void display();
};

void LinkedList::insert_last(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if(this->first == nullptr)
    {
        this->first = newNode;
        this->last = newNode;
    } else {
        last->next = newNode;
        newNode->prev = last;
        last = newNode;
    }
};

void LinkedList::display()
{
    Node *temp = this->first;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
};
int main()
{
    LinkedList l;
    l.insert_last(10);
    l.insert_last(20);
    l.insert_last(30);

    l.display();

    return 0;
}