#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int frequency(int arr[],int n){
    unordered_map<int,int> mp;
    
    for(int i=0;i<n;i++){
        mp[arr[i]] +=1;
    }
 int max = INT_MIN;
 int min = INT_MAX;
    for(int i=0;i<n;i++){
        max = max > mp[arr[i]] ? max : arr[i];
        min = min < mp[arr[i]] ? min : arr[i];

    }
    cout<<min<<" "<<max;
 return 0;
}

int main(){
 int arr[]= {1,1,0,2,3,4,2,4,4,4,4,5,3,5,5};
 int n = sizeof(arr)/sizeof(arr[0]);

 frequency(arr,n);

    return 0;
}