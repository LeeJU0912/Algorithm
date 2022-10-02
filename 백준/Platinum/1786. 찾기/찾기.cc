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

string S;
string W;

vector<int> result;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    getline(cin, S);
    getline(cin, W);

    vector<int> fail(W.size(), 0);
    for (int i = 1, j = 0; i < W.length(); i++) {
        while (j > 0 && W[i] != W[j]) {
            j = fail[j - 1];
        }
        if (W[i] == W[j]) {
            fail[i] = ++j;
        }
    }


    for (int i = 0, j = 0; i < S.length(); i++) {
        while (j > 0 && S[i] != W[j]) {
            j = fail[j - 1];
        }
        if (S[i] == W[j]) {
            if (j == W.length() - 1) {
                result.push_back(i - W.length() + 2);
                j = fail[j];
            }
            else j++;
        }
    }

    cout << result.size() << '\n';
    for (auto i : result) {
        cout << i << '\n';
    }

    return 0;
}