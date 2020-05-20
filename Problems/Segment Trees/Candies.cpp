// Problem Name: Candies
// Problem Link: https://codingcompetitions.withgoogle.com/kickstart/round/000000000019ff43/0000000000337b4d

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define pb push_back
#define pll pair<ll,ll>
#define ppll pair<ll,pll>
#define vll vector<ll>
#define vpll vector<pll>
#define vvll vector<vector<ll>>
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
#define init(x,n,v) for(ll i=0;i<=n;i++) x[i]=v;
#define all(x) x.begin(),x.end()
#define pi 3.14159265358979323846
ll MOD = 1e9+7 , MAX = 1e18;
ll n,q;
void upd(vll &a,ll p,ll v)
{
    a[p+=n]=v;
    for(p/=2;p;p/=2) a[p]=a[2*p]+a[2*p+1];
}
ll query(vll &a,ll l,ll r)
{
    ll ans=0;
    for(l+=n , r+=(n+1);l<r;l/=2,r/=2)
    {
        if(l&1) ans+=a[l++];
        if(r&1) ans+=a[--r];
    }
    return ans;
}
int main() 
{
	fast_io;
	ll x=1;
	Test
	{
	    cout<<"Case #"<<x++<<": ";
	    ll i,a,l,r;
	    cin>>n>>q;
	    vll add(2*n+10,0),odd(2*n+10,0),even(2*n+10,0);
	    for(i=1;i<=n;i++) 
	    {
	        cin>>a;
	        if(i&1) upd(add,i,i*a) , upd(odd,i,a);
	        else upd(add,i,-i*a) , upd(even,i,a);
	    }
	    a=0;
	    while(q--)
	    {
	        char c;
	        cin>>c>>l>>r;
	        if(c=='U')
	        {
	            if(l&1) upd(add,l,l*r) , upd(odd,l,r);
	            else upd(add,l,-l*r) , upd(even,l,r);
	        }
	        else
	        {
	            i=query(add,l,r);
	            if(!(l&1)) 
	            {
	                i*=-1;
	                i-=((l-1)*query(even,l,r));
	                i+=((l-1)*query(odd,l,r));
	            }
	            else
	            {
	                i-=((l-1)*query(odd,l,r));
	                i+=((l-1)*query(even,l,r));
	            }
	            a+=i;
	        }
	    }
	    cout<<a<<ln;
	}
	return 0;
}
