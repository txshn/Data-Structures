#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node*left;
        Node*right;

    Node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

Node*buildTree(Node*root){

    cout<<"enter data: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);

    if(data==-1){
        return NULL;
    }

    cout<<"enter data for inserting in left of "<< data <<endl;
    root->left=buildTree(root->left);

    cout<<"enter data for inserting in right of "<< data << endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node*root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp = q.front();
        q.pop();

        if(temp==NULL){
            cout << endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout << temp->data <<" ";
            if(temp->left){
                q.push(temp->left);
            }                                                                                                                                                       
    
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inorder(Node*root){

    if(root==NULL){
        return ;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(Node*root){

    if(root==NULL){
        return ;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node*root){

    if(root==NULL){
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;
    cout<<"enter data for root: "<<endl;
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;

        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;

        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }


}

int main(){
    Node*root=NULL;
    
    /*
    root = buildTree(root);


    cout<<"print level order traversal output "<<endl;
    levelOrderTraversal(root);

    cout<<"print inorder traversal output"<<endl;
    inorder(root);
    cout<<endl;

    cout<<"print preorder traversal output"<<endl;
    preorder(root);
    cout<<endl;

    cout<<"print postorder traversal output"<<endl;
    postorder(root);
    cout<<endl;
*/

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    return 0;


}