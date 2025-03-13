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
Given a string S, |S|<10, and distinct. and integer d. how many permutation of s possible Which is divisible by d. 
*/
ll f(int mask, int value, int &d, string &str, vector<vl>&dp)
{
    int pos=bitcount(mask);
    if(pos==si(str))
    {
        return (value==0);
    }
    if(dp[mask][value]!=-1) return dp[mask][value];
    dp[mask][value]=0;
    for(int i=0; i<si(str); i++)
    {
        if(!(mask&(1<<i)))
        {
            dp[mask][value]+=f(mask|(1<<i), (value*10+str[i]-'0')%d, d, str, dp);
        }
    }
    return dp[mask][value];
}

void solve()
{
    string str;
    int d;
    cin>>str>>d;
    int n=si(str);
    vector<vl>dp((1<<n)+1,vl(d+1,-1));
    ll ans=f(0,0,d,str,dp);
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