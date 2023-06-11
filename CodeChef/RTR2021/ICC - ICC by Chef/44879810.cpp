#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL)
//int dx[]={-1,1,0,0};
//int dy[]={0,0,-1,1};
//int dx[]={-1,0,1,-1,1,-1,0,1};
//int dy[]={1,1,1,0,0,-1,-1,-1};
const int M=1e5+5;
const int N=2e5+5;
const int mod=1e9+7;
int main()
{
    FAST();
    int t;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<pair<int,char>>v;
        while(!s.empty())
        {
            v.emplace_back(0,s.back());
            while(!s.empty()  &&  s.back() == v.back().second)
            {
                ++v.back().first;
                s.pop_back();
            }
        }
        sort(v.begin(),v.end());
        cout << v.back().first << ' ' << v.back().second << '\n';
    }
    return 0;
}