#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

vector<double> save;

int main() {
    FastIO

    int N;
    cin >> N;
    save = vector<double>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end());

    cout << fixed;
    cout.precision(3);
    for (int i = 0; i < 7; i++) {
        cout << save[i] << '\n';
    }

    return 0;
}