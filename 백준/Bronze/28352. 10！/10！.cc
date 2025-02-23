#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    long long hap = 1;
    for (int i = 2; i <= N; i++) {
        hap *= i;
    }

    cout << hap / (60 * 60 * 24 * 7);

    return 0;
}