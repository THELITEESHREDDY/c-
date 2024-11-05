#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    int height;
    Node(int d):data(d),left(NULL),right(NULL),height(1){}
};
int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return root->height;
}

int getBal(Node* root){
    if(root==NULL){
        return 0;
    }
    return height(root->left)-height(root->right);
}

Node* rotateLeft(Node* root){
    if(root==NULL){
        return nullptr;
    }

    Node* temp =root->right;
    Node* prev=temp->left;
    temp->left=root;
    root->right=prev;
     root->height= 1+ max(height(root->left),height(root->right));
    temp->height=1+ max(height(temp->left),height(temp->right));
    return temp;
}
Node* rotateRight(Node* root){
    if(root==NULL){
        return nullptr;
    }
    Node* temp=root->left;
    Node* prev=temp->right;
    temp->right=root;
    root->left=prev;
    root->height= 1+ max(height(root->left),height(root->right));
    temp->height=1+ max(height(temp->left),height(temp->right));
    return temp;
}

Node* insert(Node* root,int d){
    if(root==nullptr){
        root= new Node(d);
        return root;
    }

    if(root->data < d){
        root->right=insert(root->right,d);
    }else if(root->data > d){
        root->left = insert(root->left,d);
    }
    root->height=1+ max(height(root->right),height(root->left));
    int bal =getBal(root);
    if(bal >1){
        if(root->left->data > d){
            //left left case
            return rotateRight(root);
        }
        if(root->left->data <d){
            //left right case
            root->left=rotateLeft(root->left);
            return rotateRight(root);
        }
    }
    if(bal < -1){
        if(root->right->data <d){
            //right right case
            return rotateLeft(root);
        }
        if(root->right->data > d){
            //right left case
            root->right= rotateRight(root->right);
            return rotateLeft(root);
        }
    }
    return root;

}
void print(Node* root){
    if(root==NULL )return;

    print(root->left);
    cout<<root->data<<" height->: "<<root->height<<endl;
    print(root->right);
}
int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;

    vector<int>v(n);
    Node* root=NULL;
    for(int i=0;i<n;i++){
        cin>>v[i];
        root=insert(root,v[i]);
    }
    print(root);
    int val;
    cout<<"Enter val to delete "<<endl;
    cin>>val;
    //root=deleteNode(root,val);
    print(root);

    return 0;
}