#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int test;
    cin >> test;
    while (test--)
    {
        int n;
        cin >> n;
        string ansl;
        string ansr;
        string s,t;
        cin>>s>>t;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        reverse(t.begin(),t.end());
        deque<char> a,b;
        for(int i=0;i<n;i++)
        {
            a.push_back(s[i]);
        }
        for(int i=0;i<n;i++)
        {
            b.push_back(t[i]);
        }
        int turn=0;   
        for(int i=0;i<2*n;i++)
        {
            if(i&1)   // BOb turn
            {
                if(!a.empty() and a[0]>=b[0])
                {
                    turn=1;
                }
                if(turn)
                {
                    ansr+=b.back();
                    b.pop_back();
                }
                else
                {
                    ansl+=b[0];
                    b.pop_front();
                }
            }
            else //Alice's turn
            {
                if(!b.empty() and a[0]>=b[0])
                {
                    turn=1;
                }
                if(turn)
                {
                    ansr+=a.back();
                    a.pop_back();
                }
                else
                {
                    ansl+=a[0];
                    a.pop_front();
                }
            }
        }
        reverse(ansr.begin(),ansr.end());
        string result = ansl+ansr;
        cout<<result<<'\n';
    }
    return 0;
}