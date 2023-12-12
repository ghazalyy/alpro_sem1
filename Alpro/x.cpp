#include <iostream>

using namespace std;
int main(){
int n=11,i=0,k=0,j=0;
for(i=0;i<n;i++)
{
if(i<(n/2)) 
 {
    cout<<endl;
    for(j=0;j<i;j++)
    {
        cout<<" ";
    }
    cout<<"*";
    for(k=n/2;k>i;k--)
    {
        cout<<"  ";
    }
    cout<<"*";
 }
else
 {
    cout<<endl;
    for(k=n-1;k>i;k--)
    {
        cout<<" ";
    }
    cout<<"*";
    for(j=n/2;j<i;j++)
    {
        cout<<"  ";
    }
    cout<<"*";
 }  
}
}
