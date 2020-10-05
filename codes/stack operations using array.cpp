#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int st[MAX];
int top=-1;
void push(int st[],int val){
    if(top==MAX-1){
        cout<<"Overflow "<<endl;
    }else{
    top++;
    st[top]=val;

}}
void pop(int st[]){
    if(top==-1){
            cout<<"Underflow "<<endl;

    }else{
        cout<<"The value popped out is :"<<st[top];
        top--;
    }


}
void peek(int st[]){
if(top==-1){
    cout<<"Underflow "<<endl;
}else{
    cout<<st[top];
}}
void display(int st[]){
if(top==-1){
  cout<<"Underflow "<<endl;
}
else{
    for(int i=top;i>=0;i--){
        cout<<st[i]<<" ";
    }cout<<endl;
}
}
int main(){
    int val,opt;
    do{
        cout<<endl<<" MAIN MENU";
        cout<<endl<<"1. PUSH";
        cout<<endl<<"2. POP";
        cout<<endl<<"3. PEEK";
        cout<<endl<<"4. DISPLAY";
        cout<<endl<<"5. EXIT";
        cout<<endl<<" Enter the option you want to select:";
        cin>>opt;
        switch(opt){
    case 1:
        cout<<"Enter the value to be pushed\n";
        cin>>val;
        push(st,val);
        continue;
    case 2:
        pop(st);
        continue;
    case 3:
        peek(st);
        continue;
    case 4:
        display(st);
        continue;
    default:
        cout<<"Enter a valid option\n";
        continue;

    }}while(opt!=5);

return 0;}

