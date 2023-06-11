#include<bits/stdc++.h>
using namespace std;
#define LL long long
LL ans;
void find_ans(LL x,LL y)
{
    ++ans;
    if(x == y  ||  (x/y) >= 2LL)return;
    find_ans(y,x%y);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    LL m,n;
    cin >> t;
    while(t--)
    {
        cin >> m >> n;
        if(m > n)swap(m,n);
        ans=0LL;
        find_ans(n,m);
        if(ans & 1LL)cout << "Ari\n";
        else cout << "Rich\n";
    }
    return 0;
}