// Problem Name: Makx Sum
// Problem Link: https://www.codechef.com/problems/KSUBSUM

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
int main() 
{
	fast_io;
	Test
	{
	    ll n,k1,k2,k3,i,j;
	    cin>>n>>k1>>k2>>k3;
	    ll a[n+5],ps[n+5];
	    ps[0]=0;
	    for(i=0;i<n;i++) cin>>a[i], ps[i+1]=ps[i]+a[i];
	    priority_queue <int,vector<int>,greater<int>> q;
	    for(i=1;i<=n;i++)
	    {
	        for(j=0;j<i;j++)
	        {
	            ll z=ps[i]-ps[j];
	            if(q.size()<k3) q.push(z);
	            else if(z>q.top()) q.pop(),q.push(z);
	        }
	    }
	    ll ans[k3+5];
	    j=k3;
	    while(q.size()) ans[j--]=q.top(),q.pop();
	    cout<<ans[k1]<<" "<<ans[k2]<<" "<<ans[k3]<<ln;
	}
	return 0;
}
