#include <iostream>
#include <new>
using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int x, Node *n){
        data=x;
        next=n;
    }
    Node(){
        data=0;
        next=NULL;
    }

};
class Stack{
public:
    Node *head;
    int max_size=5;
    int size;
public:
    Stack(){
        head= NULL;
    }
    bool push(int x){
            if(size==max_size){
                cout<< "Wrong"<<endl;
                return false;
            }
            else{
                Node *temp;
                Node* n1=new Node(x,NULL);
                temp=head;
                for (int i=1;i<size;i++){
                    if(temp->next!=NULL){
                        temp=temp->next;
                    }
                    else{
                        temp->next=n1;
                        size++;
                    }
                }
            }
        return true;
    }
    Node* pop(){

        if(head== NULL){
            cout<< "Null Stack"<<endl;
            return NULL;
        }
        else{
            return top();
            size--;

        }

    }

    Node* top() {
        Node *temp;
        temp=head;
        for (int i = 0; i < size; i++) {
            if (temp->next != NULL) {
                temp = temp->next;
            } else {
                return temp;

            }

        }
    }
     void display(){
        Node* temp;
         temp=head;
         for (int i = 0; i < size; ++i) {
             if(temp->next==NULL){
                 cout<< temp->data<<endl;
                 break;
             }
             cout<< temp->data<<endl;
             temp=temp->next;

         }
    }

};
int main() {

    Stack *stack=new Stack();
    stack->push(3);
    cout<< stack->head->data<<endl;
    stack->push(5);
    stack->pop();
    stack->display();
    return 0;
}
