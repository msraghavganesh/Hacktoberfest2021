#include<bits/stdc++.h>
using namespace std;
int lcs(string s1, string s2, int dp[][8], int i, int j){
    
    if(dp[i][j] != -1)
        return dp[i][j];
    int n = 0;
    if(s1.at(i-1) == s2.at(j-1))
        n = 1 + lcs(s1, s2, dp, i-1, j-1);
    else    
        n = max(lcs(s1, s2, dp, i-1, j), lcs(s1, s2, dp, i, j-1));
    dp[i][j] = n;

    return dp[i][j];
}

int main(){

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    int dp[7][8];
    for(int i=0; i<7; i++){
        for(int j=0; j<8; j++){
            if(i==0 || j==0)
                dp[i][j] = 0;
            else
                dp[i][j] = -1;
        }
    }
    
    int i = s1.size();
    int j = s2.size();
    cout<<endl<<endl;
    cout<<"The length of the longest common subsequence is : "<<lcs(s1, s2, dp, i, j)<<endl;
    cout<<endl<<endl;

    return -1;
}