#include<bits/stdc++.h>
using namespace std;
 
void __print(int x){cerr << x;}
void __print(bool x){cerr << (int)x;}
void __print(long long x){cerr << x;}
void __print(unsigned long long x){cerr << x;}
void __print(double x){cerr << x;}
void __print(long double x){cerr << x;}
void __print(char x){cerr << '\'' << x << '\'';}
void __print(const char *x){cerr << '\"' << x << '\"';}
void __print(const string &x){cerr << '\"' << x << '\"';}
 
template<typename T, typename V>
void __print(const pair<T, V> &x){cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x){int f = 0; cerr << '{'; for(auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print(){cerr << "]\n";}
template<typename T, typename... V>
void _print(T t, V... v){__print(t); if(sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

const int M = 2e5 + 3;

ll bit[M];
int sz;

void update(int idx, ll val){
    while(idx <= sz){
        bit[idx] += val;
        idx += (idx & -idx);
    }
}
    
ll query(int R){
    ll ret = 0;
    while(R > 0){
        ret += bit[R];
        R -= (R & -R);
    }
    return ret;
}

ll query(int L, int R){
    if(L > R) return 0;
    return query(R) - query(L-1);
}

ll ans[M];
vector<pii>entry[M], ext[M], qu[M];
vector<ll>tym[M], val[M];

int main(){
	
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	sz = 2e5;

	int n, m, q;
	cin >> n >> m >> q;

	for(int i=1; i<=q; i++){
		int t;
		cin >> t;
		if(t == 1){
			int l, r, x;
			cin >> l >> r >> x;
			entry[l].emplace_back(x, i);
			ext[r+1].emplace_back(x, i);
		}
		if(t == 2){
			int r, x;
			cin >> r >> x;
			tym[r].push_back(i);
			val[r].push_back(x);
		}
		if(t == 3){
			int r, c;
			cin >> r >> c;
			qu[c].emplace_back(r, i);
		}
	}

	memset(ans, -1, sizeof ans);

	for(int i=1; i<=m; i++){
		for(auto [x, id] : ext[i]){
			update(id, -x);
		}
		for(auto [x, id] : entry[i]){
			update(id, x);
		}
		for(auto [r, id] : qu[i]){
			int last = 0;
			ll valu = 0;
			int pos = lower_bound(tym[r].begin(), tym[r].end(), id) - tym[r].begin();
			pos--;
			if(pos >= 0) last = tym[r][pos], valu = val[r][pos];
			ans[id] = valu + query(last+1, id);
		}
	}

	for(int i=1; i<=q; i++){
		if(ans[i] != -1) cout << ans[i] << "\n";
	}
	
	


}



