#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

bool chk[100001];

deque<int> dq;

int main() {
    FastIO

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (!temp) {
            chk[i] = true;
        }
    }

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        if (chk[i]) dq.push_front(temp);
    }

    int M;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        dq.push_back(temp);
        int now = dq.front();
        dq.pop_front();
        

        cout << now << ' ';
    }

    return 0;
}