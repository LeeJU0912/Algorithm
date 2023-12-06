#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

bool sosu[1234322];

vector<string> sosu_list;

int main() {
    FastIO

    for (int i = 2; i <= sqrt(1234321); i++) {
        if (sosu[i]) continue;
        for (int j = 2; i * j <= 1234321; j++) {
            sosu[i * j] = true;
        }
    }

    for (int i = 2; i <= 1234321; i++) {
        if (!sosu[i]) {
            sosu_list.push_back(to_string(i));
        }
    }

    cin >> N;
    for (int i = 0; i < sosu_list.size(); i++) {
        if (stoi(sosu_list[i]) >= N) {
            int counter = 0;
            for (int j = 0; j < sosu_list[i].size() / 2; j++) {
                if (sosu_list[i][j] == sosu_list[i][sosu_list[i].size() - 1 - j]) counter++;
            }
            
            if (counter == sosu_list[i].size() / 2) {
                cout << sosu_list[i];
                return 0;
            }
        }
    }

    return 0;
}