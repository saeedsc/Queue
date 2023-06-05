/*********************
Name: Saeid Jalaliani
Challenge 2 COSC 2436
Purpose: FIFO Stack (QUEUE)
**********************/
#include "fifo.h"

FIFO::FIFO(){
    head = NULL;
    tail = NULL;
}

FIFO::~FIFO(){
    
    Node* current=head;
    
    while(head){
        current = head;
        delete head;
        current->next=head;
    }

}

bool FIFO::push(int num, string *temp){
    
    bool success = false;
    
    if(num>0 && *temp!=""){
        Node* newNode = new Node;
        
        if(head == NULL && tail==NULL){
            head = newNode;
            tail = newNode;
            
            newNode->data.id = num;
            newNode->data.data = *temp;
            newNode->next = NULL;
            
            success = true;
            
        } else {
        
            tail->next = newNode;
            
            newNode->data.id = num;
            newNode->data.data = *temp;
            newNode->next = NULL;
            
            tail = newNode;
            
            success = true;
            
        }
        
        
    } 
    
    return success;
}

bool FIFO::pull(Data *temp){
    bool success = false;
    
    Node* current = head;
    
    if(current){
        temp->id = current->data.id;
        temp->data = current->data.data;
        
        head = current->next;
        delete current;
        success = true;
    }
    
    return success;
}

bool FIFO::peek(Data *temp){
    
    bool success = false;
  
    if(head){
        temp->id = head->data.id;
        temp->data = head->data.data;
        
        success = true;
    }
    
    return success;
}


bool FIFO::isEmpty(){
   
   bool empty = true;
   
    if(head == NULL && tail == NULL){
        empty = true;
    } else {
        empty = false;
    }
    
    return empty;
}