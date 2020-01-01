// Problem Name: The Shortest Path
// Probem Link: https://www.spoj.com/problems/SHPATH/

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
	    ll n,i,r;
	    cin>>n;
	    map <string,ll> idx;
	    string a,b;
	    vector <pll> v[n+5];
	    for(i=1;i<=n;i++)
	    {
	        cin>>a;
	        idx[a]=i;
	        ll p,nr,cst;
	        cin>>p;
	        while(p--)
	        {
	            cin>>nr>>cst;
	            v[i].pb({cst,nr});
	        }
	    }
	    cin>>r;
	    while(r--)
	    {
	        cin>>a>>b;
	        ll st=idx[a],en=idx[b],vis[n+5]={0},d[n+5];
	        for(i=1;i<=n;i++) d[i]=MAX;
	        d[st]=0;
	        priority_queue<pll,vector<pll>,greater<pll>> q;
	        q.push({0,st});
	        while(q.size() && q.top().s!=en)
	        {
	            pll z=q.top();
	            q.pop();
	            vis[z.s]=1;
	            for(i=0;i<v[z.s].size();i++)
	            {
	                pll y=v[z.s][i];
	                if(!vis[y.s] && d[y.s]>z.f+y.f) 
	                {
	                    q.push({y.f+z.f,y.s});
	                    d[y.s]=y.f+z.f;
	                }
	            }
	        }
	        cout<<d[en]<<ln;
	    }
	}
	return 0;
}
