// Problem Name: Galactik Football 
// Problem Link: https://www.codechef.com/problems/GALACTIK
// Code: 
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
#define f first
#define s second
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll root(ll s[],ll a)
{
    while(s[a]!=a)
    {
        s[a]=s[s[a]];
        a=s[a];
    }
    return a;
}
void Union(ll s[],ll a,ll b,ll w[])
{
    ll ra=root(s,a);
    ll rb=root(s,b);
    if(ra!=rb)
    {
        if(w[ra]<w[rb]) s[rb]=ra;
        else s[ra]=rb;
    }
}
int main() 
{
	fast_io;
	ll n,m,i;
	cin>>n>>m;
	ll s[n+5],a[m+5],b[m+5],w[n+5];
	for(i=1;i<=n;i++) s[i]=i;
	for(i=0;i<m;i++) cin>>a[i]>>b[i];
	for(i=1;i<=n;i++) 
	{
	    cin>>w[i];
	    if(w[i]<0) w[i]=MAX;
	}
	for(i=0;i<m;i++) Union(s,a[i],b[i],w);
	vector <ll> v;
	ll f=1,mn=MAX;
	for(i=1;i<=n;i++) 
	 if(s[i]==i)
	 {
	     if(w[i]==MAX) f=0;
	     v.pb(w[i]);
	     mn=min(mn,w[i]);
	 }
	if(!f && v.size()>1) cout<<"-1";
	else
	{
	    ll sum=0;
	    for(i=0;i<v.size();i++) sum+=v[i];
	    sum+=(mn*(v.size()-2));
	    cout<<sum;
	}
	return 0;
}
