#include<iostream>
using namespace std;
int student_count(int *arr,int n,int mid)
{
	int sum=0,count=1;
	for(int i=0;i<n;i++)
	{
		sum+=arr[i];
		if(sum>mid)
		{
			sum=arr[i];
			count++;
		}
	}
	return count;
}
int main()
{
	int n,x;
	cout<<"Enter the no. of books";
	cin>>n;
	int ar[n];
	cout<<"Enter the no. of pages in books:\n";
	for(int i=0;i<n;i++)
	cin>>ar[i];
	cout<<"Enter the no. of students:";
	cin>>x;
	int max=0,sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=ar[i];
		if(ar[i]>max)
		max=ar[i];
	}
	int l=max;
	int r=sum;
	int ans;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(student_count(ar,n,mid)<=x)
		{
			ans=mid;
			r=mid-1;
		}
		else
		l=mid+1;
	}
	cout<<"No. of maximum pages that should be allocated to a student is "<<ans<<endl;
	return 0;
}
