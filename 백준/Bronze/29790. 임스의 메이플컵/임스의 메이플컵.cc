#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, U, L;
    cin >> N >> U >> L;

    if (N >= 1000) {
        if (U >= 8000 || L >= 260) {
            cout << "Very Good";
        }
        else {
            cout << "Good";
        }
    }
    else {
        cout << "Bad";
    }

    return 0;
}