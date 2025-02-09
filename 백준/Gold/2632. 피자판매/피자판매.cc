#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int x;
int m, n;
int A[1000];
int B[1000];
map<int, int> APart, BPart;

long long ans;

int main() {
    FastIO

    cin >> x >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> B[i];
    }

    APart[0] = 1;
    for (int i = 0; i < m; i++) {
        int hap = 0;
        for (int j = 0; j < m; j++) {
            hap += A[(i + j) % m];
            APart[hap]++;
        }

        if (i == m - 1) {
            APart[hap] = 1;
        }
    }

    BPart[0] = 1;
    for (int i = 0; i < n; i++) {
        int hap = 0;
        for (int j = 0; j < n; j++) {
            hap += B[(i + j) % n];
            BPart[hap]++;
        }

        if (i == n - 1) {
            BPart[hap] = 1;
        }
    }

    for (const auto & a : APart) {
        ans += a.second * BPart[x - a.first];
    }

    cout << ans;

    return 0;
}