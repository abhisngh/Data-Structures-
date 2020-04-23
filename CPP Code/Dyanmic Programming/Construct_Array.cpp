// Your goal is to find the number of ways to construct an array such that consecutive positions contain different values.
// Specifically, we want to construct an array with n elements such that each element between 1 and k, inclusive.
// We also want the first and last elements of the array to be 1  and x.
//
#include<bits/stdc+.h>
using namespace std;
#define MOD 1000000007
long count(int n,int k,int x)
{
  long onecount=1;
  long nononecount=0;
  for(int i=2;i<=n;i++)
  {
    long temp1=nononecount*(k-1);
    long temp2=onecount+nononecount*(k-2);
    onecount=temp1%MOD;
    nononecount=temp2%MOD;
  }
  if(x==1)
  {
    return onecount;
  }
  return nononecount;
}
int main()
{
  int n,k,x;
  cin>>n>>k>>x;
  cout<<count(n,k,x);
  return 0;
}
