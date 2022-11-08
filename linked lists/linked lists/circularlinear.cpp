#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=this;
    }
};

//circular is a game of tail, not head

void insertion(Node*&tail, int d){      //same code for inserting at beginning and end
    Node*temp=new Node(d);

    if(tail==NULL){
        tail=temp;
        tail->next=tail;
    }
    else{
        temp->next=tail->next;
        tail->next = temp;
    }   
}

void positioninsertion(Node*&tail, int d, int pos){

    Node*temp=tail;
    int count=1;

    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->next = new Node(d);
}

void deletion(Node*&tail, int key){
    Node*temp;

    if(tail->data==key){
        temp=tail;
        tail=tail->next;
        free(temp);}

    else{
        Node*temp1=tail;
        while(temp1->next!=tail){

            if(temp1->next->data==key){
                temp=temp1->next;
                temp1->next=temp1->next->next;
                free(temp);
               
            }

            else{
                temp1=temp1->next;}
        }
    }
}

void print(Node*&tail){

    Node*p=tail;
        
    while(p->next!=tail){
        cout<<p->next->data<<" ";
        p=p->next;
    }
    cout<<p->next->data<<" ";

    cout<<endl;
}


int main(){

    Node*n1=new Node(2);
   
    insertion(n1, 7);
    insertion(n1, 1);
    insertion(n1, 7);
    
    print(n1);
    deletion(n1,7);
    print(n1);


}


