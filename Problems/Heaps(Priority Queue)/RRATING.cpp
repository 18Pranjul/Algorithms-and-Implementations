// Problem Name: Restaurant Rating
// Problem Link: https://www.codechef.com/problems/RRATING

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
	ll n,c,i,m=0,ans;
	cin>>n;
	priority_queue <ll> mx;
	priority_queue <ll,vector<ll>,greater<ll>> mn;
	while(n--)
	{
	    cin>>c;
	    if(c-1)
	    {
	        if(mn.size()) cout<<mn.top()<<ln;
	        else cout<<"No reviews yet\n";
	    }
	    else
	    {
	        cin>>c;
	        m++;
	        if(mn.size() && mn.top()<c)
	        {
	            mx.push(mn.top());
	            mn.pop();
	            mn.push(c);
	        }
	        else mx.push(c);
	        if(!(m%3)) mn.push(mx.top()),mx.pop();
	    }
	}
	return 0;
}
