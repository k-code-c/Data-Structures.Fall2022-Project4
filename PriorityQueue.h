//
//  PriorityQueue.h
//  project 4
//
//  Created by Kc Ashiogwu on 12/12/22.
//

#ifndef PriorityQueue_h
#define PriorityQueue_h
using namespace std;
class Node {
public:
    int data;
    int priority;
    
    Node *next;
};

class PriorityQueue{
public:
    PriorityQueue(); //default constructor
    void addData(int data, int priority);
    int Remove();
    int size;
    bool IsListEmpty();
    Node * head;
};


PriorityQueue::PriorityQueue(){
    size = 0;
    head = NULL;
}

void PriorityQueue::addData(int data, int priority){
    //create the new node to be added to the linked list
    Node* newNode = new Node;
    
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    
    //if head is null or the new node is lower priority, then add it first
    
    if(head == NULL || newNode->priority<head->priority){
        newNode->next = head;
        head = newNode;
    }
    
    //otherwise traverse the list until the proper place is found
        //either the end of the list OR where the priority is appropriate
    
    else{
        Node* current = head;
        while(current->next != NULL&& current->next->priority<= newNode->priority){
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
        
    }
    size++;
    
    
}

int PriorityQueue::Remove(){
    //get a pointer to current head (the thing we're removing)
    Node* current = head;
    //update head so that it now points to the next thing
    head = head->next;
    //get the data value from old head
    int returnData  = current->data;
    //delete old head
    delete current;
    size--;
    return returnData;
    //decrement count
    //return the value
}
bool PriorityQueue::IsListEmpty(){
    if(head==NULL){
        return true;
    }
    else{
        return false;
    }
        //
}

#endif /* PriorityQueue_h */


