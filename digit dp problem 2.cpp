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
how many zero are there from A to B?
*/
ll  fun2(int i, bool is_small, string &str,vector<vl>&dp2)
{
    if(i==si(str)) return 1;
    if(dp2[i][is_small]!=-1) return dp2[i][is_small];
    ll lo=0,ans=0,hi=str[i]-'0';
    for(int j=lo; j<=hi; j++)
    {
        ans+=fun2(i+1,is_small|(j<str[i]-'0'),str,dp2);
    }
    return dp2[i][is_small]=ans;
}
ll f(int i, bool is_small, bool non_zero, string &str, vector<vector<vl>>&dp1 ,vector<vl>&dp2 )
{
    if(i==si(str))
    {
        return 0;
    }
    if(dp1[i][is_small][non_zero]!=-1) return dp1[i][is_small][non_zero];
    ll lo=0,ans=0,hi=str[i]-'0';
    if(is_small) hi=9;
    for(int j=lo; j<=hi; j++)
    {
        ans+=f(i+1,is_small|(j<str[i]-'0'),non_zero|(j>0),str,dp1,dp2);
        if(non_zero and j==0) ans+=fun2(i+1,is_small,str,dp2);
    }
    return dp1[i][is_small][non_zero]=ans;

}

ll fun(int n)
{
    vector<vector<vl>>dp1(11,vector<vl>(2,vl(2,-1)));
    vector<vl>dp2(11,vl(2,-1));
    string str=to_string(n);
    ll ans=f(0,0,0,str,dp1,dp2);
    return ans;
}
void solve()
{
    ll a, b;
    cin>>a>>b;
    ll ans=fun(b)-fun(a-1);
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