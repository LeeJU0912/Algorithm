#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int save[5];

bool chk() {
    for (int i = 0; i < 5; i++) {
        if (save[i] != i + 1) return true;
    }

    return false;
}

void calc() {
    for (int i = 1; i < 5; i++) {
        if (save[i] < save[i - 1]) {
            int tmp = save[i];
            save[i] = save[i - 1];
            save[i - 1] = tmp;

            for (int j = 0; j < 5; j++) {
                cout << save[j] << ' ';
            }
            cout << '\n';
        }
    }
}

int main() {
    FastIO

    for (int i = 0; i < 5; i++) {
        cin >> save[i];
    }

    while(chk()) {
        calc();
    }
    
    return 0;
}