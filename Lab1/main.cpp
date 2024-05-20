#include<iostream>
#include "LinkedList.h"
using namespace std;

int main ()
{
   
    LinkedList L;
    L.addToTail(7);
    L.addToHead(5);
    L.addToHead(6);
    L.addToTail(4);
    L.addToHead(2);
    L.addToTail(1);
    L.addToHead(9);
    L.remove(6);
    L.removeFromHead();
    L.removeFromTail();
    L.traverse();
    Node*outptr;
    return 0;

}