#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
#define elif else if
#define ALL(x) x.begin(),x.end()
#define lowbit(x) (x&(-x))
using namespace std;
void fileio(const string &s)
{
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
const int INF=4e18;
inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}
int n,q,pri[1000001],num[1000001],ans[200001];
vector<int> v;
vector<array<int,2>> a[200001];
array<int,3> qry[200001];
const int N=450;
bool cmp(array<int,3>x,array<int,3>y)
{
	if(x[0]/N==y[0]/N)
	{
		if((x[0]/N)&1)
			return x[1]>y[1];
		else
			return y[1]>x[1];
	}
	return x[0]<y[0];
}
signed main()
{
	for(int i=2;i<=1000000;i++)
	{
		if(!pri[i])
			v.push_back(i);
		for(int l:v)
		{
			if(i*l>1000000)
				break;
			pri[i*l]=1;
			if(i%l==0)
				break;
		}
	}
	n=read();
	q=read();
	for(int i=1;i<=n;i++)
	{
		int x=read();
		for(int l:v)
		{
			if(l*l>x)
				break;
			if(x%l==0)
			{
				int num=0;
				while(x%l==0)
				{
					num++;
					x/=l;
				}
				a[i].push_back({l,num});
			}
		}
		if(x!=1)
			a[i].push_back({x,1});
	}
	for(int i=1;i<=q;i++)
	{
		int x=read(),y=read();
		qry[i]={x,y,i};
	}
	sort(qry+1,qry+1+q,cmp);
	int no=0;
	for(int i=qry[1][0];i<=qry[1][1];i++)
		for(auto l:a[i])
			num[l[0]]+=l[1];
	for(int i:v)
		if(num[i]%3)
			no++;
	ans[qry[1][2]]=no;
	int L=qry[1][0],R=qry[1][1];
	for(int i=2;i<=q;i++)
	{
		while(L>qry[i][0])
		{
			L--;
			for(auto l:a[L])
			{
				if(num[l[0]]%3)
					no--;
				num[l[0]]+=l[1];
				if(num[l[0]]%3)
					no++;
			}
		}
		while(R<qry[i][1])
		{
			R++;
			for(auto l:a[R])
			{
				if(num[l[0]]%3)
					no--;
				num[l[0]]+=l[1];
				if(num[l[0]]%3)
					no++;
			}
		}
		while(L<qry[i][0])
		{
			for(auto l:a[L])
			{
				if(num[l[0]]%3)
					no--;
				num[l[0]]-=l[1];
				if(num[l[0]]%3)
					no++;
			}
			L++;
		}
		while(R>qry[i][1])
		{
			for(auto l:a[R])
			{
				if(num[l[0]]%3)
					no--;
				num[l[0]]-=l[1];
				if(num[l[0]]%3)
					no++;
			}
			R--;
		}
		ans[qry[i][2]]=no;
	}
	for(int i=1;i<=q;i++)
		if(ans[i])
			puts("No");
		else
			puts("Yes");
	return 0;
}
