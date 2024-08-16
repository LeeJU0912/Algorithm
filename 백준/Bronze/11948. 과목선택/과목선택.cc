#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    vector<int> save(4);
    cin >> save[0] >> save[1] >> save[2] >> save[3];

    int a, b;
    cin >> a >> b;

    sort(save.begin(), save.end(), greater<>());

    cout << save[0] + save[1] + save[2] + max(a, b);
    
    return 0;
}