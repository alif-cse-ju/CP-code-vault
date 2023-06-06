#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
typedef double db;
mt19937 mrand(random_device{}()); 
const ll mod=1000000007;
int rnd(int x) { return mrand() % x;}
ll powmod(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll gcd(ll a,ll b) { return b?gcd(b,a%b):a;}
// head

int n,m;
void solve() {
	scanf("%d%d",&n,&m);
	ll b=0,a=0;
	ll ans=-8e18;
	rep(i,1,n+1) {
		ll x,y;
		scanf("%lld%lld",&x,&y);
		if (x<=-1&&b>=0) {
			ll t=max(min(b/(-x),(ll)y),1ll);
			ans=max(ans,a+b*t+x*t*(t+1)/2);
		}
		ans=max(ans,a+b+x);
		a=a+b*y+x*y*(y+1)/2;
		b=b+x*y;
		ans=max(ans,a);
	}
	printf("%lld\n",ans);
}

int main() {
	int _;
	for (scanf("%d",&_);_;_--) {
		solve();
	}
}