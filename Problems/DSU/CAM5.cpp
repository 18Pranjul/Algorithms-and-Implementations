// Problem Name: prayatna PR
// Problem Link: https://www.spoj.com/problems/CAM5/

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
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define Test ll t;cin>>t; while(t--)
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);
ll find(ll *par,ll a)
{
    while(a!=par[a]) a=par[a]=par[par[a]];
    return a;
}
void Union(ll *par,ll *size,ll a,ll b)
{
    a=find(par,a);
    b=find(par,b);
    if(size[a]<size[b]) par[a]=b;
    else if(size[b]<size[a]) par[b]=a;
    else par[b]=a,size[a]++;
}
int main() 
{
	fast_io;
	Test
	{
	    ll n,i,q;
	    cin>>n>>q;
	    ll par[n+5],size[n+5]={0},c=0;
	    for(i=0;i<n;i++) par[i]=i;
	    while(q--)
	    {
	        ll a,b;
	        cin>>a>>b;
	        Union(par,size,a,b);
	    }
	    for(i=0;i<n;i++) if(i==par[i]) c++;
	    cout<<c<<ln;
	}
	return 0;
} 
