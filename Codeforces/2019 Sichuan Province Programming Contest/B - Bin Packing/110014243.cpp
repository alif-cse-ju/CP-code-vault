#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,tc;
    double h1,h2,w1,w2,ans;
    cin >> t;
    for(tc=1;tc<=t;tc++)
    {
        cin >> h1 >> w1 >> h2 >> w2;
        ans=(h1+h2)*max(w1,w2)-0.5*(w1 > w2 ? h2*(w1-w2) : h1*(w2-w1));
        ans=min(ans,(h1+w2)*max(w1,h2)-0.5*(w1 > h2 ? w2*(w1-h2) : h1*(h2-w1)));
        ans=min(ans,(w1+w2)*max(h1,h2)-0.5*(h1 > h2 ? w2*(h1-h2) : w1*(h2-h1)));
        ans=min(ans,(w1+h2)*max(h1,w2)-0.5*(h1 > w2 ? h2*(h1-w2) : w1*(w2-h1)));
        cout << "Case " << tc << ": ";
        cout << fixed << setprecision(10) << ans << '\n';
    }
    return 0;