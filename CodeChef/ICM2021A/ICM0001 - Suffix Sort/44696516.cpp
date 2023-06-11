#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=3e5+5;
const int mod=1e9+7;
int a[N];
int main()
{
    FAST();
    int i,m,n,t;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        if(is_sorted(a+1,a+n+1))cout << "YES\n0\n";
        else
        {
            deque<int>dq;
            for(i=1;i<=n;i++)dq.emplace_back(a[i]);
            m=n;
            while(m--  &&  dq.back() <= dq.front())
            {
                dq.emplace_front(dq.back());
                dq.pop_back();
            }
            i=0;
            while(!dq.empty())
            {
                a[++i]=dq.front();
                dq.pop_front();
            }
            if(is_sorted(a+1,a+n+1))cout << "YES\n1\n";
            else cout << "NO\n";
        }
    }
    return 0;
}