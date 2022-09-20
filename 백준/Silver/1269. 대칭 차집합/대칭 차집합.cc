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

using namespace std;

int x, y;
set<int> a;
int counter;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> x >> y;

    for (int i = 0; i < x + y; i++) {
        int temp;
        cin >> temp;
        if (a.find(temp) != a.end()) {
            counter++;
            continue;
        }
        a.insert(temp);
    }
    cout << a.size() - counter;

    return 0;
}