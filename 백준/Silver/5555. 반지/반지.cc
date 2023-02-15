#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    string s;
    cin >> s;

    int N;
    cin >> N;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        string temp;
        cin >> temp;

        int temp_length = temp.length();

        temp += temp;

        for (int j = 0; j < temp_length; j++) {
            string now;
            for (int k = 0; k < s.length(); k++) {
                now.push_back(temp[j + k]);
            }
            if (now == s) {
                ans++;
                break;
            }
        }
    }

    cout << ans;

    return 0;
}