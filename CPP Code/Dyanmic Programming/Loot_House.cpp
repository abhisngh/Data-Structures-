// A thief wants to loot houses. He knows the amount of money in each house.
// He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
#include<bits/stdc++.h>
using namespace std;
int getMaxMoney(int arr[], int n){

    int* dp=new int[n];
	dp[0]=arr[0];
    dp[1]=std::max(arr[0],arr[1]);
    for(int i=2;i<=n-1;i++)
    {
        dp[i]=std::max(arr[i]+dp[i-2],dp[i-1]);
    }
    int ans=dp[n-1];
    delete [] dp;
    return ans;
}
int main()
{
  int n;
  cin>>n;
  int* arr=new int[n];
  for(int i=0;i<n;i++)
  {
    cin>>arr[i];
  }
  int ans=getMaxMoney(arr,n);
  cout<<ans;
  delete [] arr;
}
