// Problem: Maximum XOR Secondary
// Problem Link: https://codeforces.com/contest/281/problem/D

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
int main() 
{
	fast_io;
	ll n,i,mx=0;
	cin>>n;
	ll a[n+5];
	for(i=0;i<n;i++) cin>>a[i];
	stack <ll> st;
	st.push(a[0]);
	for(i=1;i<n;i++)
	{
	    while(st.size() && a[i]>st.top()) mx=max(mx,a[i]^st.top()), st.pop();
	    if(st.size()) mx=max(mx,a[i]^st.top());
	    st.push(a[i]);
	}
	cout<<mx;
	return 0;
}
