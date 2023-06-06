#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

struct Edge {
	int to, c, d;
	Edge(int to, int c, int d) :to(to), c(c), d(d) {

	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N >> M;
	vector<vector<Edge>>edge(N);
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> H >> W;
		L--, R--;
		edge[L].push_back(Edge(R, H, W));
		edge[R].push_back(Edge(L, H, W));
	}
	vector<long long int>dis(N, LLONG_MAX);
	dis[0] = 0;
	priority_queue<pair<long long int, int>, vector<pair<long long int, int>>, greater<pair<long long int, int>>>PQ;
	PQ.push({ 0,0 });
	while (!PQ.empty()) {
		auto box = PQ.top();
		PQ.pop();
		if (dis[box.second] < box.first)continue;
		for (auto i : edge[box.second]) {
			long long int cost = 0;
			long long int sq = sqrt(i.d);
			if (sq * sq != i.d)sq++;
			sq--;
			if (box.first < sq) {
				cost = sq - box.first + i.c + i.d / (sq + 1);
			}
			else {
				cost = i.c + i.d / (box.first + 1);
			}
			if (dis[i.to] > box.first + cost) {
				dis[i.to] = box.first + cost;
				PQ.push({ dis[i.to],i.to });
			}
		}
	}
	if (dis.back() == LLONG_MAX) {
		cout << -1 << endl;
	}
	else {
		cout << dis.back() << endl;
	}
}