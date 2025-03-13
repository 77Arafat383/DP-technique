//**************BISMILLAHIR RAHMANIR RAHIM****************
//*******************Md Yeasin Arafat****************
#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // *v.find_by_order(x)=xth position e ki ache , v.order_of_key(x)==x theke kotota choto ache
typedef tree<int, null_type, greater<int>, rb_tree_tag, tree_order_statistics_node_update> dpbds; //decending order
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> mpbds; // work like a multiset
//tuple  ---> get<0>(v[i]) , get<1>(v[i]) get<2>(v[i]) to access three tuple value
#define check cout<<'?'<<endl;
#define    ll               long long
const int M =  1e9+7;
const ll bM =  998244353;
const ll INF =  1e18;
#define    all(x)           x.begin(), x.end()
#define    pi               acos(-1.00)
#define rev(v) reverse(all(v));
#define rsort(v) sort(v.rbegin(),v.rend());
#define taking(a)  for(auto &it:a) cin>>it;
#define printv(a)  for(auto &it:a) cout<<it<<' '; cout<<'\n'
#define printm(a)  for(auto &[x,y]:a) cout<<x<<' '<<y<<'\n'
#define printmv(a) for(auto [x,v]:a) {cout<<x<<'\n'; printv(v);}
#define bitcount(x) __builtin_popcount(x)
#define si(x) int(x.size())
#define vl vector<ll>
#define vll vector<pair<ll,ll>>
#define Mp map<ll,ll>
#define MV map<ll,vl>
const int N=1e5;
 

/*
using next array I also store path of longest subsequence. 
next array te next move store kore rakhbo. 
tarpor seta diye jeta jetar jonno palindrome hoyce sei position gula nibo.. then sei position er 
character gula diye string banabo. setai longest subsequenc of palindrom hobe. 
*/

ll f(int i, int j, string &str, vector<vl>&dp)
{
    if(i==j) return 1;
    if(i>j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    if(str[i]==str[j]) dp[i][j]=f(i+1,j-1,str,dp)+2;
    else 
    {
        dp[i][j]=max(f(i+1,j,str,dp),f(i,j-1,str,dp));
    }
    return dp[i][j];
}


void solve()
{
    string str;
    cin>>str;
    int n=si(str);
    vector<vl>dp(n+1,vl(n+1,-1));
    ll ans=f(0,n-1,str,dp);
    cout<<ans<<'\n';
}


signed main()
{
 ios_base::sync_with_stdio(false) , cin.tie(NULL);
int ttt=1;
//cin>>ttt;
for(int tt=1; tt<=ttt; tt++) 
{
//cout<<"Case #"<<tt<<": ";
solve();
}
    return 0;
}