#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int i,n,x,y;
    vector<long long>v1,v2;
    cin >> n;
    for(i=0;i<n;i++)
    {
        cin >> x >> y;
        v1.emplace_back(x+y);
        v2.emplace_back(x-y);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    cout << max(v1.back()-v1[0],v2.back()-v2[0]);
    return 0;
}
