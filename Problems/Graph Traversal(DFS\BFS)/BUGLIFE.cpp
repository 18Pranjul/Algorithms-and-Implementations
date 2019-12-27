// Problem Name: A Bug’s Life
// Problem Link: https://www.spoj.com/problems/BUGLIFE/

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
	ll k=1;
	Test
	{
	    ll n,i,m;
	    cin>>n>>m;
	    vll v[n+5];
	    ll vis[n+5]={0},c[n+5],ans=1;
	    qll q;
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
	         q.push(i);
	         c[i]=0;
	         vis[i]=1;
	         while(q.size())
	         {
	             ll z=q.front();
	             q.pop();
	             for(ll j=0;j<v[z].size();j++)
	             {
	                 ll y=v[z][j];
	                 if(vis[y] && c[y]==c[z])
	                 {
	                     cout<<"Scenario #"<<k++<<":\nSuspicious bugs found!\n";
	                     goto end;
	                 }
	                 if(!vis[y]) vis[y]=1,q.push(y),c[y]=c[z]^1;
	             }
	         }
	     }
	    cout<<"Scenario #"<<k++<<":\nNo suspicious bugs found!\n";
	    end:;
	}
	return 0;
}
