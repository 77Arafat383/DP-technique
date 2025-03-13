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

ll f(int pos, vector<tuple<ll,ll,ll>>&v , vector<ll>&dp)
{
    if(pos==si(v))
    {
        return 0;
    }
    if(dp[pos]!=-1)  return dp[pos];
    dp[pos]=f(pos+1,v,dp);
    tuple<ll,ll,ll>tem={get<1>(v[pos]),0,0};
    int n_pos=upper_bound(all(v),tem)-v.begin();
   return  dp[pos]=max(dp[pos],f(n_pos,v,dp)+get<2>(v[pos]));

}


void solve()
{
    ll n;
    cin>>n;
    vector<tuple<ll,ll,ll>>v(n);
    for(int i=0; i<n; i++)
    {
        int l,r,w;
        cin>>l>>r>>w;
        v[i]={l,r,w};
    }
    sort(all(v));
    vector<ll>dp(n+1,-1);
    ll ans=f(0,v,dp);
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