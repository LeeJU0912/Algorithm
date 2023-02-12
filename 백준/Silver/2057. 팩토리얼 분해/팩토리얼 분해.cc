#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long N;
    cin >> N;

    if (N == 0) {
        cout << "NO";
        return 0;
    }
    else if (N <= 4) {
        cout << "YES";
        return 0;
    }

    long long factorial = 1;
    int counter = 0;
    while(factorial <= N) {
        counter++;
        factorial *= counter;
    }
    factorial /= counter--;

    while(N > 0) {
        if (factorial <= N) {
            N -= factorial;
        }
        if (counter == 0) break;
        factorial /= counter--;
    }

    if (N == 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}