/*
    This is a part of dynamic programming and is problem number 4;
*/



#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
} 

int lcs(string s1,int len1,string s2,int len2){
    int c[len1+1][len2+1] = {0};

    for(int i=0;i<=len1;i++){
        for(int j=0;j<=len2;j++){
            if(i==0 || j==0)
                c[i][j] = 0;
            else if(s1[i-1] == s2[j-1])
                c[i][j] = 1+c[i-1][j-1];
            else{
                c[i][j] = max(c[i][j-1],c[i-1][j]);
            }
        }
    }
    return c[len1][len2];
    
}

int main(){
    string s1,s2;
    s1 = "abcdedab";
    s2 = "cbdeab";
    int len1 = s1.length();
    int len2 = s2.length();
    int ans = lcs(s1,len1,s2,len2);
    cout<<ans;
    return 0;
}