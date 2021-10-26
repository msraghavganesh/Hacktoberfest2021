#include<bits/stdc++.h>
using namespace std;
int precedence(char c){
    if(c=='^'){
        return 3;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else if(c=='+' || c=='-'){
        return 1;
    }
    return -1;
}
string infixToPostfix(string s){
    string res="";
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z')){
            res+=s[i];
        }
        else if(s[i]=='('){
            st.push(s[i]);
        }
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(st.top())>precedence(s[i])){
                    res+=st.top();
                    st.pop();
            }
            st.push(s[i]);
        }
    }
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    return res;
}
int main(){
    string s;
    cout<<"\n Enter the String:";
    getline(cin,s);
    //cout<<s;
    cout<<"\n"<<infixToPostfix(s);
    return 0;
}