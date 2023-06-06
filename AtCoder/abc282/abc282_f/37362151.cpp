///****In the name of ALLAH, most Gracious, most Compassionate****//

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

#define ALL(a) a.begin(), a.end()
#define FastIO ios::sync_with_stdio(false); cin.tie(0);cout.tie(0)
#define IN freopen("input.txt","r+",stdin)
#define OUT freopen("output.txt","w+",stdout)

#define DBG(a) cerr<< "line "<<__LINE__ <<" : "<< #a <<" --> "<<(a)<<endl
#define NL cerr<<endl

template < class T1,class T2>
ostream &operator <<(ostream &os,const pair < T1,T2 > &p)
{
    os<<"{"<<p.first<<","<<p.second<<"}";
    return os;
}
template <class T , size_t N>
ostream &operator <<(ostream &os,const array <T,N> &a)
{
	os<<"{";
	for(auto x: a)
		os<<x<<" ";
	os<<"}";
	return os;
}

template <class T>
ostream &operator <<(ostream &os,const vector<T> &a)
{
	os<<"{ ";
	for(auto x: a)
		os<<x<<" ";
	os<<"}";
	return os;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N=3e5+5;
const int oo=1e9+7;


const int K = 23 ; /// k >= ceil(lg22(n)) +1
int st[N][K + 1];
int lg2[N+1];
void ini()
{
    lg2[1] = 0;
    for (int i = 2; i <= N; i++)
        lg2[i] = lg2[i/2] + 1;
}

int to[N][K+1];

void pre( int n)
{
	vector<pii> q;
    for (int i = 1; i <= n; i++)
        st[i][0] = q.size() + 1 , q.push_back({i,i});

    for (int j = 1; j <= K; j++)
        for (int i = 1; i + (1 << j) <= n+1; i++)
            st[i][j] = q.size()+1 , q.push_back({i,i+(1<<j)-1});
	cout<<q.size()<<"\n";
	for(auto x: q)
		cout<<x.first<<" "<<x.second<<"\n";
	cout.flush();
}
pii getf( int L,int R)
{
    if(L>R) swap(L,R);
    int j = lg2[R - L + 1];
    // return  f(st[L][j], st[R - (1 << j) + 1][j]);
	return {st[L][j], st[R - (1 << j) + 1][j]};
}


int32_t main()
{
    FastIO;
	ini();
	// DBG(pre[4000]);
	int n;
	cin>>n;
	pre(n);
	int q;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		auto x = getf(l,r);
		cout<<x.first<<" "<<x.second<<endl;
	}
}
