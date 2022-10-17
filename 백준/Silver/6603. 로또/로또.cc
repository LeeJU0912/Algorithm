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
#include <cstdlib>
#include <utility>
#include <regex>
#include <numeric>
#include <cctype>
#include <iomanip>
#include <bitset>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include <unordered_map>
#include <cfloat>
#include <list>

using namespace std;

int board[13];
int visited[13];
int N;

void dfs(int idx, int counter, vector<int> save) {
    save.push_back(board[idx]);

    if (counter == 6) {
        for (auto i : save) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    for (int i = idx + 1; i < N; i++) {
        if (visited[i]) continue;
        visited[i] = 1;
        dfs(i, counter + 1, save);
        visited[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        cin >> N;
        vector<int> save;

        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> board[i];
        }

        for (int i = 0; i < N; i++) {
            visited[i] = 1;
            dfs(i, 1, save);
            visited[i] = 0;
        }
        cout << '\n';

    }


    return 0;
}