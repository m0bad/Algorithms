#include<iostream>
#include "bst.h"
using namespace std;

	BST::BST(){
		root=NULL;
	}
	BST::node *BST::createLeaf(int key){
		node *temp = new node;
		temp->key=key;
		temp->left=NULL;
		temp->right=NULL;

		return temp;
	}

	void BST::addLeaf(int key){
		addLeafPrivate(key,root);
	}
	void BST::addLeafPrivate(int key, node *ptr){
		//check if the tree is empty
		if(root == NULL){
			//create a new root with the key as a value
			root=createLeaf(key);
		}
		else if (key < ptr->key){
			if(ptr->left != NULL){
				addLeafPrivate(key,ptr->left);
			}
			else{//the left child is empty
				ptr->left=createLeaf(key);
			}
		}
		else if (key > ptr->key){
			if(ptr->right != NULL){
				addLeafPrivate(key,ptr->right);
			}
			else{//the left child is empty
				ptr->right=createLeaf(key);
			}

		}
		else{
			cout<<"the key "<<key<<" has already been added to the tree\n";
		}
	}


	int findSmallest(){
		findSmallestPrivate(root);
	}
	int BST::findSmallestPrivate(node *ptr){
		if(root == NULL){
			cout<<"the tree is empty\n";
			return -1;
		}
		else{
			//we don't want to look in the right child
			//it always gonna be bigger
			if(ptr->left != NULL){
				return findSmallestPrivate(ptr->left);
			}
			else{//the most left element is the smallest one
				return ptr->key;
			}
		}
	}



	void BST::removeNode(int key){
		removeNodePrivate(key,root);
	}
	void BST::removeNodePrivate(int key,node *parent){
		if (root != NULL){ //if the tree is not empty
			if(root->key == key){//if the root matches the key
				removeRootMatch();
			}
			else{
				if(key < parent->key && parent->left != NULL){
					// if parent->left->key === key??
					//if so:
					if(parent->left->key == key)
						removeMatch(parent,parent->left,true);
					//if not : recursive
					else
						removeNodePrivate(key,parent->left);
				}
				else if(key > parent->key && parent->right != NULL){
					// if parent->right->key === key??
					//if so:
					if(parent->right->key ==key)
						removeMatch(parent,parent->right,false);
					//if not : recursive
					else
						removeNodePrivate(key,parent->right);
				}
				else{//the key does not exist in the tree
					cout<<"the key "<<key<<" was not found in the tree\n";
				}
			}
		}
		else{
			cout<<"the tree is empty\n";
		}
	}

	void BST::removeRootMatch(){
		if(root != NULL){
			node *delPtr=root;
			int rootKey=root->key;//for printing purposes
			int smallestInRightSubTree;

			//case 0 : root has 0 children
			if(root->left ==NULL && root->right ==NULL){
				root=NULL;
				delete delPtr;
			}
			//case 1 : 1 child (either left or right)
			//if right
			else if(root->left ==NULL && root->right != NULL){
				root = root->right;
				//then completely disconnecting the old root from the tree
				delPtr->right=NULL;
				delete delPtr;
				cout<<"The root node with key "<<rootKey<<" was deleted. "<<"the new root contains key "<<root->key<<endl;
			}
			//if left
			else if(root->left !=NULL && root->right == NULL){
				root = root->left;
				//then completely disconnecting the old root from the tree
				delPtr->left=NULL;
				delete delPtr;
				cout<<"The root node with key "<<rootKey<<" was deleted. "<<"the new root contains key "<<root->key<<endl;
			}
			//case 2: root has 2 children
			else{
				smallestInRightSubTree=findSmallestPrivate(root->right);
				removeNodePrivate(smallestInRightSubTree,root);
				root->key=smallestInRightSubTree;
				cout<<"the root key containing key "<<rootKey<<" was overritten with key "<<root->key<<endl;
			}
		}
		else{
			cout<<"can not remove root,the tree is empty\n";
		}
	}

	void BST::removeMatch(node *parent,node *match,bool left){
		if(root != NULL){
			node *delPtr;
			int matchKey=match->key;
			int smallestInRightSubTree;

			//case 0 : 0 children
			if(match->left == NULL && match->right == NULL){
				delPtr=match;
				left == true ? parent->left=NULL : parent->right = NULL;
				delete delPtr;
				cout<<"the node containing key "<<matchKey<<" was removed\n";
			}
			//case 1: 1 child(left or right)
			//case right
			else if (match ->left == NULL && match->right!=NULL){
				left == true ? parent->left = match->right : parent->right=match->right;
				match->right=NULL;
				delPtr=match;
				delete delPtr;
				cout<<"the node containing key "<<matchKey<<" was removed\n";

			}
			//case left
			else if (match ->left != NULL && match->right==NULL){
				left == true ? parent->left = match->left : parent->right=match->left;
				match->left=NULL;
				delPtr=match;
				delete delPtr;
				cout<<"the node containing key "<<matchKey<<" was removed\n";

			}
			//case 2: has 2 children
			else{
				smallestInRightSubTree=findSmallestPrivate(match->right);
				removeNodePrivate(smallestInRightSubTree,match);
				match->key=smallestInRightSubTree;
			}
		}
		else{//probaly will never execute
			cout<<"Can not remove match, the tree is empty\n";
		}
	}
