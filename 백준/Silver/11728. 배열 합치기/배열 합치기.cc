#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


    priority_queue<int, vector<int>, greater<>> pq;

    int a, b;
    cin >> a >> b;

    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    for (int i = 0; i < b; i++) {
        int temp;
        cin >> temp;
        pq.push(temp);
    }

    while(!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }

    return 0;
}