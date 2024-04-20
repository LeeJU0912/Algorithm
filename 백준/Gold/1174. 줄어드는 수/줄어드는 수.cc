#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;

vector<long long> values;

void makeValue(int lastIdx, long long hap) {
    values.push_back(hap);

    for (int i = 0; i < lastIdx; i++) {
        makeValue(i, hap * 10 + i);
    }
}

int main() {
    FastIO

    values.push_back(0);
    for (int j = 1; j <= 9; j++) {
        makeValue(j, j);
    }

    sort(values.begin(), values.end());
    
    cin >> N;

    if (N - 1 >= values.size()) {
        cout << -1;
    }
    else {
        cout << values[N - 1];
    }

    return 0;
}