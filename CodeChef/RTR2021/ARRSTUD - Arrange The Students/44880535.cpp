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
    string s;
    int t,ans;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<int>v;
        v.emplace_back(0);
        v.emplace_back(0);
        while(!s.empty())
        {
            while(!s.empty()  &&  s.back() == '0')s.pop_back();
            v.emplace_back(0);
            while(!s.empty()  &&  s.back() == '1')s.pop_back(),++v.back();
        }
        sort(v.begin(),v.end());
        ans=v.back(),v.pop_back();
        ans+=v.back(),v.pop_back();
        cout << ans << '\n';
    }
    return 0;
}