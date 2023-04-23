#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    long long N;
    cin >> N;

    long long B;
    cin >> B;

    vector<long long> save;

    long long counter = B;

    while(N > 0) {
        save.push_back((N % counter) / (counter / B));
        N -= N % counter;

        counter *= B;
    }

    for (int i = save.size() - 1; i >= 0; i--) {
        if (save[i] >= 10) {
            cout << (char)('A' + save[i] - 10);
        }
        else {
            cout << save[i];
        }
    }

    return 0;
}