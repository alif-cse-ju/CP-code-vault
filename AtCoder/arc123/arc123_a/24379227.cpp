#include <iostream>
using namespace std;
using ll = long long;
int main(){
  ll a, b, c;
  cin >> a >> b >> c;
  ll x = 2 * b - a - c;
  ll k = (x >= 0 ? 0 : (1 - x) / 2);
  ll ans = x + 3 * k;
  cout << ans << endl;
}
