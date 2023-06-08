#include<bits/stdc++.h>
 using namespace std;
 int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string s;
    cin >> s;
    cout << "3\n";
    cout << "L 2\n";
    cout << "R 2\n";
    cout << "R " << 2*(int)s.size()-1;
    return 0;
}