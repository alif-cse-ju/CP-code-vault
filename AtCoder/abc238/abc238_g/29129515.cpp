#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ll long long

template<typename temp>using ordered_set = tree<temp, null_type, less<temp>, rb_tree_tag,tree_order_statistics_node_update>;
//order_of_key(k)  : Number of items strictly smaller than k .
//find_by_order(k) : K-th element in a set (counting from zero).//*(ost.find_by_order(k))

//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};

const int M=2e5+5;
const int N=2e6+5;
const int mod=1e9+7;

inline int read()
{
	int x=0;
	bool flag=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')flag=0;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return (flag?x:~(x-1));
}

array<int,3>q[M];
vector<int>primes;
vector<array<int,2>>divCnt[N];
int k=450,a[M],ans[M],cnt[N],mark[N];

bool Compare(array<int,3>&x,array<int,3>&y)
{
	if(x[0]/k  ==  y[0]/k)
	{
		if((x[0]/k) & 1)return x[1] > y[1];
		else return y[1] > x[1];
	}
	return x[0] < y[0];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,l=0,m,n=N/2,ok=0,r,x,y;

    for(i=2;i<=1000000;i++)
	{
		if(!mark[i])primes.emplace_back(i);
		for(int it : primes)
		{
			if(i*it > 1000000)break;
			mark[i*it]=1;
			if(i%it == 0)break;
		}
	}

    n=read(), m=read();
    for(i=0; i<n; i++)
    {
        a[i]=read(), x=a[i];
        if(!divCnt[x].empty())continue;
        for(int it : primes)
        {
            if(it*it > x  ||  !mark[x])break;
            if(x%it == 0)
            {
                y=0;
                while(x%it == 0)x/=it, ++y;
                divCnt[a[i]].push_back({it,y});
            }
        }
        if(x > 1)divCnt[a[i]].push_back({x,1});
    }
    for(i=0; i<m; i++)x=read(), y=read(), q[i]={x-1,y-1,i};
    sort(q,q+m,Compare);
    l=q[0][0], r=l-1;
    for(i=0; i<m; i++)
    {
        while(l > q[i][0])
        {
            x=a[--l];
            for(auto it : divCnt[x])
            {
                if(cnt[it[0]]%3)--ok;
                cnt[it[0]] += it[1];
                if(cnt[it[0]]%3)++ok;
            }
        }
        while(r < q[i][1])
        {
            x=a[++r];
            for(auto it : divCnt[x])
            {
                if(cnt[it[0]]%3)--ok;
                cnt[it[0]] += it[1];
                if(cnt[it[0]]%3)++ok;
            }
        }
        while(l < q[i][0])
        {
            x=a[l++];
            for(auto it : divCnt[x])
            {
                if(cnt[it[0]]%3)--ok;
                cnt[it[0]] -= it[1];
                if(cnt[it[0]]%3)++ok;
            }
        }
        while(r > q[i][1])
        {
            x=a[r--];
            for(auto it : divCnt[x])
            {
                if(cnt[it[0]]%3)--ok;
                cnt[it[0]] -= it[1];
                if(cnt[it[0]]%3)++ok;
            }
        }
        ans[q[i][2]]=ok;
    }
    for(i=0; i<m; i++)
    {
        if(ans[i])printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}