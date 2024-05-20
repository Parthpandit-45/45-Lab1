#include <iostream>
#include "LinkedList.h"

Node::Node() : info(0), next(nullptr) {}
Node::Node(int inf)
{
    info=inf;
    next=nullptr;

}
LinkedList::LinkedList(){
Head=nullptr;
Tail=nullptr;
}

LinkedList::~LinkedList(){}

bool LinkedList::isEmpty()
{
    if(Head==NULL)
        return true;
    else    
        return false;

}
void LinkedList::addToHead(int data)
{
    
    Node *temp=new Node(data);
    temp->info=data;
    temp->next=Head;
    Head=temp;
    if (Tail==NULL)
        Tail=temp;


}
void LinkedList::addToTail(int data)
{
    Node *temp=new Node(data);
    if (Tail==NULL)
    {
        Head=temp;
        temp->info=data;
        temp->next=NULL;
        Tail=temp;

    }
    else   
        {
            temp->info=data;
            temp->next=NULL;
            Tail=temp;
        }
}
void LinkedList::add(int data , int pred)
{ Node* predecessor;
    retrieve(pred, predecessor);
    if (isEmpty())
        {
            addToHead(data);

        }
    else if (predecessor=Tail)
        {
            addToTail(data);

        }
    else 
        {
            Node *temp= new Node(data);
            temp->info=data;
            temp->next=predecessor->next;
            predecessor->next=temp;
        }
}
void LinkedList::traverse()
{
    Node *p=Head;
    std::cout<<"Linked list: "<<std::endl;
    while (p!=NULL)
        {
            std::cout<<p->info<<std::endl;

            p=p->next;

        }
}
void LinkedList::removeFromHead()
{
    if (!isEmpty())
    {
        Node *temp = Head;
        Head=temp->next;
        delete temp;
        if (Head==NULL)
            Tail=NULL;

    
    }
    else   
        std::cout<<"List is empty"<<std::endl;

}
void LinkedList::removeFromTail()

    {
        Node *temp=Tail;
        if (Head==Tail)
         {
            Head=NULL;
            Tail=NULL;
        }
        else
            {
                Node *predecessor=Head;
                while(predecessor->next!=Tail)
                    {
                        predecessor=predecessor->next;
                    }
                Tail=predecessor;
                predecessor->next=NULL;
            }
        delete temp;

    }

void LinkedList::remove(int data)
{
    if(!isEmpty())
        {
            if (Head->info==data)
                {
                    removeFromHead();
                }
            else if (Tail->info==data)
                {
                    removeFromTail();
                }
            else
            {
                Node *temp= Head->next;
                Node *predecessor= Head;
                while (predecessor->next!=NULL)
                    {
                        if(temp->info==data) 
                            break;
                        else    
                            {
                                    predecessor=predecessor->next;
                                    temp=temp->next;
                            }
                        if (temp!=NULL)
                            {
                                predecessor->next=temp->next;
                                delete temp;
                            }
                        else    
                            {
                                Tail=predecessor;
                                delete temp;

                            }
                    }
            }
        }
}

bool LinkedList::search(int data)
 {
    Node *temp=Head;

    if(isEmpty())
        {
            return false;

        }
    else    
        {
            while (temp->next!=NULL)
                {
                    if(temp->info==data)
                        return true;
                }
            return false;

        }
 }

bool LinkedList::retrieve(int data, Node *outputNodePointer)
    {
        Node *p=Head;
        while (p!=NULL && p->info!=data)
            {
                p=p->next;

            }
        if (p==NULL)
            return false;
        else
            {   outputNodePointer=p;
                return true;
            }
    }