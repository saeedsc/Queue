/*********************
Name: Saeid Jalaliani
Challenge 2 COSC 2436
Purpose: FIFO Stack (QUEUE)
**********************/

#ifndef FIFO_H
#define FIFO_H

#include<iostream>
#include<string>
using std::string;

struct Data {
    int id;
    string data;
};


class FIFO{
    
    public:
        FIFO();
        ~FIFO();
        
        bool push(int, string*);
        bool pull(Data*);
        bool peek(Data*);
        bool isEmpty();
    
    private:

        struct Node {
               Data data;
               Node *next;
        };
        
    Node* head;
    Node* tail;

};
#endif