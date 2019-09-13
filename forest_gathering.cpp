#include<iostream>
using namespace std;
unsigned long long int fun(unsigned int *a,unsigned int *b,unsigned long long int l,unsigned long long int mid,int n)
{
	unsigned long long int sum=0;
	for(int i=0;i<n;i++)
	{
		if(a[i]+b[i]*mid>l)
		sum+=a[i]+b[i]*mid;
	}
	return sum;
}
int main()
{
	int n;
	unsigned long long int w,l1;
	cout<<"Enter the no. of trees:";
	cin>>n;
	cout<<"Enter the amount of wood required:";
	cin>>w;
	cout<<"Enter the minimum length of tree after which it can be used:";
	cin>>l1;
	unsigned int h[n],r1[n];
	cout<<"Enter the height and rate of growth of tree:";
	for(int i=0;i<n;i++)
	cin>>h[i]>>r1[i];
	unsigned long long int l=0,r=1000000000000000000;
	unsigned long long int ans;
	while(l<=r)
	{
		unsigned long long int mid=(l+r)/2;
		if((fun(h,r1,l1,mid,n))>=w)
		{
			ans=mid;
			r=mid-1;
		}
		else
		l=mid+1;
	}
	cout<<"No. of months are "<<ans<<endl;
	return 0;
}
