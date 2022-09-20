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
vector<int> a;
vector<int> b;
int counter;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> x >> y;

    for (int i = 0; i < x; i++) {
        int temp;
        cin >> temp;
        a.push_back(temp);
    }

    for (int i = 0; i < y; i++) {
        int temp;
        cin >> temp;
        b.push_back(temp);
    }

    sort(b.begin(), b.end());

    for (int i = 0; i < x; i++) {
        if (binary_search(b.begin(), b.end(), a[i])) {
            counter++;
        }
    }

    cout << x + y - counter * 2;

    return 0;
}