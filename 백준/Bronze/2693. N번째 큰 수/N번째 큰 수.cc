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

using namespace std;

int T;
int num[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> T;

    while(T--) {
        for (int i = 0; i < 10; i++) {
            cin >> num[i];
        }
        sort(num, num + 10);

        cout << num[7] << '\n';
    }

    return 0;
}