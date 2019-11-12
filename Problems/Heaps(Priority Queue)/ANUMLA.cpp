// Problem Name: Mahesh and his lost array
// Problem Link: https://www.codechef.com/problems/ANUMLA
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
	    ll n,k,i,j;
	    cin>>n;
	    ll a[n+5];
	    k=1<<n;
	    multiset <ll> s;
	    vector <ll> v;
	    for(i=0;i<k;i++)
	    {
	        ll a;
	        cin>>a;
	        if(a) s.insert(a);
	    }
	    for(i=0;i<n;i++)
	    {
	        a[i]=*s.begin();
	        v.pb(a[i]);
	        s.erase(s.find(a[i]));
	        ll z=v.size()-1;
	        for(j=0;j<z;j++) 
	        {
	            v.pb(a[i]+v[j]);
	            s.erase(s.find(a[i]+v[j]));
	        }
	    }
	    for(i=0;i<n;i++) cout<<a[i]<<" ";
	    cout<<ln;
	}
	return 0;
}
