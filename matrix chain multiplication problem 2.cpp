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
  Find maximum possible value of this expression after inserting paranthesis. -  included;
*/

ll f(int b, int e, bool mx,string &str, vector<vector<vl>>&dp)
{
    if(b==e) return str[b]-'0';
    if(dp[b][e][mx]!=-1) return dp[b][e][mx];
    ll ans=INT_MIN;
    if(!mx) ans=INT_MAX;
    for(int i=b+1; i<e; i+=2)
    {
        if(mx)
        {
            if(str[i]=='*')
            {
                ans=max(ans,f(b,i-1,mx,str,dp)*f(i+1,e,mx,str,dp));
            }
            else if(str[i]=='+')
            {
                ans=max(ans,f(b,i-1,mx,str,dp)+f(i+1,e,mx,str,dp));
            }
            else
            {
                ans=max(ans,f(b,i-1,mx,str,dp)-f(i+1,e,0,str,dp));
            }
        }
        else
        {
            if(str[i]=='*')
            {
                ans=min(ans,f(b,i-1,mx,str,dp)*f(i+1,e,mx,str,dp));
            }
            else if(str[i]=='+')
            {
                ans=min(ans,f(b,i-1,mx,str,dp)+f(i+1,e,mx,str,dp));
            }
            else
            {
                ans=min(ans,f(b,i-1,mx,str,dp)-f(i+1,e,1,str,dp));
            }
        }
    }
    return dp[b][e][mx]=ans;

}

void solve()
{
    string str;
    cin>>str;
    int n=si(str);
    vector<vector<vl>>dp(n+1,vector<vl>(n+1,vl(2,-1)));
    ll ans=f(0,n-1,1,str,dp);
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