    #include <iostream>
    using namespace std;
    int main() {
      long long X;
      cin >> X;
      if (X < 0 and X % 10 != 0) {
        cout << X / 10 - 1 << "\n";
      } else {
        cout << X / 10 << "\n";
      }
    }