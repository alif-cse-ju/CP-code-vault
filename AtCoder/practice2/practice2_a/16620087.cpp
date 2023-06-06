#include<bits/stdc++.h>
#include<atcoder/all>

using namespace std;
using namespace atcoder;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,q,x,y,z;
    cin >> n >> q;
    dsu tree(n);
    while(q--)
    {
        cin >> x >> y >> z;
        if(x)cout << tree.same(y,z) << '\n';
        else tree.merge(y,z);
    }
    return 0;
}
