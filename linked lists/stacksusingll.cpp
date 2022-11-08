#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node*next;

    Node(int data){
        this->data=data;
        this->next=NULL;
    }

};


class Stack{

    public:

    Node*head;

    Stack(){
        head=NULL;
    }

    void headinsertion(int d){      //push a stack
        Node*temp = new Node(d);
        temp -> next = head;
        head = temp;}

    void headdeletion(){  //pop a stack
        head=head->next;
    }

    void peek(){      //peek a stack
        cout<<head->data;
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
    
    Stack st;

    st.headinsertion(4);
    st.headinsertion(3);
    st.headinsertion(2);
    st.headinsertion(1);
    st.print();

    st.headdeletion();
    st.print();

    st.peek();
}