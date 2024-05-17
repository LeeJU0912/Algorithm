#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<string> save;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        sort(s.begin(), s.end());

        do {
            cout << s << '\n';
        } while(next_permutation(s.begin(), s.end()));
    }

    return 0;
}