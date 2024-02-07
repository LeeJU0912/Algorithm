#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string S, T;

queue<string> q;

bool ans;

int main() {
    FastIO

    cin >> S >> T;

    q.push(T);

    while(!q.empty()) {
        string now = q.front();
        q.pop();

        if (now == S) {
            ans = true;
            break;
        }

        if (now[now.size() - 1] == 'A' && now[0] == 'A') {
            now.pop_back();
            q.push(now);
        }
        else if (now[now.size() - 1] == 'B' && now[0] == 'B') {
            reverse(now.begin(), now.end());
            now.pop_back();
            q.push(now);
        }
        else if (now[now.size() - 1] == 'A' && now[0] == 'B') {
            string a = now;
            a.pop_back();
            q.push(a);

            reverse(now.begin(), now.end());
            now.pop_back();
            q.push(now);
        }
    }

    if (ans) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}