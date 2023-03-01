#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
string a, b;
string calc;

void flip(int x) {
    for (int i = -1; i <= 1; i++) {
        int now = x + i;
        if (now < 0 || now >= N) continue;

        if (calc[now] == '1') calc[now] = '0';
        else calc[now] = '1';
    }
}

bool chk() {
    for (int i = 0; i < N; i++) {
        if (calc[i] != b[i]) return true;
    }
    return false;
}


int main() {
    FastIO

    cin >> N;
    cin >> a >> b;

    calc = a;

    if (calc[0] == '1') calc[0] = '0';
    else calc[0] = '1';
    if (calc[1] == '1') calc[1] = '0';
    else calc[1] = '1';

    int counter1 = 1;
    for (int i = 1; i < N; i++) {
        if (calc[i - 1] != b[i - 1]) {
            flip(i);
            counter1++;
        }
    }
    bool flag1 = false;

    if(chk()) flag1 = true;

    calc = a;
    int counter2 = 0;
    for (int i = 1; i < N; i++) {
        if (calc[i - 1] != b[i - 1]) {
            flip(i);
            counter2++;
        }
    }

    bool flag2 = false;
    if(chk()) flag2 = true;

    if (flag1 && flag2) {
        cout << -1;
    }
    else if (flag1) {
        cout << counter2;
    }
    else if (flag2) {
        cout << counter1;
    }
    else {
        cout << min(counter1, counter2);
    }

    return 0;
}