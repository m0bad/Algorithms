#include <iostream>
using namespace std;

struct node{
  int data;
  node *left_child;
  node *right_child;
  node *parent;
};

class binaryTree{
private:
  node *root;
public:
  binaryTree(){
    root=NULL;
  }

  void insert(int value){
    node *temp=new node();
    temp->data=value;
    temp->left_child=NULL;
    temp->right_child=NULL;
    if (root ==NULL){
      temp->parent=NULL;
      root = temp;
    }
    else {
      node *current =new node();
      node *previous=new node();
      current=root;
      while(current!=NULL){
        previous=current;

        if(value > current->data){
          current=current->right_child;
        }
        else{
          current=current->left_child;
        }
      }

      if (value > previous->data){
        previous->right_child=temp;
      }
      else{
        previous->left_child=temp;
      }
      temp->parent=previous;
    }
  }

  bool search(int value){
    node *current=new node();
    while(current!=NULL){
      if (value>current->data){
        current=current->right_child;
      }
      else if (value<current->data){
        current=current->left_child;
      }
      else{//if equal
        return true;
      }
    }
    return false;
  }


};


int main(){

}
