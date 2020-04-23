// Gary is bored and wants to play an interesting but tough game . So he figured out a new board game called "destroy the neighbours" .
// In this game there are N integers on a board. In one move, he can pick any integer x from the board and then
// all the integers with value x+1 or x-1 gets destroyed .
// This move will give him x points.
// Maximum points Gary can recieve from the Game setup
#include<bits/stdc++.h>
using namespace std;
int solve(int n,vector<int>A){
  unordered_map<int,int> map;
    for(int i=0;i<A.size();i++)
    {
        map[A[i]]++;
    }
    int dp[1001];
    dp[0]=0;
    dp[1]=map[1];
    for(int i=2;i<=1000;i++)
    {
        dp[i]=max(dp[i-2]+i*map[i],dp[i-1]);
    }
    int ans=dp[1000];
    delete [] dp;
    return ans;
}
int main()
{
  int n;
  vector<int> A;
  cin>>n;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    A.push_back(x);
  }
  cout<<solve(n,A)<<endl;
  return 0;
}
