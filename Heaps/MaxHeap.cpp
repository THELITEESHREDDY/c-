#include <bits/stdc++.h>
using namespace std;
void maxHeapify(vector<int>&v,int n,int i){
    if(i>=n){
        return;
    }

    int l=2*i + 1;
    int r=2*i + 2;
    int largest =i;
    if(l<n && v[l]> v[largest]){
        largest=l;
    }
    if(r <n && v[r] > v[largest]){
        largest =r;
    }
    if(i!=largest){
        swap(v[i],v[largest]);
        maxHeapify(v,n,largest);
    }
}
void buildMaxHeap(vector<int>&v,int n){
    for(int i=((n-1)/2 );i>=0;i--){
        maxHeapify(v,n,i);
    }
    maxHeapify(v,n,0);
}
void insert(vector<int>&v,int& size,int val){
    v[size++]=val;
    int i=size-1;
    
    while(i!=0 && v[(i-1)/2] < v[i]){
        swap(v[(i-1)/2],v[i]);
        i=(i-1)/2;
    }
}
void deleteheap(vector<int>&v , int& n){
    swap(v[0],v[n-1]);
    v.pop_back();
    n--;
    maxHeapify(v,n+1,0);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int size=0;
    for(int i=0;i<n;i++){
        int val;cin>>val;
        insert(v,size,val);
    }
    buildMaxHeap(v,n);

    cout<<"Max Heap: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    deleteheap(v,n);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    return 0;
}