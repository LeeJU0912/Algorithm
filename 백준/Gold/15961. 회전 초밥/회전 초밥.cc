#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, d, k ,c;

int sushi[3000001];
int ans;

unordered_map<int, int> event;

int main() {
    FastIO

    cin >> N >> d >> k >> c;

    for (int i = 0; i < N; i++) {
        cin >> sushi[i];
    }

    for (int i = 0; i < k; i++) {
        event[sushi[i]]++;
    }

    for (int i = 0; i < N; i++) {
        if (event.find(c) == event.end()) {
            ans = max(ans, (int)(event.size() + 1));
        }
        else {
            ans = max(ans, (int)event.size());
        }

        event[sushi[i]]--;
        event[sushi[(i + k) % N]]++;

        if (event[sushi[i]] == 0) event.erase(sushi[i]);
    }

    cout << ans;

    return 0;
}