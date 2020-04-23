// Given a set of n integers, find if a subset of sum k can be formed from the given set.
// Print Yes or No.
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    bool** dp=new bool*[n+1];
    for(int i=0;i<=n;i++)
    {
        dp[i]=new bool[k+1];
    }
    for(int i=0;i<n+1;i++)
    {
        dp[i][0]=true;
    }
    for(int j=1;j<k+1;j++)
    {
        dp[0][j]=false;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<k+1;j++)
        {
            dp[i][j]=dp[i-1][j];
            if(j>=arr[i-1])
            {
                dp[i][j]|=dp[i-1][j-arr[i-1]];
            }
        }
    }
    bool ans=dp[n][k];
    if(ans)
    cout<<"Yes";
    else
        cout<<"No";
    return 0;
}
