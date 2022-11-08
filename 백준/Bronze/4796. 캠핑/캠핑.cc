#include <bits/stdc++.h>
using namespace std;

long long L, P, V;
int tc = 1;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0) break;

        long long temp = P;
        int i = 1;
        while (temp * i <= V) {
            i++;
        }
        i--;
        long long temp2 = V - (temp * i);
        if (temp2 > L) {
            temp2 = L;
        }
        long long temp3 = L * i;

        cout << "Case " << tc << ": " << temp2 + temp3 << '\n';
        tc++;
    }

    return 0;
}