#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

class listQueue()
{
     node* front;
     node* rear;
     listQueue(){
         front =NULL;
         rear=NULL;
     }

void enqueue(int x){
     node *temp=new node();
     temp->data=x;
     temp->next=NULL;
     if(front==NULL&&rear==NULL){
        front=temp;
        rear=temp;

     }
     else{
     rear->next=temp;
     rear=temp;
     }
}
void dequeue(){
   //ode *temp=new node();
    if (front == NULL){
        cout<<"queue is empty"<<endl;


    }
    else if (front == rear){
        front = NULL;
        rear=NULL;
    }
    else{
      node *temp=new node;
      temp=front;

        front=front->next;
        delete temp;
    }
}

int front(){
    if(front==NULL){
         cout<<"queue is empty"<<endl;
         return;
    }
    return front->data;
}

};


int main()
{

	return 0;
}
