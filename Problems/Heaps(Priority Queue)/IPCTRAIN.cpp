// Problem Name: IPC Trainers
// Problem Link: https://www.codechef.com/JULY17/problems/IPCTRAIN

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
struct trainer
{
    ll d,t,s;
};
void siftUp(trainer heap[],ll j)
{
    if(j<=0) return ;
    ll par=(j-1)/2;
    if((heap[par].t && heap[j].t && heap[par].s<heap[j].s) || heap[par].t==0)
    {
        swap(heap[par],heap[j]);
        siftUp(heap,par);
    }
}
void siftDown(trainer heap[],ll i,ll n)
{
    ll l=2*i+1,r=2*i+2,par=i;
    if(l<=n && ((heap[par].t && heap[l].t && heap[par].s<heap[l].s) || !heap[par].t)) 
     par=l;
    if(r<=n && ((heap[par].t && heap[r].t && heap[par].s<heap[r].s) || !heap[par].t)) 
     par=r;
    if(par!=i)
    {
        swap(heap[par],heap[i]);
        siftDown(heap,par,n);
    }
    
}
void makeHeap(trainer heap[],vector<pll> v[],ll d,ll j)
{
    ll i;
    for(i=0;i<v[d].size();i++)
    {
        heap[i+j].t=v[d][i].f;
        heap[i+j].s=v[d][i].s;
        siftUp(heap,i+j);
    }
}
int main() 
{
	fast_io;
	TEST
	{
	    ll n,D,i,sad=0,j=0;
	    cin>>n>>D;
	    trainer tr[n+5];
	    for(i=0;i<n;i++) cin>>tr[i].d>>tr[i].t>>tr[i].s;
	    
	    vector <pll> v[D+5];
	    for(i=0;i<n;i++) v[tr[i].d].pb({tr[i].t,tr[i].s});
	    
	    trainer heap[n+5];
	    for(i=1;i<=D;i++)
	    {
	        makeHeap(heap,v,i,j);
	        j+=v[i].size();
	        if(j>0)
	        {
	            if(heap[0].t>0)
	            {
	                heap[0].t--;
	                swap(heap[0],heap[j-1]);
	                siftDown(heap,0,j-2);
	                siftUp(heap,j-1);
	            }
	        }
	    }
	    for(i=0;i<j;i++) 
	     if(heap[i].t>0) sad+=heap[i].t*heap[i].s;
	    cout<<sad<<ln;
	}
	return 0;
}
