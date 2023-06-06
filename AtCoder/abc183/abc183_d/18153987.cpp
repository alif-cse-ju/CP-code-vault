#include<bits/stdc++.h>

using namespace std;

const int N=2e5+5;

long long cnt[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,l,n,r;
    long long x,y;
    cin >> n >> x;
    for(i=0;i<n;i++)
    {
        cin >> l >> r >> y;
        cnt[l]+=y,cnt[r]-=y;
    }
    for(i=1;i<N;i++)cnt[i]+=cnt[i-1];
    for(i=0;i<N;i++)
    {
        if(cnt[i] > x)
        {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}
