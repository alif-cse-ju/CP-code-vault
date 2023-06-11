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
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    long long i,n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<long long>ans;
        for(i=0;i<41;i++)
        {
            if((n >> i) & 1ll)ans.emplace_back(pow(3,i));
        }
        cout << (int)ans.size() << '\n';
        for(long long it : ans)cout << it << ' ';
        cout << '\n';
    }
    return 0;
}
//1316