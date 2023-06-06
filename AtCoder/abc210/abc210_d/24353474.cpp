#include<bits/stdc++.h>
#define N 1005
#define M 5001
#define R register
#define x first
#define y second
#define ll long long
#define db double
#define mp make_pair
#define pb push_back
#define pi pair<int,int>
#define lb(x) (x&-x)
#define mod 998244353
#define wt(x) write(x),puts("")
#define ot(x) write(x),putchar(' ')
#define INF 0x7fffffffffffffff
#define F(i,start,end) for(R int (i)=(start);(i)<=(end);i++)
#define T(i,end,start) for(R int (i)=(start);(i)>=(end);i--)
using namespace std;
template<typename T> void read(T &x)
{
	int f=1;
	x=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<3)+(x<<1)+c-'0';
		c=getchar();
	}
	x*=f;
	return;
}
void write(R ll x)
{
	if(x<0)
	{
		x=~x+1;
		putchar('-');
 	}
	if(x>9)
		write(x/10);
	putchar(x%10+'0');
	return;
}
int n,m;
ll ans=INF,c,f[N][N],v[N][N],a[N][N];
ll dis(int x,int y,int a,int b)
{
	return abs(x-a)+abs(y-b);
}
int main()
{
	read(n),read(m),read(c);
	F(i,1,n)
		F(j,1,m)
			read(a[i][j]),v[i][j]=1ll*c*dis(1,1,i,j)-a[i][j];
	memset(f,0xcf,sizeof(f));
	F(i,1,n)
		F(j,1,m)
		{
			ans=min(ans,1ll*c*dis(1,1,i,j)+a[i][j]-max(f[i-1][j],f[i][j-1]));
			f[i][j]=max(max(f[i-1][j],f[i][j-1]),v[i][j]);
		}
	F(i,1,n)
		F(j,1,m)
			v[i][j]=1ll*c*dis(1,m,i,j)-a[i][j];
	memset(f,0xcf,sizeof(f));
	F(i,1,n)
		T(j,1,m)
		{
			ans=min(ans,1ll*c*dis(1,m,i,j)+a[i][j]-max(f[i-1][j],f[i][j+1]));
			f[i][j]=max(max(f[i-1][j],f[i][j+1]),v[i][j]);
		}
	wt(ans);
	return 0;
}