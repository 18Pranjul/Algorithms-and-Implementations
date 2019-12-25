// Problem Name: Inversion Count
// Problem Link: https://www.spoj.com/problems/INVCNT/

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
void update(ll BIT[],ll n,ll i)
{
    while(i<=n)
    {
        BIT[i]++;
        i+=(i&-i);
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
ll bs(ll a[],ll n,ll x)
{
    ll l=0,r=n-1,m;
    while(l<=r)
    {
        m=l+(r-l)/2;
        if(a[m]==x) return m;
        else if(a[m]>x) r=m-1;
        else l=m+1;
    }
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i;
	    cin>>n;
	    ll a[n+5],BIT[n+5]={0},b[n+5],s=0;
	    for(i=0;i<n;i++) cin>>a[i],b[i]=a[i];
	    sort(b,b+n);
	    for(i=0;i<n;i++)
	    {
	        ll p=bs(b,n,a[i])+1;
	        s+=query(BIT,n)-query(BIT,p);
	        update(BIT,n,p);
	    }
	    cout<<s<<ln;
	}
	return 0;
} 
