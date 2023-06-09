#include<bits/stdc++.h>
using namespace std;
#define PII pair<int,int>
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
    FAST();
    bool valid;
    int i,n,t,a[505],b[505];
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(i=1;i<=n;i++)cin >> a[i];
        for(i=1;i<=n;i++)cin >> b[i];
        if((n & 1)  &&  a[n/2+1] != b[n/2+1])cout << "NO\n";
        else
        {
            valid=true;
            vector<PII>pa,pb;
            for(i=1;i<=n/2;i++)
            {
                if(a[i] > a[n-i+1])swap(a[i],a[n-i+1]);
                if(b[i] > b[n-i+1])swap(b[i],b[n-i+1]);
                pa.emplace_back(a[i],a[n-i+1]);
                pb.emplace_back(b[i],b[n-i+1]);
            }
            sort(pa.begin(),pa.end());
            sort(pb.begin(),pb.end());
            for(i=0;i<n/2;i++)
            {
                if(pa[i] != pb[i])
                {
                    valid=false;
                    break;
                }
            }
            if(valid)cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}