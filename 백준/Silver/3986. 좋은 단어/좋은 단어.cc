#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int ans = 0;


    for (int i = 0; i < N; i++) {
        stack<int> s;
        string temp;
        cin >> temp;

        s.push(temp[0]);

        for (int j = 1; j < temp.size(); j++) {
            if (s.empty()) {
                s.push(temp[j]);
            }
            else {
                if (temp[j] == s.top()) {
                    s.pop();
                }
                else {
                    s.push(temp[j]);
                }
            }

        }

        if (s.empty()) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}