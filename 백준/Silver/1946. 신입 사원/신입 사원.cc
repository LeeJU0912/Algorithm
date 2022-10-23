#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int T;

    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<pair<int, int>> grades;

        for (int i = 0; i < N; i++) {
            int a, b;
            cin >> a >> b;
            grades.push_back({a, b});
        }

        sort(grades.begin(), grades.end());

        int temp = 0;
        int result = 1;

        for (int i = 1; i < N; i++) {
            if (grades[temp].second > grades[i].second) {
                result++;
                temp = i;
            }
        }

        cout << result << '\n';
    }

    return 0;
}