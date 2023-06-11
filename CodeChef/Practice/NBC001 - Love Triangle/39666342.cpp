# include <bits/stdc++.h>
using namespace std;
# define ll long long
# define ld long double
ld area(int arr[]) {
    int s1 = arr[0];
    int s2 = arr[1];
    int s3 = arr[2];
        ld semi_perimeter = (s1 + s2 + s3) / 2;
        return sqrt(semi_perimeter * (semi_perimeter - s1) * (semi_perimeter - s2) * (semi_perimeter - s3));
} 
int main() {;
    int t;
    cin >> t;
    while (t--) {
        int sides[3];
        scanf("%d %d %d", &sides[0], &sides[1], &sides[2]);
        sort(sides, sides + 3);
                ld x = area(sides);
        if ((sides[0] + sides[1]) > sides[2]) printf("YES %.5Lf \n", x);
        else cout << "NO" << endl;
    }
        return 0;
}