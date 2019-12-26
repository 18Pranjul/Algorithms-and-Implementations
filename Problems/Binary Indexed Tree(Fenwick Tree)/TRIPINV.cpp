// Problem Name: Mega Inversions
// Problem Link: https://www.spoj.com/problems/TRIPINV/

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
#define mp make_pair
#define f first
#define s second
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll bs(ll a[],ll n,ll x)
{
    ll l=0,r=n-1,m;
    while(l<=r)
    {
        m=(l+r)/2;
        if(a[m]==x) return m;
        a[m]<x?l=m+1:r=m-1;
    }
}
ll query(ll BIT[],ll i)
{
    ll s=0;
    while(i>0)
    {
        s+=BIT[i];
        i-=(i&-i);
    }
    return s;
}
void update(ll BIT[],ll n,ll i,ll c)
{
    while(i<=n)
    {
        BIT[i]+=c;
        i+=(i&-i);
    }
}
int main() 
{
	fast_io;
	ll n,i;
	cin>>n;
	ll a[n+5],b[n+5],BIT1[n+5]={0},BIT2[n+5]={0},ans=0;
	for(i=0;i<n;i++) cin>>a[i],b[i]=a[i];
	sort(b,b+n);
	for(i=0;i<n;i++)
	{
	    ll p=bs(b,n,a[i])+1;
	    update(BIT2,n,p,1);
	}
	for(i=0;i<n;i++)
	{
	    ll p=bs(b,n,a[i])+1,x,y;
	    x=query(BIT1,n)-query(BIT1,p);
	    y=query(BIT2,p-1);
	    ans+=(x*y);
	    update(BIT1,n,p,1);
	    update(BIT2,n,p,-1);
	}
	cout<<ans;
	return 0;
}
