#include<bits/stdc++.h>
using namespace std;
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int main()
{
    FAST();
    int i,n,t;
    long double x,y,z,temp,cnt1,cnt2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cnt1=cnt2=0;
        for(i=0;i<n;i++)
        {
            cin >> x >> y >> z;
            temp=x*(y/(y+z));
            cnt2+=temp,cnt1+=x-temp;
        }
        cout << fixed << setprecision(10) << cnt1 << ' ';
        cout << fixed << setprecision(10) << cnt2 << '\n';
    }
    return 0;
}