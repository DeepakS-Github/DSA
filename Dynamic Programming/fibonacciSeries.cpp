#include <bits/stdc++.h>
using namespace std;


// Memoization Method-> Top-down approach 
// TC: O(n) 
// SC: O(n)->for recursion stack + O(n)->for dp vector
int memoization(int n, vector<int> &dp){
    if(n<=1){
        return n;
    }
    if(dp[n]!=-1){
        return dp[n];
    }
    dp[n] = memoization(n-1, dp)+memoization(n-2, dp);
    return dp[n];
}


// Tabular Method -> Bottom-up approach
// TC: O(n) 
// SC: O(n)->for dp vector
int tabular(int n, vector<int> &dp){
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp.back();
}


// SC: O(1)
// TC: O(n)
int spaceOptimized(int n){
    int prev = 1;
    int prev2 = 0;
    int curr;
    for(int i=0; i<n-1; i++){
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }
    return curr;
}


int main(){
    int n = 6;
    vector<int> dp(n+1,-1);
    // cout << memoization(n,dp) << endl;
    // cout << tabular(n,dp) << endl;
    cout << spaceOptimized(n) << endl;
}