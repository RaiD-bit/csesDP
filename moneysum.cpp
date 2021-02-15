//THINK FIRST CODE NEXT!!!!!!!!!!!!!!!!!
//It does not matter how slowly you go as long as you do not stop. - Confucius
#include<bits/stdc++.h>
using namespace std;
#define deb(x) cout << #x << ':' << x << endl;
#define loop3(i, k, n) for(i=k; i<n; i++)
#define ll  long long 
#define loop(i,n) for(int i=0;i<n;i++)
#define loop2(i,n) for(int i = 1;i<=n;i+=1)
#define pb push_back
#define mp make_pair
#define v1d vector<ll>
#define v2d vector<vector<ll>>
#define Sort(v) sort(v.begin(),v.end())
const int INF = 1e9 +5 ;
#define ll        long long
// #define mp      make_pair
#define eb         emplace_back
#define pb         push_back
#define ss         second
#define ff         first
#define IOS        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod        998244353
#define MOD        (1000*1000*1000+7)
#define MN         LLONG_MIN
#define MX         LLONG_MAX
#define v1d        vector<ll>
#define v2d        vector<vector<ll>>
#define vip        vector<pair<ll,ll> >
#define v1s        vector<string>
#define pa         pair<ll,ll>
#define mxpq(T)    priority_queue <T>
#define mnpq(T)    priority_queue<T,vector<T>,greater<T>>
#define print(v)   for(auto i:v)cout<<i<<" ";cout<<endl;
#define p2d(v)     for(auto a:v){for(auto b:a)cout<<b<<" ";cout<<endl;}
#define p1d(v)     for(auto a:v)cout<<a<<" ";cout<<endl;
#define ppd(v)     for(auto a:v)cout<<a.ff<<" "<<a.ss<<endl;
#define input(b,n) for(int i=0;i<n;i++)cin>>b[i];
#define Sort(v)    sort(v.begin(),v.end())
#define RSort(v)   sort(v.rbegin(),v.rend())
#define all(v)     v.begin(),v.end()
int gcd(int a,int b){return b?gcd(b,a%b):a;}
//string s = bitset<64>(a).to_string();
void moneySumRec(int pos,vector<int> &v, int s,set<int> &ans)
{
    if(pos == v.size()){
        if(s!=0)
        ans.insert(s);
        return ;
    }
    moneySumRec(pos+1,v,s+v[pos],ans);
    moneySumRec(pos+1,v,s,ans);
}

void moneySumRec(int pos,vector<int> &v, int s,set<int> &ans, vector<int> dp)
{
    if(pos == v.size()){
        if(s!=0)
        ans.insert(s);
        return ;
    }
    moneySumRec(pos+1,v,s+v[pos],ans);
    moneySumRec(pos+1,v,s,ans);
}


int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    loop(i,n)
    {
        cin >> v[i];
    }
    set<int> ans;
    moneySumRec(0,v,0,ans);
    cout << ans.size() << endl;
    for(auto x: ans){
        cout << x << " ";
    }
    cout << endl;
}