#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int n;
    cin >> n;
    n%=1000;
    if(n > 0)n=1000-n;
    cout << n;
    return 0;
}
