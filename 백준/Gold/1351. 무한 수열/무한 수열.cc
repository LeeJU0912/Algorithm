#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

long long N, P, Q;
map<long long, long long> save;
set<long long> st;

void dividing(long long now) {
    if (st.find(now) != st.end() || now == 0) return;
    st.insert(now);

    dividing(now / P);
    dividing(now / Q);
}

int main() {
    FastIO

    cin >> N >> P >> Q;

    save.insert({0, 1});

    dividing(N);

    for (auto i : st) {
        if (i == 0) continue;
        save[i] = save[i / P] + save[i / Q];
    }

    cout << save[N];

    return 0;
}