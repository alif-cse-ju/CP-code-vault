#include<bits/stdc++.h>
using namespace std;
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,k,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k <= (n-1)/2)
        {
            deque<int>dq;
            for(i=1;i<=n;i++)dq.emplace_back(i);
            while(k--)
            {
                cout << dq.front() << ' ' << dq.back() << ' ';
                dq.pop_back(),dq.pop_front();
            }
            while(!dq.empty())
            {
                cout << dq.front() << ' ';
                dq.pop_front();
            }
            cout << '\n';
        }
        else cout << "-1\n";
    }
    return 0;
}
//