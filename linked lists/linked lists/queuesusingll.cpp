#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;}

};

class Queue{

    public:

    Node*head;

    Queue(){
        head=NULL;
    }


    void headinsertion(int d){      //push front
        Node*temp = new Node(d);
        temp -> next = head;
        head = temp;
    }

    void taildeletion(){      //pop rear

        Node*p=head;

        while(p->next->next!=NULL){
            p=p->next;
        }

        p->next=nullptr;

    }   

    void print(){
        Node*p=head;
        
        while(p!=NULL){
            cout<<p->data<<" ";
            p=p->next;}

        cout<<endl;
    }
};

int main(){

    Queue q;

    q.headinsertion(4);
    q.headinsertion(3);
    q.headinsertion(2);
    q.headinsertion(1);
    q.print();

    q.taildeletion();
    q.taildeletion();
    q.print();
    



}