#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;
    Node*prev;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
    }
};


void headinsertion(Node*&head, int d){

    Node*temp=new Node(d);
    
    temp->next=head;
    head->prev=temp;
    head=temp;
}

void tailinsertion(Node*&head, int d){

    Node*temp=new Node(d);
    Node*p=head;

    while(p->next!=NULL){
        p=p->next;}
    
    p->next=temp;
    temp->prev=p;
    temp->next=NULL;
}


void positioninsertion(Node*&head, int pos, int d){

    Node*temp=new Node(d);
    Node*p=head;
   
    int count=1;

    while(count<pos){
        p=p->next;
        count++;
    }
    
    temp->next=p->next;
    p->next->prev=temp;
    p->next=temp;
    temp->prev=p;   

}

void deletion(Node*&head, int key){
    Node*temp;

    if(head->data==key){
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }

    else{
        Node*temp1=head;

        while(temp1->next!=NULL){
            if(temp1->next->data==key){

                temp=temp1->next;
                temp1->next=temp1->next->next;
                temp1->prev=temp->prev;
                free(temp);
            }

            else{
                temp1=temp1->next;
            }
        }
    }
}

void print(Node*&head){
    Node*p=head;

    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;
    }

    cout<<endl;
}

//reversing a doubly ll means, start printing prev from tail, instead of normal next from head


int main(){

    Node*n1=new Node(2);
    headinsertion(n1, 1);
    tailinsertion(n1, 3);
    print(n1);

    deletion(n1, 2);
    print(n1);

}