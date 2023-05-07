#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;


int main() {
    FastIO

    int N;
    cin >> N;

    queue<int> save;
    for (int i = 1; i <= N; i++) {
        save.push(i);
    }

    bool down = false;

    vector<int> ans;

    while(!save.empty()) {
        if (down) {
            save.push(save.front());
            save.pop();
        }
        else {
            ans.push_back(save.front());
            save.pop();
        }
        down = !down;
    }

    for (auto i : ans) {
        cout << i << ' ';
    }

    return 0;
}