#include <bits/stdc++.h>
using namespace std;

vector<int> save;
int N, M;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);
    }

    sort(save.begin(), save.end());

    vector<int> temp(N);

    for (int i = 0; i < M; i++) {
        temp[i] = 1;
    }

    do {
        for (int i = 0; i < N; i++) {
            if (temp[i] == 1) {
                cout << save[i] << ' ';
            }
        }
        cout << '\n';
    } while(prev_permutation(temp.begin(), temp.end()));

    return 0;
}