    #include <bits/stdc++.h>
    using namespace std;

    int main() {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        map<string, pair<int, int>> m = {
                {"black", {0, 1}},
                {"brown", {1, 10}},
                {"red", {2, 100}},
                {"orange", {3, 1000}},
                {"yellow", {4, 10000}},
                {"green", {5, 100000}},
                {"blue", {6, 1000000}},
                {"violet", {7, 10000000}},
                {"grey", {8, 100000000}},
                {"white", {9, 1000000000}}
        };
        long long tmp = 0;
        string temp;
        for (int i = 0; i < 2; i++) {

            cin >> temp;

            tmp *= 10;
            tmp += m[temp].first;
        }

        cin >> temp;

        cout << tmp * m[temp].second;

        return 0;
    }