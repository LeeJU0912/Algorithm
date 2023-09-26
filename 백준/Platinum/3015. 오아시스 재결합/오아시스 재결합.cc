#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;
stack<pair<int, int>> stk;

long long ans;

int main() {
    FastIO

    cin >> N;
    save = vector<int>(N);

    for (int i = 0; i < N; i++) {
        cin >> save[i];
    }

    stk.push({save[0], 0});

    for (int i = 1; i < N; i++) {
        int now = 0;
        // 작은 경우
        if (stk.top().first > save[i]) {
            now = 1;
            ans += now;
        }
        // 같은 경우
        else if (stk.top().first == save[i]) {
            now = stk.top().second + 1;
            ans += now;
        }
        // 큰 경우
        else {
            while(!stk.empty() && stk.top().first < save[i]) {
                stk.pop();
                ans += 1;
            }
            if (!stk.empty()) {
                if (stk.top().first == save[i]) {
                    now = stk.top().second + 1;
                    ans += now;
                }
                else {
                    now = 1;
                    ans += now;
                }
            }
        }

        stk.push({save[i], now});
    }

    cout << ans;

    return 0;
}