#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int max(int a, int b)  
{  
    return (a > b)? a : b;  
} 


int solve(int n,int p[],int w[],int weight){
    int c[n+1][weight+1];
    for(int i =0;i<=n;i++){
        for(int j=0;j<=weight;j++){
            if(i==0 || j==0)
                c[i][j] = 0;
            else if(j >= w[i]){
                c[i][j] = max(p[i]+c[i-1][j-w[i]],c[i-1][j]);
            }
            else{
                c[i][j] = c[i-1][j];//max(c[i-1][j],c[i-1][j-w[i]]);
            }
        }
    }
    return c[n][weight];

}



int main(){
    int n,we;
    cin>>n>>we;
    // n is no of items and w is the weigth we can carry at most
    int p[n],w[n];
    for(int i= 0;i<n;i++){
        cin>>p[i];
    }
    // input the profit array
    
    for(int i= 0;i<n;i++){
        cin>>w[i];
    }
    // input the weight array
    int ans = solve(n,p,w,we);
    cout<<ans;
    return 0;
}