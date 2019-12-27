// Problem Name: Prime Path
// Problem Link: https://www.spoj.com/problems/PPATH/

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
void sieve(ll *pr)
{
    for(ll i=2;i<=9999;i++)
     if(!pr[i]) 
      for(ll j=2*i;j<=9999;j+=i) pr[j]=1;
}
int main() 
{
	fast_io;
	ll k=1;
	Test
	{
	    ll a,b,i,vis[10005]={0},lvl[10005],pr[10005]={0},j;
	    pr[0]=pr[1]=1;
	    cin>>a>>b;
	    vll v[10005];
	    sieve(pr);
	    for(i=1000;i<=9999;i++) lvl[i]=MAX;
	    qll q;
	    q.push(a);
	    vis[a]=1;
	    lvl[a]=0;
	    while(q.size())
	    {
	        ll z=q.front();
	        q.pop();
	        for(i=0;i<4;i++)
	        {
	            ll m=z-((z/(ll)pow(10,i))%10)*pow(10,i);
	            for(j=0;j<10;j++)
	            {
	                if(i==3 && j==0) continue;
	                ll r=m+j*pow(10,i);
	                if(!vis[r] && !pr[r])
	                {
	                    q.push(r);
	                    vis[r]=1;
	                    lvl[r]=lvl[z]+1;
	                }
	            }
	        }
	    }
	    if(lvl[b]==MAX) cout<<"Impossible\n";
	    else cout<<lvl[b]<<ln;
	}
	return 0;
} 
