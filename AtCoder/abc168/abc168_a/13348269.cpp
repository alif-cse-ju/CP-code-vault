#include<bits/stdc++.h>

using namespace std;

#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main()
{
    FAST();
    int n;
    cin >> n;
    n%=10;
    if(n == 3)cout << "bon";
    else if(n == 0 || n == 1 || n == 6 || n == 8)cout << "pon";
    else cout << "hon";
    return 0;
}
