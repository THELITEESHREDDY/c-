#include<bits/stdc++.h>
using namespace std;
struct tree {
	int data;
	tree* left;
	tree* right;

	tree(int x):data(x),left(nullptr),right(nullptr) {}
};

void printlevelorderTraversal(tree* root) {
	if(root==NULL)return;
	cout<<endl;
	queue<tree*>s;
	s.push(root);
	while(!s.empty()) {

		tree* curr = s.front();
		cout<<curr->data<<" ";

		s.pop();
		if(curr->left) {
			s.push(curr->left);

		}

		if(curr->right) {
			s.push(curr->right);

		}

	}
	return;
}
void printpostorder(tree* root) {
	if(root ==NULL) {
		return ;
	}
	printpostorder(root->left);
	printpostorder(root->right);
	cout<<root->data<<" ";
}
void printpreorder(tree* root) {
	if(root == NULL)return;

	cout<<root->data<<" ";
	printpreorder(root->left);
	printpreorder(root->right);
}
void printinorder(tree* root) {
	if(root==NULL)return;

	printinorder(root->left);
	cout<<root->data<<" ";
	printinorder(root->right);
}
tree* construct(vector<int> v,int i) {
	if(i>=v.size()) {
		return nullptr;
	}
	tree* node = new tree(v[i]);

	node->left=construct(v,2*i + 1);

	node->right = construct(v,2*i + 2);

	return node;
}
void searchelementsintree(){
	cout<<"\nSearch Element: click 1.DFS : 2.BFS"<<endl;
	int o;
	cin>>o;
	cout<<"enter target: ";
	int target;cin>>target;
	
	if(o==1){
	    o=0;
	    cout<<"1.preorder\n"<<"2.inorder\n"<<"3.postorder"<<endl;
	    cin>>o;
	    bool ans=(o==1? searchpreorder(root,target):((o==2)? searchinorder(root,target):searchpostorder(root,target)));
	    if(ans==true){
	        cout<<"Element found"<<endl;
	    }else{
	        cout<<"Element not found"<<endl;
	    }
	    
	}else{
	    bool ans =searchlevelorder(root,target);
	    if(ans ==true){
	        cout<<"Element found"<<endl;
	    }else{
	        cout<<"Element not found"<<endl;
	    }
	}
}
int main() {
	int n;
	cout<<"give n: ";
	cin>>n;
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin>>v[i];
	}

	tree* root =construct(v,0);
	cout<<"Print Tree: Depth-first search "<<endl;
	cout<<"Inorder: ";
	printinorder(root);
	cout<<"\nPreorder: ";
	printpreorder(root);
	cout<<"\nPostorder: ";
	printpostorder(root);
	cout<<"\nBreadth-first search "<<endl;
	printlevelorderTraversal(root);
	
	
	return 0;
}
