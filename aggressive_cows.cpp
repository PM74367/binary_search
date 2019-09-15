#include<bits/stdc++.h>
using namespace std;
int cow_no(int *ar,int n,int c,int dis)
{
	int i,prev=ar[0],temp=1;
	for(i=1;i<n;i++)
	{
		int cur=ar[i];
		if((cur-prev)>=dis)
		{
			temp++;
			prev=ar[i];
			if(temp==c)
			{
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int stalls,cows,i=0;
	cout<<"Enter no. of stalls:";
	cin>>stalls;
	int loc[stalls];
	cout<<"Enter location of skills:\n";
	for(i=0;i<stalls;i++)
		cin>>loc[i];
	sort(loc,loc+stalls);
	cout<<"Enter no. of cows:";
	cin>>cows;
	int l=1;
	int r=loc[stalls-1]-loc[0];
	int res=-1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(cow_no(loc,stalls,cows,mid))
		{
			res=mid;
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	cout<<"Largest minimum distance is "<<res<<endl;
	return 0;
}
