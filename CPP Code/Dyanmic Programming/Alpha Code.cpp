#include<iostream>
using namespace std;
int mod=1000000007;
int num_codes(string arr,int size)
{
	int* output=new int[size+1]{0};

	output[0]=1;
	for(int i=1;i<size;i++)
	{
		int temp1=(arr[i-1]-'0')*10;
		int temp2=arr[i]-'0';
		if(arr[i]!='0')
		{
			output[i]=output[i-1];
		}
		if(temp1+temp2<=26 && i>1 && temp1+temp2>=10)
		{
			output[i]+=output[i-2];
		}
		else if(temp1+temp2<=26 && temp1+temp2>=10)
		{
			output[i]++;
		}
		output[i]=output[i]%mod;

	}
	int ans=output[size-1];
	delete [] output;
	return ans;

}
int main()
{
	string s;
	do
	{
		cin>>s;
		if(s=="0")
		{
			break;
		}
		int output=num_codes(s,s.size());
		cout<<output<<endl;
	}while(s!="0");
	return 0;

}
