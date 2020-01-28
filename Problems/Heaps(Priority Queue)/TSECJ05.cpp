// Problem Name: Chef and his software
// Problem Link: https://www.codechef.com/problems/TSECJ05

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
	    ll n,i,k,a;
	    cin>>k>>n;
	    priority_queue <ll,vector<ll>,greater<ll>> mn;
	    for(i=0;i<n;i++) 
	    {
	        cin>>a;
	        if(mn.size()<k) mn.push(a);
	        else if(mn.top()<a) mn.pop(),mn.push(a);
	        cout<<(mn.size()<k?-1:mn.top())<<" ";
	    }
	    cout<<ln;
	}
	return 0;
}
