#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

map<string, vector<string>> groupAndMember;
map<string, string> memberAndGroup;

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        string teamName;
        cin >> teamName;

        int t;
        cin >> t;

        for (int j = 0; j < t; j++) {
            string member;
            cin >> member;
            memberAndGroup[member] = teamName;
            groupAndMember[teamName].push_back(member);
        }
    }

    for (int i = 0; i < M; i++) {
        string s;
        cin >> s;
        int order;
        cin >> order;

        if (order) {
            cout << memberAndGroup[s] << '\n';
        }
        else {
            sort(groupAndMember[s].begin(), groupAndMember[s].end());
            for (const auto& x : groupAndMember[s]) {
                cout << x << '\n';
            }
        }
    }

    return 0;
}