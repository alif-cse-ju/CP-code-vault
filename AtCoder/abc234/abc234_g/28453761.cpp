#include<bits/stdc++.h>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using ll = long long;

const ll MOD = 998244353;

int main(){
	int N; cin >> N;
	vector<ll> A(N);
	for(int i=0; i<N; i++) cin >> A[i];
	vector<ll> dp(N+1);
	dp[0] = 1;
	std::stack<ll> max, min, max_v, min_v;
	ll max_sum = 0, min_sum = 0;
	for(int i=0; i<N; i++){
		// max
		{
			ll sum_v = dp[i];
			while(!max.empty() && max.top() < A[i]){
				max_sum -= max_v.top()*max.top();
				sum_v += max_v.top();
				max_sum %= MOD;
				sum_v %= MOD;
				max.pop();
				max_v.pop();
			}
			max_sum += sum_v*A[i];
			max_sum %= MOD;
			max.push(A[i]);
			max_v.push(sum_v);
		}
		// min
		{
			ll sum_v = dp[i];
			while(!min.empty() && min.top() > A[i]){
				min_sum -= min_v.top()*min.top();
				sum_v += min_v.top();
				min_sum %= MOD;
				sum_v %= MOD;
				min.pop();
				min_v.pop();
			}
			min_sum += sum_v*A[i];
			min_sum %= MOD;
			min.push(A[i]);
			min_v.push(sum_v);
		}
		dp[i+1] = max_sum-min_sum;
		dp[i+1] %= MOD;
	}
	ll ans = dp[N];
	if(ans < 0) ans += MOD;
	cout << ans << endl;
}
