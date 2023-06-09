#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
vector<long long>v;
map<long long,bool>mark;
void PreCal()
    for(long long i=1;i<10001;i++)
    {
        mark[i*i*i]=1;
        v.emplace_back(i*i*i);
    }
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    PreCal();
    bool flag;
    int t;
    long long n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        flag=0;
        for(long long it : v)
        {
            if(mark.find(n-it) != mark.end())
            {
                flag=1;
                break;
            }
        }
        if(flag)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
//