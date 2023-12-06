#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

bool sosu[1003002];

vector<int> sosu_list;

int main() {
    FastIO

    for (int i = 2; i <= sqrt(1003001); i++) {
        if (sosu[i]) continue;
        for (int j = 2; i * j <= 1003001; j++) {
            sosu[i * j] = true;
        }
    }

    for (int i = 2; i <= 1003001; i++) {
        if (!sosu[i]) {
            sosu_list.push_back(i);
        }
    }

    cin >> N;
    for (int i = 0; i < sosu_list.size(); i++) {
        if (sosu_list[i] >= N) {
            int counter = 0;

            string s_sosu = to_string(sosu_list[i]);
            for (int j = 0; j < s_sosu.size() / 2; j++) {
                if (s_sosu[j] == s_sosu[s_sosu.size() - 1 - j]) counter++;
            }

            if (counter == s_sosu.size() / 2) {
                cout << sosu_list[i];
                return 0;
            }
        }
    }

    return 0;
}