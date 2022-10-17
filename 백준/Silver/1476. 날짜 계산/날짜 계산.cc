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

int E, S, M;
int ans;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> E >> S >> M;

    while(E != 1 || S != 1 || M != 1) {
        ans++;
        E -= 1;
        if (E == 0) {
            E = 15;
        }
        S -= 1;
        if (S == 0) {
            S = 28;
        }
        M -= 1;
        if (M == 0) {
            M = 19;
        }
    }

    cout << ans + 1;

    return 0;
}