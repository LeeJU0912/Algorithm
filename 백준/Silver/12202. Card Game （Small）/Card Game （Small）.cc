#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> save;

bool canFind() {
    vector<int> temp;
    temp.push_back(save[0]);

    int streak = 1;
    for (int i = 1; i < save.size(); i++) {
        temp.push_back(save[i]);
        if (save[i] - save[i - 1] == K) streak++;
        else streak = 1;

        if (streak == 3) {
            temp.pop_back();
            temp.pop_back();
            temp.pop_back();

            for (int j = i + 1; j < save.size(); j++) {
                temp.push_back(save[j]);
            }

            save = temp;

            return true;
        }
    }

    return false;
}

int main() {
    FastIO

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> N >> K;

        save = vector<int>(N);
        for (int i = 0; i < N; i++) {
            cin >> save[i];
        }

        while(canFind()) { }

        cout << "Case #" << t << ": " << save.size() << '\n';
    }

    return 0;
}