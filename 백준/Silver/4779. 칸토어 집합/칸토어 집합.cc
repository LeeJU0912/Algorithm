#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool calc[531442];

void solve(int start, int end) {
    if (end - start < 2) return;
    
    int gap = end - start + 1;
    int empty_start = start + gap / 3;
    int empty_end = end - gap / 3;

    for (int i = empty_start; i <= empty_end; i++) {
        calc[i] = false;
    }

    solve(start, empty_start - 1);
    solve(empty_end + 1, end);
}

int main() {
    FastIO

    memset(calc, true, sizeof(calc));
    solve(1, 531441);

    int N;
    while(cin >> N) {
        for (int i = 1; i <= pow(3, N); i++) {
            if (calc[i]) {
                cout << '-';
            }
            else {
                cout << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}