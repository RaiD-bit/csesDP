#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll coinCombination1(ll x, vector<ll> &coins){
    if(x == 0)
        return 1;
    ll ans = 0;
    for(auto z: coins){
        if(x-z>=0){
            ans += coinCombination1(x-z,coins);
        }
    }
    return ans;
}

ll coinCombination1Memo(ll x, vector<ll> &coins, vector<ll> &dp){
    if (dp[x] != -1)
        return dp[x];
    if (x == 0)
        return 1;
    ll ans = 0;
    for(auto z: coins){
        if (x - z >= 0){
            ans += coinCombination1Memo(x-z,coins,dp);
            ans %= 1000000007;
        }
    }
    return dp[x] = ans;
}

int main(){
    // there n coins available and x is the sum we need to create.
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
    // let's look at the recursive approach.
    /* cout << coinCombination1(x,coins) << endl; */

    // lets memoize this recursive function 
    vector<ll> dpM(x+1,-1);
    cout << "Memo ans : " << coinCombination1Memo(x,coins,dpM) << endl;

    // moving on to the bottom up approach 
    vector<ll> dpT(x+1,-1);
    dpT[0] = 1;
    for(int i = 1;i <= x; i++ ){
        ll ans = 0;
        for(auto z: coins){
            if(i-z >=0){
                ans += dpT[i-z];
                ans %= 1000000007;
            }
        }
        dpT[i] = ans;
    }
    cout << "Bottom up ans : " << dpT[x] << endl;

}
