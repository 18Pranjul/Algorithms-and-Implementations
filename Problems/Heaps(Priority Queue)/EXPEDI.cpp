// Problem Name: Expedition
// Problem Link: https://www.spoj.com/problems/EXPEDI/

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
bool cmp(pll x,pll y)
{
    return x.s<y.s;
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,a,b;
	    cin>>n;
	    pll p[n+5];
	    for(i=0;i<n;i++) 
	    {
	        cin>>a>>b;
	        p[i]={b,a};
	    }
	    priority_queue <pll> pq;
	    cin>>a>>b;
	    for(i=0;i<n;i++) p[i].s=a-p[i].s;
	    sort(p,p+n,cmp);
	    p[n]={0LL,a};
	    ll d=0,ans=0;
	    for(i=0;i<=n;i++)
	    {
	        l:;
	        if(d+b<p[i].s)
	        {
	            if(pq.empty()) 
	            {
	                ans=-1;
	                break;
	            }
	            ans++;
	            b+=pq.top().f;
	            pq.pop();
	            goto l;
	        }
	        else b-=(p[i].s-d),d=p[i].s;
	        pq.push(p[i]);
	    }
	    cout<<ans<<ln;
	}
	return 0;
}
