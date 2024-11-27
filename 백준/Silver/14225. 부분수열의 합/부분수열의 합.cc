#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
unordered_set<int> chk;

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        save.push_back(x);
    }
    
    for (int i = 0; i < N; i++) {
        unordered_set<int> next = chk;
        for (int x : chk) {
            next.insert(x + save[i]);
        }
        next.insert(save[i]);
        chk = next;
    }

    for (int i = 1; i <= 2000000; i++) {
        if (chk.find(i) == chk.end()) {
            cout << i;
            return 0;
        }
    }

    return 0;
}