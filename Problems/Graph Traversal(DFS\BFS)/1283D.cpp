// Problem Name: Christmas Trees
// Problem Link: https://codeforces.com/contest/1283/problem/D

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
map <ll,ll> d,used;
int main() 
{
	fast_io;
	ll n,m,i;
	cin>>n>>m;
	ll a,ans=0;
	vll p;
	qll q;
	for(i=0;i<n;i++) 
	{
	    cin>>a;
	    q.push(a);
	    d[a]=0;
	    used[a]=1;
	}
	while(q.size())
	{
	    if((ll)(p.size())==m) break;
	    ll t=q.front();
	    q.pop();
	    if(d[t]!=0)
	    {
	        ans+=d[t];
	        p.pb(t);
	    }
	    if(!d.count(t-1))
	    {
	        d[t-1]=d[t]+1;
	        q.push(t-1);
	        used[t-1]=1;
	    }
	    if(!d.count(t+1))
	    {
	        d[t+1]=d[t]+1;
	        q.push(t+1);
	        used[t+1]=1;
	    }
	    if((ll)(p.size())==m) break;
	}
	sort(p.begin(),p.end());
	cout<<ans<<ln;
	for(i=0;i<m;i++) cout<<p[i]<<" ";
	return 0;
}
