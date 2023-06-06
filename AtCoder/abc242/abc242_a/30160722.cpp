#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c, x;
    std::cin >> a >> b >> c >> x;
    
    if (x <= a) {
        std::cout << "1\n";
    } else if (x > b) {
        std::cout << "0\n";
    } else {
        std::cout << std::fixed << std::setprecision(10) << 1.0 * c / (b - a) << "\n";
    }
    
    return 0;
}