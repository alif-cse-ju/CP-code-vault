#include<bits/stdc++.h>
using namespace std;
#define PI acos(-1)
int i,n,x,y,cnt_0_a,cnt_1_a,cnt_0_b,cnt_1_b;
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);
    cin >> n;
    for(i=1;i<=n;i++)
    {
        cin >> x;
        if(x == 1)
        {
            cnt_1_a++;
        }
        else
        {
            cnt_0_a++;
        }
        cin >> y;
        if(y == 1)
        {
            cnt_1_b++;
        }
        else
        {
            cnt_0_b++;
        }
    }
    cout << min(cnt_1_a,cnt_0_a) + min(cnt_1_b,cnt_0_b);
    return 0;
}