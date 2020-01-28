// Problem Name: Weird Function
// Problem Link: https://www.spoj.com/problems/WEIRDFN/

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
int main() 
{
	fast_io;
	Test
	{
	    ll a,b,c,n,i,s=1,f;
	    cin>>a>>b>>c>>n;
	    priority_queue <ll> mx;
	    priority_queue <ll,vector<ll>,greater<ll>> mn;
	    mx.push(1);
	    for(i=2;i<=n;i++)
	    {
	        f=(a*mx.top()+b*i+c)%MOD;
	        s+=f;
	        if(f<mx.top())
	        {
	            mn.push(mx.top());
	            mx.pop();
	            mx.push(f);
	        }
	        else mn.push(f);
	        if(i&1) mx.push(mn.top()),mn.pop();
	    }
	    cout<<s<<ln;
	}
	return 0;
}
