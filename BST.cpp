/*Implement Binary Search Tree
4) Node * find_min(Node *) - Gets minimum node in a subtree
5) void replace_At_Parent(Node * A, Node *B) - Replaces A with B at the parent of A. This replacement makes the B the respective child (left/right child depending if A was left or right child of its parent)
6) void deleteNode(int value) - Deletes the node with "value"*/
#include<iostream>
using namespace std;
//class node
class node {
      public:
      int data;
      node*parent;
      //filial nodes
      node*left;
      node*right;
      //default constructor
      node(int value) { 
            parent = NULL;
            left = NULL;
            right = NULL;
            data = value;
      }
};
//class BST for the tree
class BST {
      public:
      //roooooooooooooot
      node*root; 
      //default constructor
      BST() {
           root = NULL;
      }
      //1. insert()
      void insert(int value) { //dummy function
           insert(root, value); //sets current = root
           }
      void insert(node*current, int value) {
           if(root == NULL) { 
                   root = new node(value);
           }
           else {
                   if(value < current -> data) {
                            if(current -> left == NULL) {
                                       current -> left = new node(value);
                                       current -> left -> parent = current;
                            }
                            else {
                                       insert(current -> left, value);
                            }
                   }
                   else {
                            if(current -> right == NULL) {
                                       current -> right = new node(value);
                                       current -> right -> parent = current;
                            }
                            else {
                                       insert(current -> right, value);
                            }
                   }
           }
      }
      //2. display()
      void display() { //dummy function
           display(root); //sets current = root
           cout << endl;
      }
      void display(node*current) {
           if(current == NULL) {
                      return;
           }
           //display left
           display(current -> left);
           //display current
           cout << current -> data << ", ";
           //display right
           display(current -> right);
      }
      //3. search()
      node*search(int value) { //dummy function
           return search(root, value); //sets current = root
      }
      node*search(node*current, int value) {
           if(current == NULL || current -> data == value) {
                      return current;
           }
           else {
                      if(value < current -> data) {
                               return search(current -> left, value); //go left
                      }
                      else {
                               if(value > current -> data) {
                                        return search(current -> right, value); //go right
                               }
                      }
           }
      }
      //2D display
      void print2D() { //dummy function
           print2D(root, 0); //sets current = root 
      }  
      void print2D(node*current, int spaces) {  
           if(current == NULL) {
                       return;  
           }
           spaces += 5; 
           print2D(current -> right, spaces); 
           cout << endl;
           for(int i = 5; i < spaces; i++) {
                     cout << " ";
           }
           cout << current -> data;
           print2D(current -> left, spaces);
      }
      //4.node*find_min(node*)
      int find_min(int value) {
          node*current = search(root, value);
          node*min = find_min(current);
          return min -> data;
      }
      node*find_min(node*current) {
           if(current == NULL) {
                      cout << "No minimum." << endl;
                      return NULL;
           }
           else { 
                      if(current -> left == NULL) {
                                 cout << current -> data << endl;
                                 return current;
                      }
                      else {
                                 find_min(current -> left);
                      }
           }
      }
      //5.void replace_At_Parent(node*A, node*B)
      void replace_At_Parent(node*A, node*B) {
           if(A -> parent -> left == A) {
                A -> parent -> left = B;
           }
           else {
                if(A -> parent -> right == A) {
                     A -> parent -> right = B;
                }
                else {
                     if(B != NULL) {
                          B -> parent = A -> parent;
                     }
                     else {
                          A -> parent = NULL;
                     }
                }
           }
      }
      //6.void deleteNode(int value)
      void deleteNode(int value) {
           node*current = search(root, value);
           if(current == NULL) {
                      cout << "Cannot delete." << endl;
           }
           else {
                      if(current -> left == NULL) {
                                 replace_At_Parent(current, current -> right);
                      }
                      else {
                                 if(current -> right == NULL) {
                                            replace_At_Parent(current, current -> left);
                                 }
                                 else {
                                            node*temp = find_min(current -> right);
                                            current -> data = temp -> data;
                                            replace_At_Parent(temp, NULL);
                                            delete temp;
                                 }
                      }
           }
      }
      
};
//main function
int main() {
    BST NMB48;
    NMB48.insert(5);
    NMB48.insert(2);
    NMB48.insert(8);
    NMB48.insert(1);
    NMB48.insert(6);
    NMB48.insert(4);
    NMB48.insert(7);
    NMB48.insert(3);
    NMB48.display();
    cout << NMB48.search(3) -> data << endl;
    cout << NMB48.search(3) << endl;
    NMB48.print2D();
    cout << endl;
    cout << "Minimum: ";
    NMB48.find_min(2);
    cout << endl;
    NMB48.deleteNode(4);
    NMB48.print2D();
    cout << endl;
    return 0;
}
