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

int yut[4];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 3; i++) {
        int temp = 0;
        for (int j = 0; j < 4; j++) {
            cin >> yut[j];
            if (yut[j]) temp++;
        }

        if (temp == 0) {
            cout << 'D' << '\n';
        }
        else if (temp == 1) {
            cout << 'C' << '\n';
        }
        else if (temp == 2) {
            cout << 'B' << '\n';
        }
        else if (temp == 3) {
            cout << 'A' << '\n';
        }
        else {
            cout << 'E' << '\n';
        }

    }

    return 0;
}