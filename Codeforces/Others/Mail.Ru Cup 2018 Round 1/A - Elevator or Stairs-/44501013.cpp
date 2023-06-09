#include<bits/stdc++.h>
using namespace std;
int main()
    int x,y,z,t1,t2,t3,cnt1=0,cnt2=0;
    cin >> x >> y >> z >> t1 >> t2 >> t3;
    cnt1=fabs(x-y)*t1;
    cnt2=t3*3+fabs(z-x)*t2+fabs(x-y)*t2;
    if(cnt2<=cnt1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;