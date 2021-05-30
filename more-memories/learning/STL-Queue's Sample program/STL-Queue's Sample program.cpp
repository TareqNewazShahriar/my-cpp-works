//////////////////////////////////////////////////////////////////////
//
// Compile options needed: none
//
// <filename> :  queue.cpp
//
// Functions:
//
//    queue::push(), queue::pop(), queue::empty(), queue::back(),
//    queue::front(),queue::size()
//
//////////////////////////////////////////////////////////////////////

/* Compile options needed:none
*/
#include <list>
#include <iostream>
#include <queue>
#include <deque>

using namespace std ;

// Using queue with list
typedef list<int > INTLIST;
typedef queue<int>  INTQUEUE;

// Using queue with deque
typedef deque<char*> CHARDEQUE;
typedef queue<char*> CHARQUEUE;

void main(void)
{
    int size_q;
    INTQUEUE q;
    CHARQUEUE p;

    // Insert items in the queue(uses list)
    q.push(42);
    q.push(100);
    q.push(49);
    q.push(201);

 
// Program Output is:


    // Output the size of queue
    size_q = q.size();
    cout << "size of q is:" << size_q << endl;

    // Output items in queue using front()
    // and use pop() to get to next item until
    // queue is empty
    while (!q.empty())
    {
        cout << q.front() << endl;
        q.pop();

    }

// Insert items in the queue(uses deque)
    p.push("cat");
    p.push("ape");
    p.push("dog");
    p.push("mouse");
    p.push("horse");

    // Output the item inserted last, using back()
    cout << p.back() << endl;

    // Output the size of queue
    size_q = p.size();
    cout << "size of p is:" << size_q << endl;

    // Output items in queue using front()
    // and use pop() to get to next item until
    // queue is empty
    while (!p.empty())
    {
        cout << p.front() << endl;
        p.pop();

    }
}
/*
Program Output:

201
size of q is:4
42
100
49
201
horse
size of p is:5
cat
ape
dog
mouse
horse
*/