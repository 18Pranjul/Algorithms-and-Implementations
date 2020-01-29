// Problem Name: Capital Movement
// Problem Link: https://www.codechef.com/problems/CAPIMOVE

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
int main() 
{
	fast_io;
	Test
	{
	    ll n,i;
	    cin>>n;
	    ll p[n+5];
	    priority_queue <pll> pq;
	    map <ll,ll> mp;
	    mp[0]=0;
	    for(i=1;i<=n;i++) cin>>p[i],pq.push({p[i],i}),mp[p[i]]=i;
	    vll v[n+5];
	    for(i=1;i<n;i++)
	    {
	        ll a,b;
	        cin>>a>>b;
	        v[a].pb(b);
	        v[b].pb(a);
	    }
	    ll ans[n+5];
	    for(i=1;i<=n;i++) ans[i]=pq.top().f;
	    while(pq.size())
	    {
	        pll z=pq.top();
	        pq.pop();
	        ll k=pq.size()?pq.top().f:0;
	        if(ans[z.s]==z.f) ans[z.s]=k;
	        for(i=0;i<v[z.s].size();i++) if(ans[v[z.s][i]]==z.f) ans[v[z.s][i]]=k;
	    }
	    for(i=1;i<=n;i++) cout<<mp[ans[i]]<<" ";
	}
	return 0;
}
