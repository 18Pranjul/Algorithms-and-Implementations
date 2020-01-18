// Problem Name: Fast roads
// Problem Link: https://www.codechef.com/ALPAST01/problems/FASTROAD

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
	    ll n,m,u,v,i;
	    double T;
	    cin>>n>>m>>u>>v;
	    vector <pair<double,ll>> adj[n+5];
	    for(i=0;i<m;i++)
	    {
	        ll a,b,sp,l;
	        cin>>a>>b>>l>>sp;
	        T=l/(sp*1.0);
	        adj[a].pb({T,b});
	        adj[b].pb({T,a});
	    }
	    double tm[n+5];
	    for(i=1;i<=n;i++) tm[i]=MAX*1.0;
	    tm[u]=0.0;
	    priority_queue<pair<double,ll>,vector<pair<double,ll>>,greater<pair<double,ll>>> pq;
	    pq.push({tm[u],u});
	    while(pq.size() && pq.top().s!=v)
	    {
	        pair<double,ll> z=pq.top();
	        pq.pop();
	        for(i=0;i<adj[z.s].size();i++)
	        {
	            if(tm[adj[z.s][i].s]>tm[z.s]+adj[z.s][i].f)
	            {
	                tm[adj[z.s][i].s]=tm[z.s]+adj[z.s][i].f;
	                pq.push({tm[adj[z.s][i].s],adj[z.s][i].s});
	            }
	        }
	    }
	    if(tm[v]==MAX) cout<<"-1\n";
	    else cout<<fixed<<setprecision(10)<<tm[v]<<ln;
	}
	return 0;
}
