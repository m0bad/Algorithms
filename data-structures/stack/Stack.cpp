#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};


class stack {
private:
    Node *top;
    int count;
public:
    stack(){
        top = NULL;
        count =0;
    }

    bool isEmpty(){
        if(top != NULL){
            return false;
        }
        return true;
    }

    int getTop(){
        return top->data;
    }
    int getCount(){
        return count;
    }

    void push(int value){
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        count ++;
    }

    int pop(){
        if(top == NULL){
            cout <<"the stack is empty"<<endl;
            return 0;
        }else{
            Node *temp = new Node();
            int result = top->data;
            temp= top->next;
            delete top;
            top = temp;
            count --;
            return result;
        }
    }

};


