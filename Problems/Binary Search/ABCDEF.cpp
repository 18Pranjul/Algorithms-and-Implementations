// Problem Name: ABCDEF
// Problem Link: https://www.spoj.com/problems/ABCDEF/

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
    ll l=0,r=n-1,c=0,j;
    while(l<=r)
    {
        ll m=(l+r)/2;
        if(a[m]==x)
        {
            j=m-1;
            while(j>=0 && a[j]==a[m]) c++,j--;
            j=m;
            while(j<n && a[j]==a[m]) c++,j++;
            //cout<<c<<ln;
            return c;
        }
        else if(a[m]>x) r=m-1;
        else l=m+1;
    }
    return c;
}
void print(ll a[],ll n)
{
    if(n==0) cout<<a[n]<<" ";
    else 
    {
        print(a,n-1);
        cout<<a[n]<<" ";
    }
}
int main() 
{
	fast_io;
	ll n,a[105],m,i,j,k,l;
	cin>>n;
	m=n*n*n;
	ll la[m+5],ra[m+5];
	for(i=0;i<n;i++) cin>>a[i];
	l=0;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  for(k=0;k<n;k++)
	   la[l++]=a[i]*a[j]+a[k];
	l=0;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
	  for(k=0;k<n;k++)
	   if(a[k]) ra[l++]=(a[i]+a[j])*a[k];
	sort(la,la+m); sort(ra,ra+l);
	//print(la,m-1);cout<<ln;print(ra,m-1);cout<<ln;
	ll ans=0;
	for(i=0;i<m;)
	{
	    ll c=0;
	    j=la[i];
	    while(i<m && la[i]==j) i++,c++;
	    //cout<<j<<","<<c<<"->";
	    //i++;
	    ans+=(c*bs(ra,l,j));
	    //cout<<ln;
	}
	cout<<ans;
	return 0;
}
