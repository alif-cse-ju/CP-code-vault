#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
const int N=3e5+10,LG=18,p=998244353;
int n,q,a[N],f[LG][2][2];
void solve(int o){
	Rof(i,(1<<n)-1,0)if(!(i>>o&1)){
		int x=a[i],y=a[i^(1<<o)];
		a[i]=(f[o][0][0]*x+f[o][1][0]*y)%p;
		a[i^(1<<o)]=(f[o][0][1]*x+f[o][1][1]*y)%p;
	}
}
signed main(){
	n=read(),q=read();
	For(i,0,(1<<n)-1)a[i]=read();
	For(i,0,n-1)f[i][0][0]=f[i][1][1]=1;
	while(q--){
		int x=read(),y=read();
		if(y==1){//1->0
			(f[x][0][0]+=f[x][0][1])%=p,(f[x][1][0]+=f[x][1][1])%=p;
		}else{//0->1
			(f[x][0][1]+=f[x][0][0])%=p,(f[x][1][1]+=f[x][1][0])%=p;
		}
	}For(i,0,n-1)solve(i);
	For(i,0,(1<<n)-1)printf("%lld ",a[i]);
	return 0;
}