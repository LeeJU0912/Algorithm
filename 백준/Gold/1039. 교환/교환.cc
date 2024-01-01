#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

string N;
int K;

queue<string> q;
unordered_set<string> st;

int main() {
    FastIO

    cin >> N >> K;

    q.push(N);

    for (int i = 0; i < K; i++) {
        st.clear();

        int qsize = q.size();
        for (int x = 0; x < qsize; x++) {
            string now = q.front();
            q.pop();

            for (int j = 0; j < now.size() - 1; j++) {
                for (int k = j + 1; k < now.size(); k++) {
                    string next = now;

                    if (j == 0 && next[k] == '0') continue;

                    swap(next[j], next[k]);

                    if (st.find(next) != st.end()) continue;
                    st.insert(next);

                    q.push(next);
                }
            }
        }
    }

    if (q.empty()) {
        cout << -1;
        return 0;
    }

    string ans = "0";

    while(!q.empty()) {
        ans = max(ans, q.front());
        q.pop();
    }

    cout << ans;

    return 0;
}