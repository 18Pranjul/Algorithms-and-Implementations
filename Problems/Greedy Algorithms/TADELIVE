// Problem Name: Delivery Man
//Problem Link: https://www.codechef.com/problems/TADELIVE

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
#define TEST ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
struct tll
{
    ll a;
    ll b;
    ll m;
};
bool cmp(tll a,tll b)
{
    return a.m>b.m;
}
int main()
{
	fast_io;
	ll n,x,y,i;
	cin>>n>>x>>y;
	ll a[n+5],b[n+5];
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<n;i++) cin>>b[i];
	vector <tll> v;
	for(i=0;i<n;i++)
	{
	    tll t;
	    t.a=a[i];
	    t.b=b[i];
	    t.m=abs(a[i]-b[i]);
	    v.pb(t);
	}
	sort(v.begin(),v.end(),cmp);
	ll max=0;
	for(i=0;i<n;i++)
	{
	    if(v[i].a>v[i].b)
	    {
	        if(x>0)
	        {
	            max+=v[i].a;
	            x--;
	        }
	        else
	        {
	            max+=v[i].b;
	            y--;
	        }
	    }
	    if(v[i].a<v[i].b)
	    {
	        if(y>0)
	        {
	            max+=v[i].b;
	            y--;
	        }
	        else
	        {
	            max+=v[i].a;
	            x--;
	        }
	    }
	    if(v[i].a==v[i].b)
	    {
	        if(x>y)
	        {
	            max+=v[i].a;
	            x--;
	        }
	        else
	        {
	            max+=v[i].b;
	            y--;
	        }
	    }
	}
	cout<<max;
	return 0;
}
