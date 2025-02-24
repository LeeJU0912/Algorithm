#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

struct INFO {
    bool finish = false;
    INFO * next[26]{};

    void insert(char * key) {
        if (*key == 0) {
            finish = true;
            return;
        }

        int cur = *key - 'a';
        if (next[cur] == nullptr) {
            next[cur] = new INFO();
        }
        next[cur]->insert(key + 1);
    }

    INFO * find(char * key) {
        if (*key == 0) return this;
        int cur = *key - 'a';
        if (next[cur] == nullptr) return nullptr;
        return next[cur]->find(key + 1);
    }
};

int main() {
    FastIO

    INFO * root = new INFO();

    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        char s[501];
        cin >> s;

        root->insert(s);
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        char s[501];
        cin >> s;

        if (root->find(s)) ans++;
    }

    cout << ans;

    return 0;
}