#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll diceCombinationRec(ll n)
{
    if(n == 0)
        return 1;
    ll ans = 0;
    for(int i = 1; i <= 6; i++)
    {
        if(n-i >= 0)
            ans +=  diceCombinationRec(n - i);

    }
    return ans;

}

ll diceCombinationMemo(ll n, vector<ll> &dp)
{
   if(dp[n] != -1)
       return dp[n];
   if(n == 0)
       return 1;
   int ans = 0;
   for(int i = 1; i <= 6; i++)
   {
       if(n - i >= 0)
           ans += diceCombinationMemo(n-i,dp);
   }
   return dp[n] = ans;
}

int main()
{
    // n denotes the sum we need to create
    ll n; 
    cin >> n;
    // lets us try the recursive approach first
    cout <<"ans through normal recursion is : " <<  diceCombinationRec(n) << endl;
    // lets us memoize the recursive approach
    vector<ll> dp(n+1,-1);
    cout <<"ans through memoized recursion(top down) is : " <<diceCombinationMemo(n,dp) << endl;
    // let us see the bottom up approach
    vector<ll> dp1(n+1,-1);
    dp1[0] = 1;
    dp1[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        ll ans = 0;
        for(int j = 1; j <= 6; j++)
        {
            if(i-j>=0)
            {
                ans += dp1[i-j];
            }
        }
        dp1[i] = ans;
    }
    cout <<"ans through memoized recursion(bottom up) is : " << dp1[n] << endl;
}
