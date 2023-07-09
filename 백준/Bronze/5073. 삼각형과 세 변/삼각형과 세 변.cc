#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int a, b, c;

    while(true) {
        cin >> a >> b >> c;

        if (a == 0 && b == 0 && c == 0) break;

        int maxi;
        int others;
        if (b >= a) {
            maxi = b;
            others = a + c;
        }
        if (c >= b) {
            maxi = c;
            others = a + b;
        }
        if (a >= c) {
            maxi = a;
            others = b + c;
        }

        if (maxi >= others) {
            cout << "Invalid" << '\n';
        }
        else {
            if (a == b && b == c) {
                cout << "Equilateral" << '\n';
            }
            else if (a == b || b == c || c == a) {
                cout << "Isosceles" << '\n';
            }
            else if (a != b && b != c && c != a) {
                cout << "Scalene" << '\n';
            }
        }

    }
    
    return 0;
}