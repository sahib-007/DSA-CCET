#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    int sort;
    for(int i=0;i<t;i++){
        sort = i;
        for(int j=0;j<i;j++){
            if(arr[j] > arr[sort]){
                int tmp = arr[j];
                arr[j] = arr[sort];
                arr[sort] = tmp;
                cout<<"  tmp->"<<tmp;
                break; 
            }
        }
    }
    for(int i =0;i<t;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}