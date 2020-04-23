// Given an integer N, find and return the count of unique Binary search trees (BSTs) are
// possible with nodes valued from 1 to N.
// Output count can be very large, so return the count modulo 10^9+7.
#include<bits/stdc++.h>
using namespace std;
int countBST( int n)
{
   long long int mod=pow(10,9)+7;
    long long int *dp=new long long int[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(long long int k=0;k<i;k++)
        {
            long res=dp[k]*1l*dp[i-k-1];
            int temp=(int)(res%mod);
            dp[i]=(dp[i]+temp)%mod;
        }
    }
    int ans=dp[n];
    delete [] dp;
    return ans;

}
int main()
{
  int n;
  cin>>n;
  int ans=countBST(n);
  cout<<ans;
  return 0;
}
