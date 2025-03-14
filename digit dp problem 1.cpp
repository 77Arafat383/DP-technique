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
How many integers within the range A to B have digit sum X? 
*/
ll f(int i, bool ok,int sum,int &x,string &str, vector<vector<vl>>&dp)
{
    if(i==si(str))
    {
        return (sum==x);
    }
    if(dp[i][ok][sum]!=-1) return dp[i][ok][sum];
    int hi=str[i]-'0';
    if(ok) hi=9;
    dp[i][ok][sum]=0;
    for(int j=0; j<=hi; j++)
    {
        ll nw=(ok|(j<hi));
        dp[i][ok][sum]+=f(i+1,nw,sum+j,x,str,dp);
       
    }
    return dp[i][ok][sum];
}
ll cal(int n,int x)
{
    string str=to_string(n);
    rev(str);
    for(int i=si(str); i<=9; i++) str.push_back('0');
    rev(str);
  //  cout<<str<<' ';
    vector<vector<vl>>dp(si(str)+1,vector<vl>(2,vl(1000,-1)));
    ll ans=f(0,0,0,x,str,dp);
   // cout<<ans<<'\n';
    return ans;

}

void solve()
{
    ll a,b,x;
    cin>>a>>b>>x;
    ll ans=cal(b,x)-cal(a-1,x);
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