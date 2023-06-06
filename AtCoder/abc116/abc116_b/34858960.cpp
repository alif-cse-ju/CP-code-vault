#include <bits/stdc++.h>
using namespace std;

//https://atcoder.jp/contests/abc116/tasks/abc116_b


int main() {
	int s;
    cin >> s;
    int ans = 0;
    int a = s;
	map<int, int> amap;
    amap[s] = 1;
    for (int i=2; i < 1000001; i++) {
        a = a%2 ==0 ? a/2 : 3*a+1;
		if (amap.count(a) == 0) {
			amap[a] = i;
		} else {
            ans = i;
            break;
		}
    }
    cout << ans << endl;
}
