// Problem Name: The lazy programmer
// Problem Link: https://www.spoj.com/problems/LAZYPROG/

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
struct data
{
    ll a,b,d;
};
bool cmp(data k1,data k2)
{
    if(k1.d==k2.d) return k1.a>k2.a;
    return k1.d<k2.d;
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,tm=0;
	    double m=0.0;
	    cin>>n;
	    data k[n+5];
	    for(i=0;i<n;i++) cin>>k[i].a>>k[i].b>>k[i].d;
	    sort(k,k+n,cmp);
	    priority_queue <pll> pq;
	    for(i=0;i<n;i++)
	    {
	        pq.push({k[i].a,k[i].b});
	        if(tm+k[i].b<=k[i].d) tm+=k[i].b;
	        else
	        {
	            l:;
	            pll z=pq.top();
	            pq.pop();
	            if(z.s<k[i].b-k[i].d+tm)
	            {
	                m+=(z.s/(z.f*1.0));
	                k[i].b-=z.s;
	                goto l;
	            }
	            else
	            {
	                m+=((k[i].b-k[i].d+tm)/(z.f*1.0));
	                z.s-=(k[i].b-k[i].d+tm);
	                tm=k[i].d;
	            }
	            if(z.s) pq.push(z);
	        }
	    }
	    cout<<fixed<<setprecision(2)<<m<<ln;
	}
	return 0;
}
