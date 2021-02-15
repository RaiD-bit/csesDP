#include<bits/stdc++.h>
using namespace std;
#define ll long long 

// ll bookShopRec(ll n, ll x, vector<ll> &h, vector<ll> &s){
//     if(x == 0){
//         return 0;
//     }
//     if(n == 0){
//         return 0;
//     }
//     ll ans = INT_MIN;
//     if(x - h[n-1] >=0){
//         ans = max(bookShopRec(n-1, x - h[n-1],h,s) + s[n-1],bookShopRec(n-1,x,h,s));
//     }
//     else {
//         ans = bookShopRec(n-1,x,h,s);
//     }
//     return ans;
// }

ll bookShopMemo(ll n, ll x, vector<int> &h, vector<int> &s, vector<vector<int>> &dp){
    if(dp[n][x] != INT_MIN)
        return dp[n][x];
    if(x == 0){
        return dp[n][x] = 0;
    }
    if(n == 0){
        return dp[n][x] = 0;
    }
    ll ans = INT_MIN;

    if(x - h[n-1] >=0){
        ans = max(bookShopMemo(n-1, x - h[n-1],h,s,dp) + s[n-1],bookShopMemo(n-1,x,h,s,dp));
    }
    else {
        ans = bookShopMemo(n-1,x,h,s,dp);
    }
    return dp[n][x] = ans;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    ll n,x;
    cin >> n >> x;
    vector<int> s(n), h(n);
    for(int i = 0; i<n; i++)
    {
        cin >> h[i];
    }   

    for(int i = 0; i<n; i++)
    {
        cin >> s[i];
    }

    // lets look at the recursive solution.
    // cout << bookShopRec(n,x,h,s) << endl;

    // moving on to memoization.
    vector<vector<int>> dpM(n+1,vector<int>(x+1,INT_MIN));
    cout << bookShopMemo(n,x,h,s, dpM) << endl;
    // -> memoized approach gives TLE. seems like the limits are tight.
    // vector<vector<int>> dpT(n+1,vector<int>(x+1,0));

    // for(int i = 0; i<=n; i++){
    //     for(int j = 0; j <= x; j++){
    //         if(i == 0 || j == 0)
    //         {
    //             dpT[i][j] = 0;
    //         }
    //         else{
    //             if(h[i-1] > j)
    //                 dpT[i][j] = dpT[i-1][j];
    //             else
    //                 dpT[i][j] = max(dpT[i-1][j-h[i-1]] + s[i-1], dpT[i-1][j]);
    //         }                
    //     }
    // }

    // cout << dpT[n][x] << endl;

}
