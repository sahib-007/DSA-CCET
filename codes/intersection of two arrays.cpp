#include<bits/stdc++.h>// not ioptimised
using namespace std;
int binarysearch(int b[100],int lb,int ub,int x){
    int count=0;
            while(lb<=ub){
        int mid=lb+(ub-1)/2;
        if(x==b[mid]){
                count=count+1;
                return count;

        }
        if(x>b[mid]){
            lb=mid+1;
        }
        if(x<b[mid]){
            ub=mid-1;
        }

}
return count;}
int intersection(int a[100],int b[100],int n,int m){
    sort(a,a+n);
    sort(b,b+m);
    int ans=0;

        for(int i=0;i<n;i++){
          int  res=binarysearch(b,0,m-1,a[i]);
          if(res!=0){
            ans=ans+1;}


}
return ans;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }
        int result=intersection(a,b,n,m);
        cout<<result<<endl;


    }
    return 0;
}
