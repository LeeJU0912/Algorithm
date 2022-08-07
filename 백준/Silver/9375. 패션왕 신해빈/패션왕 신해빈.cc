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


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int TC;

    cin >> TC;

    for (int i = 0; i < TC; i++) {
        map<string, int> m;
        map<string, int>::iterator iter;

        int N;
        int ans;
        string s1, s2;

        ans = 1;

        cin >> N;

        for (int j = 0; j < N; j++) {
            cin >> s1 >> s2;

            if (m.find(s2) == m.end()) {
                m[s2] = 1;
            }
            else {
                m[s2]++;
            }
        }
        for (iter = m.begin(); iter!= m.end(); iter++) {
            ans *= iter->second + 1;
        }
        cout << ans - 1 << '\n';
    }

    return 0;
}