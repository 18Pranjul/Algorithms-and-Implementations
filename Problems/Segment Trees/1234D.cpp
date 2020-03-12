// Problem Name: Distinct Characters Queries
// Problem Link: https://codeforces.com/contest/1234/problem/D

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
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll tree[300005];
void build(string s,ll l,ll r,ll i)
{
    if(l==r)
    {
        tree[i]=1<<(s[l]-'a');
        return ;
    }
    ll m=l+(r-l)/2;
    build(s,l,m,2*i+1);
    build(s,m+1,r,2*i+2);
    tree[i]=tree[2*i+1] | tree[2*i+2];
}
void update(ll p,char c,ll l,ll r,ll i)
{
    if(l==r) 
    {
        tree[i]=1<<(c-'a');
        return ;
    }
    ll m=l+(r-l)/2;
    (p<=m) ? update(p,c,l,m,2*i+1) : update(p,c,m+1,r,2*i+2);
    tree[i] = tree[2*i+1] | tree[2*i+2];
}
ll query(ll x,ll y,ll l,ll r,ll i)
{
    if(l>=x && r<=y) return tree[i];
    if(y<l || x>r) return 0;
    ll m=l+(r-l)/2;
    return query(x,y,l,m,2*i+1) | query(x,y,m+1,r,2*i+2);
}
int main() 
{
	fast_io;
	string s;
	cin>>s;
	ll n=s.size(),q,i;
	build(s,0,n-1,0);
	cin>>q;
	while(q--)
	{
	    ll x;
	    cin>>x;
	    if(x==1)
	    {
	        ll p;
	        char c;
	        cin>>p>>c;
	        update(p-1,c,0,n-1,0);
	    }
	    else
	    {
	        ll l,r,c=0;
	        cin>>l>>r;
	        cout<<__builtin_popcount(query(l-1,r-1,0,n-1,0))<<ln;
	    }
	}
	//cout<<s;
	return 0;
}
