#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
string ans;
bool chk;

void solve(int count) {
    if (chk) return;

    for (int i = 1; i <= count / 2; i++) {

        for (int j = 0; j < count - i; j++) {
            int counter = 0;

            for (int k = 0; k < i; k++) {
                if (ans[j + k] == ans[i + j + k]) {
                    counter++;
                }
            }
            if (counter == i) return;
        }
    }

    if (count == N) {
        cout << ans;
        chk = true;
        return;
    }

    for (int i = 1; i <= 3; i++) {
        if (ans[ans.length() - 1] == i + '0') continue;

        ans.push_back(i + '0');
        solve(count + 1);
        ans.pop_back();
    }
}

int main() {
    FastIO

    cin >> N;

    for (int i = 1; i <= 3; i++) {
        ans.push_back(i + '0');
        solve(1);
        ans.pop_back();
    }
    
    return 0;
}