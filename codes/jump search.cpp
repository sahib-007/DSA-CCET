#include<bits/stdc++.h>
using namespace std;
int jumpsearch(int arr[],int low,int high,int n,int val){
int step=sqrt(n);
while(arr[step]<val &&high<n)
{
    low=step;
    step=step+sqrt(n);
    if(high>n-1){
        high=n;
    }
}
for(int i=low;i<high;i++){
        if(val==arr[i]){
            return i+1;
        }

}
return -1;

}
int main(){
int n,*arr;
cin>>n;
arr=(int *)malloc(n* sizeof(int));
for(int i=0;i<n;i++){
    cin>>arr[i];
}
int val;
cin>>val;
int pos=jumpsearch(arr,0,n-1,n,val);
if(pos==-1){
    cout<<"The element does not exist"<<endl;
}
else{
    cout<<pos<<endl;
}
return 0;
}

