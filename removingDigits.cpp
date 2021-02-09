#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll removeDigitsRec(ll n)
{
    if(n == 0)
        return 0;
    vector<ll> digits;
    ll z = n;
    while(z){
        digits.push_back(z%10);
        z/=10;
    }
    ll ans = INT_MAX;
    for(auto x: digits){
        if(x == 0)
        continue;
        if(n - x >= 0){
            ans = min(ans, removeDigitsRec(n-x)+1);
        }
    }
    return ans;

}

ll removeDigitsMemo(ll n, vector<ll> &dp)
{
    if(dp[n] != -1)
        return dp[n];
    if(n == 0)
        return 0;
    vector<ll> digits;
    ll z = n;
    while(z){
        digits.push_back(z%10);
        z/=10;
    }
    ll ans = INT_MAX;
    for(auto x: digits){
        if(x == 0)
        continue;
        if(n - x >= 0){
            ans = min(ans, removeDigitsMemo(n-x,dp)+1);
        }
    }
    return dp[n] = ans;

}

int main(){
    ll n;
    cin >> n;
    // cout << removeDigitsRec(n) << endl;
    vector<ll> dpM(n+1,-1);
    // cout << "memo ans : " << removeDigitsMemo(n,dpM) << endl;
    // cout << removeDigitsMemo(n,dpM) << endl;

    // now tabular method

    vector<ll> dpT(n+1,INT_MAX);
    dpT[0] = 0;

    for(int i = 1; i<=n; i++)
    {
        vector<ll> digit;
        ll z = i;
        while(z){
            digit.push_back(z%10);
            z/=10;
        }
        for(auto x: digit){
            if(i - x >= 0){
                dpT[i] = min(dpT[i], dpT[i-x] + 1);
            }
        }
    }

    cout << dpT[n] << endl;

}
