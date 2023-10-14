#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
vector<int> save;

long long ans;

int main() {
    FastIO

    cin >> N;

    long long hap = 0;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        save.push_back(temp);

        hap += temp;
    }

    for (int i = 0; i < N; i++) {
        ans += (hap - save[i]) * save[i];
    }

    cout << ans / 2;

    return 0;
}