#include <bits/stdc++.h>
using namespace std;

void printN_naturalNumbers(int n){

    if(n==0){
        
        return;
    }
    cout<<n<<" ";
    printN_naturalNumbers(n - 1);
    cout<<n<<" ";
    return ;
}

int sumOfNumbers(int n){
   if(n==1){
    return 1;
   }

   return n + sumOfNumbers(n - 1);
}

int sumOfArray(int arr[],int n){
    if(n==1){
        return arr[n];
    }

    return arr[n]+ sumOfArray(arr,n - 1);
}

int factorialNumber(int n){
    if(n<=0|| n==1){
        return 1;
    }

    return n*factorialNumber(n - 1);
    
}
int fibonacci(int n){
    if(n<=0){
        return 0;
    }
    if(n ==1){
        return 1;
    }

    return fibonacci(n - 1 ) + fibonacci(n - 2);
}
int sumOfDigits(int n){
   if(n<=0){
    return 0;
   }

   int sum=0;
   int digit = n%10;
   n/=10;
   sum+=digit;
   return sum + sumOfDigits(n);
}

int minMax(int arr[],int start, int end){
    
   if(start == end){
     return arr[start];
   }

   int  mid =(start + end)/2;
   int max1= minMax(arr,start,mid);
   int max2 = minMax(arr,mid+ 1,end);
   return (max1 > max2 ? max1 : max2);
}

int maxMin(int arr[],int start, int end){
    if(start == end){
        return arr[start];
    }

    int mid = start - (start - end)/2;
    int min1 = maxMin(arr,start,mid);
    int min2 = maxMin(arr,mid + 1, end);
    return (min1 < min2 ? min1 : min2);
}

void reverseString(string &s,int start,int end){
    if(start == end){
        return ;
    }


    char temp = s[start];
    s[start] =s[end];
    s[end] = temp;
     
    reverseString(s,start++,end--);
}


int main(){

    string str;

    getline(cin,str);
    cout<<str;
    reverseString(str,1,str.length() - 1);
    cout<<str;
    
    return 0;
}