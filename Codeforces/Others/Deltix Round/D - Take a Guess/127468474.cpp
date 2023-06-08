#include<bits/stdc++.h>
using namespace std;
const int N=1e4+5;
int a[N],_and[N],_or[N];
int main()
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int i,j,k,n,x,_and23,_or23,_xor23;
    cin >> n >> k;
    for(i=2; i<=n; i++)
    {
        cout << "and 1 " << i << endl;
        cin >> _and[i];
    }
    for(i=2; i<=n; i++)
    {
        cout << "or 1 " << i << endl;
        cin >> _or[i];
    }
    cout << "and 2 3" << endl;
    cin >> _and23;
    cout << "or 2 3" << endl;
    cin >> _or23;
    _xor23=(_and23 ^ _or23);
    a[1]=_and[2],a[2]=a[3]=_and23;
    for(i=0; i<30; i++)
    {
        if((_xor23 >> i) & 1)
        {
            if(((_or[2] >> i) & 1)  &&  ((_or[3] >> i) & 1))
            {
                if((_and[2] >> i) & 1)a[2] |= (1 << i);
                else a[3] |= (1 << i);
            }
            else if((_or[2] >> i) & 1)a[2] |= (1 << i);
            else a[3] |= (1 << i);
        }
    }
    for(i=0; i<30; i++)
    {
        if((_or[2] >> i) & 1)
        {
            if(!((a[2] >> i) & 1))a[1] |= (1 << i);
        }
    }
    for(i=4; i<=n; i++)a[i] |= _and[i];
    for(i=4; i<=n; i++)
    {
        for(j=0; j<30; j++)
        {
            if((_or[i] >> j) & 1)
            {
                if(!((a[1] >> j) & 1))a[i] |= (1 << j);
            }
        }
    }
    sort(a+1,a+n+1);
    cout << "finish " << a[k] << endl;
    return 0;
}