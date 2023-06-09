#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
const int mod=1e9+7;
int a[N],xr[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,n,x,y,z,_and,pos=0,val;
    map<int,int>idx;
    cin >> n;
    for(i=2;i<=n;i++)
    {
        cout << "XOR " << 1 << ' ' << i << endl;
        cin >> xr[i];
        if(idx.find(xr[i]) == idx.end())idx[xr[i]]=i;
        else pos=i,val=xr[i];
    }
    if(pos)
    {
        cout << "AND " << idx[val] << ' ' << pos << endl;
        cin >> _and;
        a[idx[val]]=a[pos]=_and;
        a[1]=(xr[pos] ^ _and);
        for(i=2;i<=n;i++)a[i]=(xr[i] ^ a[1]);
    }
    else
    {
        pos=idx[n-1];
        if(pos == 2)
        {
            x=xr[2];
            cout << "AND 1 3" << endl;
            cin >> y;
            y+=xr[3]+y;
            cout << "AND 2 3" << endl;
            cin >> z;
            z+=(xr[2] ^ xr[3])+z;
        }
        else
        {
            cout << "AND 1 2" << endl;
            cin >> x;
            x+=xr[2]+x;
            y=xr[pos];
            cout << "AND 2 " << pos << endl;
            cin >> z;
            z+=(xr[2] ^ xr[pos])+z;
        }
        a[1]=(x+y-z)/2;
        for(i=2;i<=n;i++)a[i]=(xr[i] ^ a[1]);
    }
    cout << '!';
    for(i=1;i<=n;i++)cout << ' ' << a[i];
    cout << endl;
    return 0;
}
//