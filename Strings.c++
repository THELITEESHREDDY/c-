#include <bits/stdc++.h>
using namespace  std;

string isPalindrome(string s){
    int n= s.length();

    for(int i=0; i<n;i++){
        int j= (n- 1) - i;
        if(s[i] != s[j]){
            return "No";
        }
    }
    return "Yes";
}

string mostRepeatedWords(string s){

    int n = s.length();
    string temp;
    string finalWord;
    int final =0,count =0;

    istringstream word(s);


    while( word >> temp){
        string currWord;

        for(int i=0; i< temp.length(); i++){
            if(currWord.length()==0){
                currWord.push_back(temp[i]);
            }else{
                int j = 0;

                while( j < currWord.length()){

                    if(temp[i]== currWord[j]){
                        count +=1;
                    }else {
                        currWord.push_back(temp[i]);
                    }
                    j++;
                }
            }
        }

        if(count > final){
            final = count;
            finalWord = currWord;
        }
       
        count =0;
        currWord.clear();
    }
    return finalWord;
}

int countNumbersInString(string s){
    int total=0;
    int i=0;

    while(i < s.length()){
        if(isdigit(s[i])){
            int count =0;

            while(i< s.length() && isdigit(s[i])){
                count = count* 10 + (s[i] - '0');
                i++;

            }
            total += count;
        }else{
            i++;
        }
    }
    return total;
}

// 18
 int longestParenthesis(string p){

    int countLeft=0,countRight=0,n=p.length();
    int i=0,j=(n - 1);
    // for(int i=0; i< n;i++){
    //     if(p[i]=='['){
    //         countLeft +=1;
    //     }else if(p[i]==']'){
    //         countRight +=1;
    //     }
    // }
    // int result = ((countLeft > countRight)? countRight *2 :  countLeft * 2);

    while(i <= j){
        if(p[i]=='['){
            if(p[j]==']'){
                countLeft +=2;
            }
        }
        j--;
        i++;
    }
    return countLeft;
 }

// 41
int secondOccurance(string s,string a){
    int count =0;
    for(int i=0; i< s.length(); i++){

        for(int j=0; i< a.length(); j++){

            if(s[i]==a[j]){

                if(j == a.length() - 1){
                    count +=1;
                }

                if(count ==2){
                    return 1;
                }
            }
        }
    }

    return -1;
}
int maxMex(int arr[],int k, int n){
    int start =0, end= n;
    int min = INT_MIN;
    while(end < n){
        int currMin = INT_MAX, i=start;
         while(i<= end){
            currMin= min_element(arr[i],currMin);
            i++;
        }
            min = max_element(currMin,min);
            start++;
            end++;
    }

    

    return min;
}

int main(){

    int arr[] = { 3, 2, 1, 4 };
 
    // Given length of subarray
    int k = 2;
 
    // Size of the array
    int n = sizeof(arr) / sizeof(arr[0]);
 
    // Function Call
  cout<<  maxMex(arr, n, k);
 


    

    return 0;
}
