#include<iostream>
using namespace std;

class Node{
    public:
    int coeff;
    int exp;
    Node*next;


    Node(int coeff, int exp){       //basically creating a linked list which holds 2 values instead of 1, ie, coefficient and exponent of a polynomial
        this->exp=exp;
        this->coeff=coeff;
        next=NULL;
    }
};

    void printNode(Node*head){      //printing a node by traversing it
        Node*p = head;

        while(p!=NULL){
            cout<<p->coeff<<"x^"<<p->exp<<" ";
            p=p->next;
        }
    }

    void insertNode(Node*head, int coeff, int exp){     //inserting a node at the end of the list
        Node*temp = head;
        
        while(temp->next!=NULL){
            temp=temp->next; 
        }

        temp->next=new Node(coeff, exp); 
    }
    
    void addition(Node*head1, Node*head2){      //comparing 2 different linked lists, and thus adding them

        Node*result = NULL;

        while(head1!=NULL && head2!=NULL){     

            int c, e;

            if(head1->exp==head2->exp){     //if same exponent
                c = (head1->coeff) + (head2->coeff);
                e = head1->exp;
                head1=head1->next;
                head2=head2->next;   
            }

            else if(head1->exp>>head2->exp){        //if head1 exponent is greater than head2 exponent
                c = head1->coeff;
                e = head1->exp;
                head1 = head1->next;
            }

            else{       //if head1 exponent is greater than head2 exponent
                c = head2->coeff;
                e = head2->exp;
                head2 = head2->next;
            }
            

            if(result==NULL){
                result = new Node(c, e);
            }

            else{
                insertNode(result, c, e);
            }
        }

        while(head1!=NULL){      //assuming head2 is over, so we have to print remaining head1 result
            if(result==NULL){
                result = new Node(head1->coeff, head1->exp);
            }

            else{
                insertNode(result, head1->coeff,head1->exp);
            }
        }

        while(head2!=NULL){      //assuming head1 is over, so we have to print remaining head2 result
            if(result==NULL){
                result = new Node(head2->coeff, head2->exp);
            }

            else{
                insertNode(result, head2->coeff,head2->exp);
            }
        }

        printNode(result);

    }


int main(){
    Node*sex1 = new Node(3, 2);
    insertNode(sex1, 2, 1);
    insertNode(sex1, 4, 0);

    Node*sex2 = new Node(4, 3);
    insertNode(sex2, 2, 2);
    insertNode(sex2, 9, 0);

    addition(sex1, sex2);
}
