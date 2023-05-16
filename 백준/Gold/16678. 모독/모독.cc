#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
long long ans;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    int counter = 1;
    for (int i = 0; i < save.size(); i++) {
        if (save[i] - counter >= 0) {
            ans += save[i] - counter;
            counter++;
        }
    }

    cout << ans;

    return 0;
}