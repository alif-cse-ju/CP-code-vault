#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int lb = 19;

mt19937_64 gen((unsigned long long)new char ^ time(0));

inline ull mul(ull x,ull y)
{
	ull res = 0;
	if(x&1) res = y;
	for(int i=1; i<64; ++i) if((x>>i)&1)
		res ^= (y << i) ^ (y >> (64 - i));
	return res;
}

ull a[MAXN];
tuple<int,int,int,int,int,int> qs[MAXN];

ull pwb[lb], f[MAXN][lb];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i)
		scanf("%llu",&a[i]);
	
	for(int i=1; i<=Q; ++i)
	{
		int l1, r1, l2, r2, l3, r3;
		scanf("%d%d%d%d%d%d",&l1,&r1,&l2,&r2,&l3,&r3);
		
		int len1 = r1 - l1 + 1;
		int len3 = r3 - l3 + 1;
		
		qs[i] = make_tuple(l1, l2, l3, len1, len3, min(len1, len3));
	}
	
	for(int rn=1; rn<=1; ++rn)
	{
		for(int i=0; i<lb; ++i)
			pwb[i] = gen();
		for(int i=n; i>=1; --i)
		{
			f[i][0] = a[i];
			for(int j=1; i+(1<<j)-1<=n; ++j)
				f[i][j] = mul(f[i][j-1], pwb[j-1]) ^ f[i+(1<<(j-1))][j-1];
		}
		for(int i=1; i<=Q; ++i)
		{
			int i1, i2, i3, len1, len3, res;
			tie(i1, i2, i3, len1, len3, res) = qs[i];
			
			int cur = 0;
			for(int j=lb-1; j>=0; --j)
				if(cur + (1<<j) <= res && (f[i1][j] ^ f[i2][j]) == f[i3][j])
					cur += 1<<j, i1 += 1<<j, i2 += 1<<j, i3 += 1<<j;
			
			get<5>(qs[i]) = cur;
		}
	}
	
	for(int i=1; i<=Q; ++i)
	{
		int i1, i2, i3, len1, len3, res;
		tie(i1, i2, i3, len1, len3, res) = qs[i];
		
		if(res<len1 && res<len3)
		{
			if((a[i1+res] ^ a[i2+res]) < a[i3+res])
				printf("Yes\n");
			else
				printf("No\n");
		}
		else
		{
			if(res<len3)
				printf("Yes\n");
			else
				printf("No\n");
		}
	}
	return 0;
}