#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> v;
int save[100000];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    for (int i = 0; i < K; i++) {
        save[0] += v[i];
    }

    for (int i = 1; i < N - K + 1; i++) {
        save[i] = save[i - 1] - v[i - 1] + v[i + K - 1];
    }


    cout << *max_element(save, save + N - K + 1);

    return 0;
}