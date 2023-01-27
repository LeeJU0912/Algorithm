#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int main() {
    FastIO

    int N;
    cin >> N;

    int a, b;
    cin >> a >> b;

    int c;
    cin >> c;

    int calorie = c;
    int cost = a;

    vector<int> topping(N);

    for (int i = 0; i < N; i++) {
        cin >> topping[i];
    }

    sort(topping.begin(), topping.end(), greater<>());

    int ans = c / a;

    for (int i = 0; i < N; i++) {
        calorie += topping[i];
        cost += b;
        ans = max(ans, calorie / cost);
    }

    cout << ans;

    return 0;
}