#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll minimimizingCoinsRec(ll x, vector<ll> &coins){
    if(x == 0)
        return 0;
    ll ans = INT_MAX;
    for(auto z: coins){
        if(x - z >= 0){
            ans  = min(minimimizingCoinsRec(x-z,coins) + 1,ans);
        }
    }
    return ans;

}

ll minimimizingCoinsMemo(ll x, vector<ll> &coins, vector<ll>&dp){
    if(dp[x]!=INT_MAX)
        return dp[x];
    if(x == 0)
        return 0;
    ll ans = INT_MAX;
    for(auto z : coins){
        if(x-z >= 0){
            ans  = min(minimimizingCoinsMemo(x-z,coins,dp) + 1, ans);
        }
    }
    return dp[x] = ans;
}

int main(){
    // n is the number of coins and x is the desired sum of money
    ll n, x;
    cin >> n >> x;
    // vector coins contains the denomination of coins we have
    vector<ll> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    // let's see the recursive approach
    cout << minimimizingCoinsRec(x,coins) << endl;

    // let's memoize the recursive approach.
    vector<ll> dp(x+1, INT_MAX);
    cout <<"ans from memoized approach  : " <<  minimimizingCoinsMemo(x,coins,dp) << endl;

    // let's do the bottom up approach 
    vector<ll> dp1(x+1, INT_MAX);
    dp1[0] = 0;
    for(int i = 0; i <= x; i++){
        for(auto z: coins){
            if(i - z >=0){
                dp1[i] = min(dp1[i-z] + 1, dp1[i]);
            }

        }
    }
    
    cout <<"ans from bottom up  approach  : " <<  dp1[x] << endl;

    // note: memoized solution gets tle in one case also replace ans with -1 in case its not possible to create a valid solution. bottom up approach passes.
}
