// Problem Name: 4 values whose sum is 0
// Problem Link: https://www.spoj.com/problems/SUMFOUR/

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
ll BS(ll* f,ll k,ll x)
{
    ll l=0,r=k-1,m=l+(r-l)/2,c=0;
    while(r>=l)
    {
        m=l+(r-l)/2;
        if(f[m]==x)
        {
            ll t=m-1;
            c=1;
            while(t>=0 && f[t]==x) c++,t--;
            t=m+1;
            while(t<k && f[t]==x) c++,t++;
            return c;
        }
        else if(f[m]>x) r=m-1;
        else l=m+1;
    }
    return c;
}
int main() 
{
	fast_io;
	ll n,i,j;
	cin>>n;
	ll a[n+5],b[n+5],c[n+5],d[n+5],e[(n*n)+5],f[(n*n)+5],k=0;
	for(i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i]>>d[i];
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  e[k]=a[i]+b[j],f[k++]=(c[i]+d[j])*(-1);
	sort(e,e+k);
	sort(f,f+k);
	ll ans=0,k1=0,k2=0;
	for(i=0;i<k;)
	{
	    k1=0;
	    ll t=e[i];
	    while(i<k && e[i]==t) k1++,i++;
	    k2=BS(f,k,t);
	    ans+=(k1*k2);
	}
	cout<<ans;
	return 0;
}
