#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N, M;
    cin >> N >> M;

    vector<int> save(N + 1);

    for (int i = 1; i <= N; i++) {
        save[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;

        stack<int> s;
        for (int j = a; j <= b; j++) {
            s.push(save[j]);
        }
        for (int j = a; j <= b; j++) {
            save[j] = s.top();
            s.pop();
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << save[i] << ' ';
    }

    return 0;
}