// Problem Name: Many Chefs
// Problem Link: https://www.codechef.com/problems/MANYCHEF
// We will start filling the string with substring "CHEF" from last in order to make it finally lexicographically smaller.

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
bool eq(char a,char b)
{
    if(a=='?' || a==b) return 1;
    return 0;
}
int main() 
{
	fast_io;
	TEST
	{
	    string s,s1;
	    ll n,i;
	    cin>>s;
	    n=s.size();
	    for(i=n-4;i>=0;i--)
	    {
	        if(eq(s[i],'C')&& eq(s[i+1],'H')&& eq(s[i+2],'E') && eq(s[i+3],'F'))
	        {
	            s[i]='C';
	            s[i+1]='H';
	            s[i+2]='E';
	            s[i+3]='F';
	        }
	    }
	    for(i=0;i<n;i++) if(s[i]=='?') s[i]='A';
	    cout<<s<<ln;
	}
	return 0;
}
