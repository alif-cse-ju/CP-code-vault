#include <iostream>
using namespace std;
int main()
{
  int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  
  int ans = 0;
  ans++;
  if(b != a) ans++;
  if(c != a && c != b) ans++;
  if(d != a && d != b && d != c) ans++;
  if(e != a && e != b && e != c && e != d) ans++;
  
  cout << ans << endl;
  return 0;
}