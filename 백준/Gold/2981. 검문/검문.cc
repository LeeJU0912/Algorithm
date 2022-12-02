#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    vector<int> v;
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());

    int temp = v[1] - v[0];
    for (int i = 2; i < N; i++) {
        temp = gcd(temp, v[i] - v[i - 1]);
    }

    for (int i = 2; i * i <= temp; i++) {
        if (temp % i == 0) {
            ans.push_back(i);
            ans.push_back(temp / i);
        }
    }
    ans.push_back(temp);

    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());

    for (auto i : ans) {
        cout << i << '\n';
    }

    return 0;
}