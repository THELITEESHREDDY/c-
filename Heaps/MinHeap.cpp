#include <bits/stdc++.h>
using namespace std;
void minHeapify(vector<int>&v,int n,int i){
    if(i>=n){
        return;
    }
    int l= 2*i+1;
    int r=2*i+2;
    int smallest=i;
    if(l<n && v[l]< v[i]){
        smallest=l;
    }
    if(r< n && v[r]<v[smallest]){
        smallest=r;
    }
    if(i!= smallest){
        swap(v[i],v[smallest]);
        minHeapify(v,n,smallest);
    }
}
void buildMinHeap(vector<int>& v, int n){
    for(int i=((n-1)/2);i>=0;i--){
        minHeapify(v,n,i);     
    }
    minHeapify(v,n,0);
}
void insert(vector<int>& v,int val,int& size){
    v[size++]=val;
    int i=size -1;
    while(i!=0 && v[(i-1)/2] > v[i]){
        swap(v[(i-1)/2 ],v[i]);
        i=(i-1)/2;
    }
}
void deleteheap(vector<int>&v , int& n){
    swap(v[0],v[n-1]);
    v.pop_back();
    n--;
    minHeapify(v,n,0);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    int size=0;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        insert(v,val,size);
    }
    buildMinHeap(v,n);

    cout<<"Min Heap: ";
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