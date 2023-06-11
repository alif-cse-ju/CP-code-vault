#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
#define INF INT_MAX
#define MOD 1000000007
#define all(x) x.begin(), x.end()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin >> T;
    while(T--){
        int _, K; cin >> _ >> K;
                if(K == 0){
            cout << "YES" << endl;
            cout << "0" << endl;
            continue;
        }
        if(K%2 == 0){
            cout << "NO" << endl;
            continue;
        }
        int op = __lg(K);
        vi sol(op+1, -1);
        int idx = 1;
        for(; op >= 0; op--){
            if(!(K&(1<<op))) break;
            sol[op] = idx;
            idx += (1<<op);
            K -= (1<<op);
        }
        if(op != -1){
            int v = ((1<<op)-1)-K; // number of zeros to increase by v
            int x = ((1<<op)+v)/2;
            sol[op] = idx-x;
            int l = idx-x, r = idx-x+(1<<op);
            for(op--; op >= 0; op--){
                if((idx-l)&(1<<op)){
                    sol[op] = l;
                    l += (1<<op);
                }else{
                    sol[op] = r;
                    r += (1<<op);
                }
            }
        }
        cout << "YES" << endl;
        cout << sol.size() << endl;
        for(auto i : sol) cout << i << endl;
    }
    return 0;
}