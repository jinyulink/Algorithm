#include<bits/stdc++.h>
using namespace std;
int a[5]={2,3,8,6,1};
int main()
{
	int t=1;
	cout<<"0: ";
	for(int i=0;i<5;i++)	cout<<a[i]<<' ';
	cout<<'\n';
	for(int i=1;i<5;i++)
	{
		int j=i;
		while(j>0&&a[j-1]>a[j])
		{
			swap(a[j-1],a[j]);
			j--;
			//cout<<t++<<": ";
			//cout<<"i: "<<i<<" j: "<<j<<' ';
			//for(int kk=0;kk<5;kk++)	cout<<a[kk]<<' ';
			//cout<<'\n';
		}
	}
	return 0;
}
