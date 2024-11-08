#include <bits/stdc++.h>
using namespace std;
void maxHeap(vector<int>&v, int n,int i){
    if(i>=n){
        return;
    }
    int l= 2*i+1;
    int r = 2*i+2;
    int largest=i;
    if(l<n && v[l]> v[i]){
        largest=l;
    }
    if(r<n && v[r] > v[largest]){
        largest=r;
    }
    if(i!=largest){
        swap(v[i],v[largest]);
        maxHeap(v,n,largest);
    }
}
void heapsort(vector<int>&v ,int n){
    //this loop builds heap structure
    for(int i=(n-1)/2;i>=0;i--){
        maxHeap(v,n,i);
    }
    //this loop every time 0 index will have max element,
    // swaps max element with last one then i decreases
    //again builds heap from 0 to n-2 , swap 0index (max element) with last index;
    for(int i=n-1;i>=0;i--){
        maxHeap(v,i,0);
        swap(v[0],v[i]);
    }
}
int main(){
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    
    heapsort(v,n);
    cout<<"Heap Sort: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    return 0;
}