#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, K;
vector<int> ans;
bool visited[5001];

int main() {
    FastIO

    cin >> N >> K;

    int cur = K;
    visited[K] = true;
    ans.push_back(cur);

    while(ans.size() < N) {
        for (int i = 1; i <= K; i++) {
            cur++;
            if (cur > N) cur -= N;
            while(visited[cur]) {
                cur++;
                if (cur > N) cur -= N;
            }
        }
        visited[cur] = true;
        ans.push_back(cur);
    }

    cout << '<';
    for (int i = 0; i < ans.size() - 1; i++) {
        cout << ans[i] << ", ";
    }
    cout << ans[ans.size() - 1] << '>';

    return 0;
}