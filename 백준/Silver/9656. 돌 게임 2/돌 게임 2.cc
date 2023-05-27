#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

int main() {
    FastIO

    cin >> N;

    if (N % 2) {
        cout << "CY";
    }
    else {
        cout << "SK";
    }
    
    return 0;
}