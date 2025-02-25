#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

struct INFO {
    string name;
    struct Compare {
        bool operator()(const INFO* a, const INFO* b) const {
            return a->name < b->name;
        }
    };

    set<INFO*, Compare> child;
};

INFO * findINFO(INFO * before, const string& now) {
    for (auto next : before->child) {
        if (next->name == now) return next;
    }

    return nullptr;
}

void addString(INFO * before, string s, int idx) {
    if (idx == s.size()) return;

    string now;
    for (; idx < s.size(); idx++) {
        if (s[idx] == '\\') {
            idx++;
            break;
        }
        now += s[idx];
    }

    INFO * result = findINFO(before, now);

    if (result == nullptr) {
        INFO * nowINFO = new INFO();
        nowINFO->name = now;

        before->child.insert(nowINFO);

        addString(nowINFO, s, idx);
    }
    else {
        addString(result, s, idx);
    }
}

void printINFO(INFO * now, int depth) {
    if (depth >= 0) {
        for (int i = 0; i < depth; i++) {
            cout << ' ';
        }
        cout << now->name << '\n';
    }

    for (auto next : now->child) {
        printINFO(next, depth + 1);
    }
}

int main() {
    FastIO

    INFO * root = new INFO();

    cin >> N;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        addString(root, s, 0);
    }

    printINFO(root, -1);

    return 0;
}