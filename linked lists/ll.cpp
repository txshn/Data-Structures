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

void headinsertion(Node*&head, int d){
    Node*temp = new Node(d);
    temp -> next = head;
    head = temp;}

void tailinsertion(Node*&head, int d){
    Node*p = new Node(d);

    Node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp-> next = p;
}

void print(Node*&head){

    Node*p=head;
        
    while(p!=NULL){
        cout<<p->data<<" ";
        p=p->next;}

    cout<<endl;
}

void positioninsertion(Node*&head, int d, int pos){

    Node*temp=head;
    int count=1;

    while(count<pos){
        temp=temp->next;
        count++;
    }
    temp->next = new Node(d);
}

void deletion(Node*&head, int key){
    Node*temp;

    if(head->data==key){
        temp=head;
        head=head->next;
        free(temp);}

    else{
        Node*temp1=head;
        while(temp1->next!=NULL){

            if(temp1->next->data==key){
                temp=temp1->next;
                temp1->next=temp1->next->next;
                free(temp);
                break;
            }

            else{
                temp1=temp1->next;}
        }
    }
}

int main(){

    Node*n1=new Node(2);
    headinsertion(n1, 1);
    tailinsertion(n1, 3);
    positioninsertion(n1, 4, 3);
    deletion(n1, 3);
    
    print(n1);

}
