#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

Stack::Stack()
{
    pTop = NULL;
}

void Stack::push(void* inData)
{
    Node* newnode = (Node*) malloc(sizeof(Node));
    newnode->data = inData;
    if(pTop == NULL){
        pTop = newnode;
        newnode->pNext = NULL;
    }
    else{
        Node* previous = pTop;
        newnode->pNext = previous;
        pTop = newnode;
    }
}
void* Stack::pop()
{
    Node* temp = new Node;
    temp = pTop;
    void* data = temp->data;
    pTop = temp->pNext;
    delete temp;
    return data;
}

void* Stack::top()
{
    return pTop;
}

bool Stack::empty()
{
    if(pTop == NULL){
        return true;
    }
    return false;
}


void Stack::display()
{
    Node *p1;
    p1 = pTop;
    while (p1 != NULL)
    {
        cout<< ((Disc*)(p1->data))->toString()<<"\t";
        p1 = p1->pNext;
    }
    cout<<endl;
}
