// Problem Name: Can you answer these queries III
// Problem Link: https://www.spoj.com/problems/GSS3/

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
struct tree
{
    ll s,ps,ss,ms;
};
tree findans(tree sg[],ll l,ll r,ll x,ll y,ll i)
{
    tree k;
    k.s=0;
    k.ps=k.ss=k.ms=-MAX;
    if(l>=x && r<=y) return sg[i];
    if(y<l || x>r) return k;
    ll m=(l+r)/2;
    tree lt=findans(sg,l,m,x,y,2*i+1);
    tree rt=findans(sg,m+1,r,x,y,2*i+2);
    k.s=lt.s+rt.s;
    k.ps=max(lt.ps,lt.s+rt.ps);
    k.ss=max(lt.ss+rt.s,rt.ss);
    k.ms=max(max(max(k.s,max(k.ps,k.ss)),max(lt.ms,rt.ms)),lt.ss+rt.ps);
    return k;
}
void build(tree sg[],ll a[],ll n,ll l,ll r,ll i)
{
    if(l==r) sg[i].s=sg[i].ps=sg[i].ss=sg[i].ms=a[l];
    else
    {
        ll m=(l+r)/2;
        build(sg,a,n,l,m,2*i+1);
        build(sg,a,n,m+1,r,2*i+2);
        sg[i].s=sg[2*i+1].s+sg[2*i+2].s;
        sg[i].ps=max(sg[2*i+1].ps,sg[2*i+1].s+sg[2*i+2].ps);
        sg[i].ss=max(sg[2*i+2].ss,sg[2*i+1].ss+sg[2*i+2].s);
        sg[i].ms=max(max(max(sg[2*i+1].ms,sg[2*i+2].ms),max(sg[i].s,max(sg[i].ps,sg[i].ss))),sg[2*i+1].ss+sg[2*i+2].ps);
    }
}
void update(tree sg[],ll l,ll r,ll i,ll x,ll y)
{
    if(l==r) sg[i].s=sg[i].ps=sg[i].ss=sg[i].ms=y;
    else
    {
        ll m=(l+r)/2;
        if(x<=m) update(sg,l,m,2*i+1,x,y);
        else update(sg,m+1,r,2*i+2,x,y);
        sg[i].s=sg[2*i+1].s+sg[2*i+2].s;
        sg[i].ps=max(sg[2*i+1].ps,sg[2*i+1].s+sg[2*i+2].ps);
        sg[i].ss=max(sg[2*i+2].ss,sg[2*i+1].ss+sg[2*i+2].s);
        sg[i].ms=max(max(max(sg[2*i+1].ms,sg[2*i+2].ms),max(sg[i].s,max(sg[i].ps,sg[i].ss))),sg[2*i+1].ss+sg[2*i+2].ps);
    }
}
int main() 
{
	fast_io;
	ll n,i,m,ch,x,y;
	cin>>n;
	ll a[n+5];
	for(i=0;i<n;i++) cin>>a[i];
	tree sg[3*n];
	build(sg,a,n,0,n-1,0);
	cin>>m;
	while(m--)
	{
	    cin>>ch>>x>>y;
	    if(!ch) update(sg,0,n-1,0,x-1,y);
	    else cout<<findans(sg,0,n-1,x-1,y-1,0).ms<<ln;
	}
	return 0;
}  
