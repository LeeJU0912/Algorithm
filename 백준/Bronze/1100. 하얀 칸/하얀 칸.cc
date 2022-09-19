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

using namespace std;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s[8];
    int counter = 0;

    for (int i = 0; i < 8; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < 8; i++) {
        if (i % 2) {
            for (int j = 1; j < 8; j += 2) {
                if (s[i][j] == 'F') {
                    counter++;
                }
            }
        }
        else {
            for (int j = 0; j < 8; j += 2) {
                if (s[i][j] == 'F') {
                    counter++;
                }
            }
        }
    }

    cout << counter;

    return 0;
}