#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define F first
#define S second
int const M=2e5+10,mod=1e9+7,inf=1e9+10;
int ans[M],cnt[M];
string x[10];
signed main()
{
	int n;
	cin>>n;
	for(int i=1;i<=3;i++)
	{
		cin>>x[i];
		int mx=0;
		for(int j=0;j<1000;j++)cnt[j]=0;
		//cout<<(int)'a';
		for(int j=0;j<x[i].size();j++)
		{
			cnt[(int)x[i][j]]++;
			mx=max(mx,cnt[(int)x[i][j]]);
		}
		int tmp=mx+n;
		ans[i]=min((int)x[i].size(),tmp);
		if(ans[i]==(int)x[i].size())
		{
			bool flag=0;
			for(int j=0;j<x[i].size();j++)
			{
				int tmp=cnt[(int)x[i][j]];
				if(tmp+n>=(int)x[i].size())
				{
					int res=(int)x[i].size()-tmp;
					if((n-res)%2==0)flag=1;
				}
			}
			if(!flag)ans[i]--;
		}
	}
	for(int i=1;i<=3;i++)
	{
		bool flag=0;
		for(int j=1;j<=3;j++)
		{
			if(i==j)continue;
			if(ans[i]<=ans[j])flag=1;
		}
		if(!flag)
		{
			if(i==1)cout<<"Kuro";
			else if(i==2)cout<<"Shiro";
			else cout<<"Katie";
			return 0;
		}
	}
	cout<<"Draw";
}
