// Problem Name: Running Median Again
// Problem Link: spoj.com/problems/RMID2/

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
	    ll n,m=0;
	    priority_queue <ll> mx;
	    priority_queue <ll,vector<ll>,greater<ll>> mn;
	    while(1)
	    {
	        cin>>n;
	        if(n==0) break;
	        else if(n==-1)
	        {
	            cout<<mx.top()<<ln;
	            mx.pop();
	            m--;
	            if((m+1)/2>mx.size())
	            {
	                mx.push(mn.top());
	                mn.pop();
	            }
	        }
	        else
	        {
	            m++;
	            if(mx.size() && n<mx.top())
	            {
	                mn.push(mx.top());
	                mx.pop();
	                mx.push(n);
	            }
	            else mn.push(n);
	            if((m+1)/2>mx.size()) 
	            {
	                mx.push(mn.top());
	                mn.pop();
	            }
	        }
	    }
	}
	return 0;
}
