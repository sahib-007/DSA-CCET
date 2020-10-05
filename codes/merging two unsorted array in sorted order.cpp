#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    	int partition(int a[],int lb,int ub){
	    int pivot=a[lb];
	    int start =lb;
	    int end=ub;
	    while(start<end){
            while(a[start]<=pivot){
                start++;

            }
            while(a[end]>pivot){
                end--;
            }
            if(start<end){
                int temp=a[start];
                a[start]=a[end];
                a[end]=temp;

            }
	    }
	    int temp=a[lb];
	    a[lb]=a[end];
	    a[end]=temp;
	    return end;

	}

	int quick_sort(int a[],int lb,int ub){
	    if(lb<ub){
                int loc=partition(a,lb,ub);
                quick_sort(a,lb,loc-1);
                quick_sort(a,loc+1,ub);

	    }

	}

	void sortedMerge(int a[], int b[], int res[],int n, int m)
	{
        int temp,i,j;
        int first=0,second=0;
	    quick_sort(a,0,n-1);
	    quick_sort(b,0,m-1);

         int mid=n;
         int end=m;
         int index=0;
         i=0,j=0;
	        while((i<mid)&&(j<end)){
            if(a[i]<b[j]){
                    res[index]=a[i];
                    i++;

            }else{
                res[index]=b[j];
                j++;
            }index++;

    }
    if(i>=mid){
        while(j<end){
            res[index]=b[j];
            j++;
            index++;
        }
    }else{
        while(i<mid){
            res[index]=a[i];
            i++;
            index++;
        }
    }



	}
};
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
        int res[n+m];
        Solution ob;
        ob.sortedMerge(a,b,res,n,m);
        for(int i=0;i<n+m;i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";


    }


return 0;


}
