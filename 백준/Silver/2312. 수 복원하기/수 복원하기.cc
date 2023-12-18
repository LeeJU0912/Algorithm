#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool sosu[100001];

vector<int> sosu_list;

int main() {
    FastIO

    for (int i = 2; i * i <= 100000; i++) {
        if (sosu[i]) continue;
        for (int j = 2; i * j <= 100000; j++) {
            sosu[i * j] = true;
        }
    }

    for (int i = 2; i <= 100000; i++) {
        if (!sosu[i]) sosu_list.push_back(i);
    }

    int T;
    cin >> T;

    while(T--) {
        int n;
        cin >> n;

        for (int i = 0; i < sosu_list.size(); i++) {
            int counter = 0;
            while (n % sosu_list[i] == 0) {
                n /= sosu_list[i];
                counter++;
            }
            if (counter) {
                cout << sosu_list[i] << ' ' << counter << '\n';
            }
        }
    }

    return 0;
}