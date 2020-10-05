#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int quicksort(int s,int t,int arr[]){
    if(s>=t)
        return 0;
    int index;
    int x = t;
    index = partition(arr,s,x);
    quicksort(s,index-1,arr);
    quicksort(index+1,t,arr);
}
int partition(int arr[],int s,int t){
    int value = arr[t-1];
    int piviot =0;
    int index = 0;
    for(int i =s;i<t;i++){
        if(arr[i] > value)
            piviot++;
        else
        {
            int temp =arr[piviot];
            arr[piviot] = arr[i];
            arr[i] = temp;
            index++;
            piviot++;
        }
    }
}

int main(){
    int t;
    cin>>t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin>>arr[i];
    }
    quicksort(0,t,arr);
    return 0;
}