// A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time.
// Implement a method to count how many possible ways the child can run up to the stairs.
// You need to return all possible number of ways.
#include<iostream>
using namespace std;
long count_stair(int n)
{
  long* output=new long[n+1];
  output[0]=1;
  output[1]=1;
  output[2]=2;
  for(int i=3;i<n+1;i++)
  {
    output[i]=output[i-1]+output[i-2]+output[i-3];
  }
  return output[n];
}
int main()
{
  int n;
  cin>>n;
  int ans=count_stair(n);
  cout<<ans;
  return 0;
}
