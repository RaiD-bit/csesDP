#include<bits/stdc++.h>
using namespace std;
#define ll long long 

ll coinCombination2(ll x, ll pos, vector<ll> &coins){
    if(x == 0){
        /* cout << "done " << endl; */
        return 1;
    }
    ll ans = 0;
    for(int i = pos; i < coins.size(); i++){
        if(x - coins[i]>=0){
            /* cout << coins[i] << " "; */
            ans += coinCombination2(x-coins[i],i,coins);
        }
        /* ans += coinCombination2(x-coins[i], pos+1,coins); */
    }
    return ans;
}

ll coinCombination2Memo(ll x, ll pos, vector<ll> &coins, vector<vector<ll>> &dp){
    if(dp[pos][x] != -1)
        return dp[pos][x];
    if(x == 0)
        return dp[pos][x] = 1;
    if(pos == 0)
        return 0;
    if(coins[pos-1] > x){
        dp[pos][x] = coinCombination2Memo(x,pos-1,coins,dp)%1000000007;
        return dp[pos][x];
    }
    dp[pos][x] = (coinCombination2Memo(x,pos-1,coins,dp) + coinCombination2Memo(x - coins[pos-1],pos,coins,dp))%1000000007;
    return dp[pos][x];
}

int main(){
    // n is the number of coins and x is the sum we need to make.
    ll n, x;
    cin >> n >> x;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++){
        cin >> coins[i];
    }
    // let's see the recursive way
    //cout << coinCombination2(x,0,coins) << endl;
    // let's now memoize the recursive function.
    vector<vector<ll>> dpM(coins.size()+1,vector<ll> (x+1,-1));
    /* cout << "memoized ans : " << coinCombination2Memo(x,coins.size(),coins,dpM) << endl; */
    /* for(auto i : dpM){ */
    /*     for(auto j: i) */
    /*         cout << j << " "; */
    /*     cout << endl; */
    /* } */
    
    vector<ll> dpT(x+1,0);
    dpT[0] = 1;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j <=x; j++){
            if(j - coins[i] >= 0){
                dpT[j] += dpT[j-coins[i]];
                dpT[j] %= 1000000007;
            }
        }
    }
    cout << "bottom-up ans : " << dpT[x]  << endl;

}
