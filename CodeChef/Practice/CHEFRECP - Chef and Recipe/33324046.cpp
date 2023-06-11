#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t,a[1005],cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int>v;
        set<int>uniq,distCnt;
        for(i=0;i<n;i++)
        {
            cin >> a[i];
            uniq.insert(a[i]);
        }
        cnt=1;
        v.emplace_back(a[0]);
        for(i=1;i<n;i++)
        {
            if(a[i] == v.back())++cnt;
            else
            {
                distCnt.insert(cnt);
                v.emplace_back(a[i]),cnt=1;
            }
        }
        distCnt.insert(cnt);
        if(v.size() == uniq.size()  &&  v.size() == distCnt.size())cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}