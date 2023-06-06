#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int a[4];
    for(int i=0;i<4;i++)cin >> a[i];
    sort(a,a+4);
    if(a[0]+a[3] == a[1]+a[2])cout << "Yes";
    else if(a[0]+a[1]+a[2] == a[3])cout << "Yes";
    else cout << "No";
    return 0;
}
