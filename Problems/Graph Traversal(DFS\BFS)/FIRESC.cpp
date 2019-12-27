// Problem Name: Fire Escape Routes
// Problem Link: https://www.codechef.com/problems/FIRESC

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
void dfs(vll v[],ll vis[],ll a,ll *c)
{
    vis[a]=1;
    (*c)++;
    for(ll i=0;i<v[a].size();i++)
    {
        ll b=v[a][i];
        if(!vis[b]) dfs(v,vis,b,c);
    }
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,m;
	    cin>>n>>m;
	    vll v[n+5];
	    ll vis[n+5]={0},c=0,ans=1,c1;
	    for(i=0;i<m;i++)
	    {
	        ll a,b;
	        cin>>a>>b;
	        v[a].pb(b);
	        v[b].pb(a);
	    }
	    for(i=1;i<=n;i++) 
	     if(!vis[i])
	     {
	         c++;
	         c1=0;
	         dfs(v,vis,i,&c1);
	         ans=(ans*c1)%MOD;
	     }
	    cout<<c<<" "<<ans<<ln;
	}
	return 0;
}
