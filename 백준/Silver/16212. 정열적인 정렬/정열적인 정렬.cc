#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    for (int i = 0; i < N; i++) {
        cout << save[i] << ' ';
    }

    return 0;
}