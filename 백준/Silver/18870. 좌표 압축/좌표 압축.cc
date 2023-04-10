#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> save(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    vector<int> temp = save;

    sort(temp.begin(), temp.end());

    temp.erase(unique(temp.begin(), temp.end()), temp.end());

    for (int i = 0; i < N; i++) {
        cout << lower_bound(temp.begin(), temp.end(), save[i]) - temp.begin() << ' ';
    }

    return 0;
}