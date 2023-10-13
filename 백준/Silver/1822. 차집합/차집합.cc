#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

set<int> st;

int main() {
    FastIO

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        st.insert(temp);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        st.erase(temp);
    }

    cout << st.size() << '\n';

    for (int i : st) {
        cout << i << ' ';
    }


    return 0;
}