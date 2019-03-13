#include<stdio.h>
#include<iostream>
#include<math.h>
#include "stack.h"
#include "disc.h"
using namespace std;

void printTower(Stack* t1, Stack* t2, Stack* t3){
    cout<<endl;
    cout<<"----------------------------Towers of Hanoi----------------------------"<<endl;
    cout<<"Stack 1: ";
    t1->display();
    cout<<"Stack 2: ";
    t2->display();
    cout<<"Stack 3: ";
    t3->display();
    
    
}

void solver(int n,Stack* Beg, Stack* Final, Stack* Aux){
    if(!(Beg->empty())){
    if(n==1){
            Final->push(Beg->pop());
            return;
        }
        solver(n-1,Beg,Aux,Final);
        Final->push(Beg->pop());
        solver(n-1,Aux,Final,Beg);
    }
    }


void toh(int n)
{
    int i, x;
    Disc* a;
    Disc* b;
    Stack* t1 = new Stack();
    Stack* t2 = new Stack();
    Stack* t3 = new Stack();

    for (i = n; i >= 1; i--)
    {
        Disc* d = new Disc(i);
        cout << d->toString();
        t1->push(d);
    }
    printTower(t1,t2,t3);
    solver(n,t1,t2,t3);
    printTower(t1,t2,t3);
}

int main()
{
    int n;
    cout<<"Enter the number of disks: ";
    cin>>n;
    toh(n);
    return 0;
}
