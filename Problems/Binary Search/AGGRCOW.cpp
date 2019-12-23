// Problem Name: Aggressive cows
// Problem Link: https://www.spoj.com/problems/AGGRCOW/

#include <bits/stdc++.h>
void merge(long long int a[],long long int l,long long int m,long long int r)
{
    long long int i,j,k,n1,n2;
    n1=m-l+1;
    n2=r-m;
    long long int L[n1],R[n2];
    for(i=0;i<n1;i++)
     L[i]=a[l+i];
    for(j=0;j<n2;j++)
     R[j]=a[m+1+j];
    i=j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<R[j])
         a[k++]=L[i++];
        else
         a[k++]=R[j++];
    }
    while(i<n1)
     a[k++]=L[i++];
    while(j<n2)
     a[k++]=R[j++];
}
void mergeSort(long long int a[],long long int l,long long int r)
{
    if(l<r)
    {
        long long int mid=(l+r)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
long long int cow(long long int c,long long int x,long long int a[],long long int n){
    long long int i,cowpos=1,lastpos=a[0];
    for(i=1;i<n;i++){
        if(a[i]-lastpos>=x){
            cowpos++;
            lastpos=a[i];
            if(cowpos==c)
            return 1;
        }
    }
    return 0;
}
int main() {
	long long int t,n,c,i,p,j,k;
	scanf("%lld",&t);
	while(t--){
	    scanf("%lld%lld",&n,&c);
	    long long int a[n];
	   for(i=0;i<n;i++)
	   scanf("%lld",&a[i]);
	   mergeSort(a,0,n-1);
	   p=a[n-1]-a[0];
	   long long int u=p,l=0,mid;
	   while(u-l>1){
	       mid=l+(u-l)/2;
	       if(cow(c,mid,a,n)==1)
	       l=mid;
	       else
	       u=mid;
	   }
	   printf("%lld\n",l);
	}
	return 0;
} 
