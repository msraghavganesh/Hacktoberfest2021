// Writing a program to check whether the given number is prime or not;

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    cin>>n;
   for(i=2;i<n;i++){
       if(n%i==0){
           cout<<"Not Prime"<<endl;
           break;
       }
   }
   if(i==n){
      cout<<"Prime Number";
   }
   return 0;
}
