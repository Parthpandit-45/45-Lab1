#pragma once
class Node 
    {
        public:
            Node();

            int info;
            Node *next;
            Node(int inf);
    };

class LinkedList: public Node
{
    private:
        Node *Head;
        Node *Tail;

    
public:
    LinkedList();
    ~LinkedList();
    bool isEmpty();
    void addToHead(int data);
    void addToTail(int data);
    void add(int data, int pred);
    void removeFromHead();
    void removeFromTail();
    void remove(int data);
    bool retrieve (int data, Node * outputNodepointer);
    bool search (int data);
    void traverse();

};
