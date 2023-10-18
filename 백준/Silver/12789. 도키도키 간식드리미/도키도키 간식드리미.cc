#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
queue<int> s;
stack<int> tmp;

int counter = 1;

int main() {
    FastIO

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;

        s.push(temp);
    }

    while(!s.empty()) {
        int now = s.front();
        s.pop();

        if (now == counter) {
            counter++;
        }
        else {
            tmp.push(now);
        }

        while(!tmp.empty()) {
            int tmp_now = tmp.top();

            if (tmp_now == counter) {
                counter++;
                tmp.pop();
            }
            else break;
        }
    }

    while(!tmp.empty()) {
        int now = tmp.top();
        tmp.pop();

        if (now == counter) {
            counter++;
        }
        else {
            cout << "Sad";
            return 0;
        }
    }

    cout << "Nice";

    return 0;
}