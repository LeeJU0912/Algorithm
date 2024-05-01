#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, M;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq1;
priority_queue<pair<int, int>> pq2;
int key[100001];

int main() {
    FastIO

    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        pq1.push({b, a});
        pq2.push({b, a});
        key[a] = b;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        string order;
        cin >> order;

        if (order == "recommend") {
            int a;
            cin >> a;

            if (a == -1) {
                while(pq1.top().first != key[pq1.top().second]) {
                    pq1.pop();
                }
                cout << pq1.top().second << '\n';
            }
            else {
                while(pq2.top().first != key[pq2.top().second]) {
                    pq2.pop();
                }
                cout << pq2.top().second << '\n';
            }
        }
        else if (order == "add") {
            int a, b;
            cin >> a >> b;
            pq1.push({b, a});
            pq2.push({b, a});
            key[a] = b;
        }
        else {
            int a;
            cin >> a;
            key[a] = -1;
        }
    }

    return 0;
}