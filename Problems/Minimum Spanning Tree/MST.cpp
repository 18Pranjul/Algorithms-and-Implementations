// Problem Name: Minimum Spanning Tree
// Problem Link: https://www.spoj.com/problems/MST/


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
struct SET
{
    ll p;
    ll r;
};
bool cmp(edge e1,edge e2)
{
    return e1.d<e2.d;
}
ll root(SET s[],ll a)
{
    if(s[a].p!=a)
     s[a].p=root(s,s[a].p);
    return s[a].p;
}
void Union(SET s[],ll a,ll b)
{
    if(s[a].r<s[b].r) s[a].p=b;
    else if(s[a].r>s[b].r) s[b].p=a;
    else s[a].p=b,s[b].r++;
}
void kruskal(edge e[],ll k,ll n,vll &v)
{
    ll i;
    SET s[n+5];
    for(i=0;i<=n;i++) s[i].p=i,s[i].r=0;
    for(i=0;i<k;i++)
    {
        ll x=root(s,e[i].u);
        ll y=root(s,e[i].v);
        if(x!=y)
        {
            v.pb(i);
            Union(s,x,y);
        }
    }
}
int main() 
{
	fast_io;
	ll n,i,j,k;
	cin>>n>>k;
	edge e[k+5];
	for(i=0;i<k;i++) cin>>e[i].u>>e[i].v>>e[i].d;
	sort(e,e+k,cmp);
	vll v;
	kruskal(e,k,n,v);
	ll ans=0;
	for(i=0;i<v.size();i++) ans+=e[v[i]].d;
	cout<<ans;
	return 0;
}
