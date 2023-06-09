#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    bool mark;
    int i,n,t,x,cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt=0,mark=1;
        for(i=1;i<=n;i++)
        {
            cin >> x;
            if(x == 1  &&  mark)++cnt;
            else mark=0;
        }
        if(cnt == n)
        {
            if(cnt & 1)cout << "First\n";
            else cout << "Second\n";
        }
        else
        {
            if(!(cnt & 1))cout << "First\n";
            else cout << "Second\n";
        }
    }
    return 0;