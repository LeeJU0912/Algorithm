#include <bits/stdc++.h>

using namespace std;

vector<tuple<int, int, int, string>> dat;

bool compare(tuple<int, int, int, string> t1, tuple<int, int, int, string> t2) {
    if (get<0>(t1) == get<0>(t2) && get<1>(t1) == get<1>(t2) && get<2>(t1) == get<2>(t2)) {
        return get<3>(t1) < get<3>(t2);
    }
    if (get<0>(t1) == get<0>(t2) && get<1>(t1) == get<1>(t2)) {
        return get<2>(t1) > get<2>(t2);
    }
    if (get<0>(t1) == get<0>(t2)) {
        return get<1>(t1) < get<1>(t2);
    }
    return get<0>(t1) > get<0>(t2);
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        int a, b, c;
        cin >> a >> b >> c;

        dat.emplace_back(make_tuple(a, b, c, s));


    }

    sort(dat.begin(), dat.end(), compare);

    for (auto i : dat) {
        cout << get<3>(i) << '\n';
    }
    return 0;
}