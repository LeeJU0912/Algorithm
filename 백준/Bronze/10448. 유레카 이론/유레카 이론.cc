#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main(){
    FastIO


    int tri[46];

    for (int i = 1; i <= 45; i++) {
        tri[i] = i * (i + 1) / 2;
    }

    int T;
    cin >> T;

    while(T--) {
        int N;
        cin >> N;

        bool flag = false;
        for (int i = 1; i <= 45; i++) {
            for (int j = 1; j <= 45; j++) {
                for (int k = 1; k <= 45; k++) {
                    if (tri[i] + tri[j] + tri[k] == N) {
                        flag = true;
                        break;
                    }
                }
                if (flag) break;
            }
            if (flag) break;
        }

        if (flag) cout << 1 << '\n';
        else cout << 0 << '\n';
    }


    return 0;
}