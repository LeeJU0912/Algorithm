#include <iostream>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <string>
#include <vector>
#include <tuple>
#include <functional>
#include <map>
#include <set>
#include <cstring>
#include <array>
#include <climits>

using namespace std;

priority_queue<int, vector<int>, greater<int>> pq1;
priority_queue<int> pq2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        if (temp == 0) {
            if (pq1.empty() && pq2.empty()) {
                cout << "0" << '\n';
            }
            else {
                if (pq1.empty()) {
                    cout << pq2.top() << '\n';
                    pq2.pop();
                }
                else if (pq2.empty()) {
                    cout << pq1.top() << '\n';
                    pq1.pop();
                }
                else {
                    if (pq1.top() < -pq2.top()) {
                        cout << pq1.top() << '\n';
                        pq1.pop();
                    }
                    else {
                        cout << pq2.top() << '\n';
                        pq2.pop();
                    }
                }
            }
        }
        else if (temp > 0) {
            pq1.push(temp);
        }
        else {
            pq2.push(temp);
        }
    }

    return 0;
}