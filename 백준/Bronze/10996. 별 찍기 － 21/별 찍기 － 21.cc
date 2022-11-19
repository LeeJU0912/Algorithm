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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    int N;
    cin >> N;

    if (N & 1) {
        for (int i = 0; i < N * 2; i++) {
            if (i & 1) {
                for (int j = 0; j < N - 1; j++) {
                    if (j & 1) {
                        cout << '*';
                    }
                    else {
                        cout << ' ';
                    }
                }
                cout << '\n';
            }
            else {
                for (int j = 0; j < N; j++) {
                    if (j & 1) {
                        cout << ' ';
                    }
                    else {
                        cout << '*';
                    }
                }
                cout << '\n';
            }
        }
    }
    else {
        for (int i = 0; i < N * 2; i++) {
            if (i & 1) {
                for (int j = 0; j < N; j++) {
                    if (j & 1) {
                        cout << '*';
                    }
                    else {
                        cout << ' ';
                    }
                }
                cout << '\n';
            }
            else {
                for (int j = 0; j < N - 1; j++) {
                    if (j & 1) {
                        cout << ' ';
                    }
                    else {
                        cout << '*';
                    }
                }
                cout << '\n';
            }
        }
    }


    return 0;
}