#include <iostream>

using namespace std;


struct node {
    int data;
    node* next;
};


class list{
private:
    node *head, *tail;
public :

list(){
    head=NULL;
    tail=NULL;
    }
void create_node(int value){
/*
The creation of a new node at the end of nexted list has 2 steps:
    -nexting the newly created node with tail node. Means passing the address of a new node to the next pointer of a tail node.
    -The tail pointer should always point to the last node. So we will make our tail pointer equal to a new node.
*/
    node *temp=new node();
    temp -> data = value;
    temp -> next = NULL;
    if (head == NULL){
    head=temp;
    tail=temp;
    temp=NULL;
}
    else {
    tail -> next = temp;
    tail=temp;
    }
}




void display(){
    node *temp=new node();
    temp=head;
    while (temp != NULL){
    cout<<temp -> data<<"\t";
    temp= temp -> next;
    }
}

//insertion at the start
void insert_start(int value){
/*
to  insert a node at the start of a singly nexted list , there is two-step algorithms:
   - New node should be connected to the first node, which means the head. This can be achieved by putting the address of the head in the next field of the new node.
   - New node should be considered as a head. It can be achieved by declaring head equals to a new node.
*/
    node *temp=new node();
    temp -> data = value;
    temp ->next  = head;
    head = temp;
}

// the insertion at the end is the same as creation function which we inserted at end of the list .

//Insertion at Particular Position
void insert_position(int pos, int value){
/*
we insert between two nodes (cuurent and previous), there are 2-steps:
    Pass the address of the new node in the next field of the previous node.
    Pass the address of the current node in the next field of the new node.
*/

    node *pre=new node();
    node *cur=new node();
    node *temp=new node();
    cur=head;
    for(int i=1;i<pos;i++){
    pre=cur;
    cur= cur -> next;
    }
    temp ->data = value;
    pre -> next = temp;
    temp -> next = cur;
}

//Deletion at the start
void delete_first(){
/*
there are 3 steps :
    -Declare a temp pointer and pass the address of the first node, i.e. head to this pointer.
    -Declare the second node of the list as head as it will be the first node of linked list after deletion.
    -Delete the temp node.
*/

    node *temp=new node();
    temp=head;      //created to be deleted later , because if i do (head=head->next) what will be deleted then ?
    head=head -> next;
    delete temp;
}


//Deletion at the End
void delete_last(){
/*
-you will need access to the second to the last node of the linked list as you will delete the last node and make the previous node as the tail of linked list.
-the algorithm should be capable of finding a node that comes before the last node by traversing the linked list
-we would make two temporary pointers and let them move through the list
-at the end the previous node will point to the second to the last node and the current node will point to the last node that will be deleted
-We would delete this node and make the previous node as the tail
*/
    node *current=new node();
    node *previous=new node();
    current=head;
    while(current -> next != NULL){
       previous=current;
       current = current ->next;
    }
    tail=previous;
    previous ->next =NULL;
    delete current;

    }

//Deletion at a Particular Position
void delete_position(int pos){
/*
-We ask the user to input the position of the node to be deleted
- we move two temporary pointers through the linked list until we reach our specific node
-we delete our current node and pass the address of the node after it to the previous pointer
*/
    node *current=new node();
    node *previous=new node();
    //node *temp=new node();
    current=head;
    //temp=head;
    for (int i=1;i<pos;i++){
        previous = current;
        current = current-> next;
    }
    previous -> next = current -> next;
}


bool searchList(int value){
    node *temp=new node();
    temp=head;
    while(temp != NULL){
        if(temp->data==value){
            return true;
          }
          temp=temp->next;
        }
        return false;
      }

};
int main()
{
    list l1;
    l1.create_node(10);
    l1.insert_start(5);
    l1.create_node(15);
    bool found=l1.searchList(5);
    l1.display();
    if(found==true)cout<<"found"<<endl;
    return 0;
}
