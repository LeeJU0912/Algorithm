#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    queue<int> q;

    int N;

    cin >> N;

    while(true) {
        int temp;
        cin >> temp;
        if (temp == -1) break;
        if (temp == 0) {
            if (q.empty()) continue;
            else {
                q.pop();
                continue;
            }
        }
        if (q.size() == N) continue;
        else {
            q.push(temp);
        }
    }

    if (q.empty()) {
        cout << "empty" << '\n';
    }

    while(!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }

    return 0;
}