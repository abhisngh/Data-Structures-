#include<iostream>
using namespace std;
int lis(int* arr,int size)
{
  int* output=new int[size];

  output[0]=1;
  for(int i=1;i<size;i++)
  {
  	output[i]=1;
    for(int j=i-1;j>=0;j--)
    {
      if(arr[j]>arr[i])
      {
        continue;
      }
      int possible_ans=output[j]+1;
      if(possible_ans>output[i])
      {
        output[i]=possible_ans;
      }
    }
  }
  int ans=0;
  for(int i=0;i<size;i++)
  {
  	if(ans<output[i])
  	{
  	ans=output[i];
	}
  }
  delete [] output;
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
  int ans=lis(arr,n);
  cout<<ans;
  delete [] arr;
}
