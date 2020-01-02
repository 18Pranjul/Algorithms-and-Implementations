// Problem Name: Petya and the Road Repairs
// Problem Link: https://www.spoj.com/problems/IITWPC4I/

#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <cstring>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <utility>
#include <iomanip>
#include <climits>
using namespace std;
#define ll long long
#define MOD 1000000007
#define MAX 1000000000000000000
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define vll vector<ll>
#define sll stack<ll>
#define qll queue<ll>
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct edge
{
    ll u,v,d;
};
bool cmp(edge e1,edge e2)
{
    return e1.d<e2.d;
}
ll root(ll s[],ll a)
{
    while(s[a]!=a)
    {
        s[a]=s[s[a]];
        a=s[a];
    }
    return a;
}
void Union(ll s[],ll z[],ll a,ll b)
{
    if(z[b]) s[a]=b;
    else s[b]=a;
}
ll kruskal(edge e[],ll k,ll n,ll a[],vll &v)
{
    ll i,m=0;
    for(i=1;i<=n;i++) if(!a[i]) m++;
    ll s[n+5];
    for(i=1;i<=n;i++) s[i]=i;
    for(i=0;i<k;i++)
    {
        ll x=root(s,e[i].u);
        ll y=root(s,e[i].v);
        if(x!=y && a[x]+a[y]!=2)
        {
            v.pb(i);
            Union(s,a,x,y);
        }
    }
    return m;
}
int main() 
{
	fast_io;
	ll n,i,j,k;
	Test
	{
	    cin>>n>>k;
	    ll a[n+5];
	    edge e[k+5];
	    for(i=1;i<=n;i++) cin>>a[i];
	    for(i=0;i<k;i++) cin>>e[i].u>>e[i].v>>e[i].d;
	    sort(e,e+k,cmp);
	    vll v;
	    ll m=kruskal(e,k,n,a,v);
	    ll ans=0;
	    if(v.size()<m) cout<<"impossible\n";
	    else
	    {
	        for(i=0;i<m;i++) ans+=e[v[i]].d;
	        cout<<ans<<ln;
	    }
	}
	return 0;
}
