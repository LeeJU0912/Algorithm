#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, Q;
long long shap[100001];
long long hap[100001];

int main() {
    FastIO

    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> temp;
        hap[i] = hap[i - 1] + temp;
        shap[i] = shap[i - 1] + temp * temp;
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        cout << ((hap[r] - hap[l - 1]) * (hap[r] - hap[l - 1]) - (shap[r] - shap[l - 1])) / 2 << '\n';
    }

    return 0;
}