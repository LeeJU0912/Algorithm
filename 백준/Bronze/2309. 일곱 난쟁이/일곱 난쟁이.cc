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

using namespace std;

int dwarf[9];
int counter;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    for (int i = 0; i < 9; i++) {
        cin >> dwarf[i];
    }

    sort(dwarf, dwarf + 9);


    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            int sum = 0;
            int temp, temp2;
            temp = dwarf[i];
            temp2 = dwarf[j];
            dwarf[i] = 0;
            dwarf[j] = 0;
            for (int k = 0; k < 9; k++) {
                sum += dwarf[k];
            }
            if (sum == 100) {
                for (int k = 0; k < 9; k++) {
                    if (dwarf[k]) cout << dwarf[k] << '\n';
                }
                return 0;
            }
            dwarf[i] = temp;
            dwarf[j] = temp2;
        }
    }

    return 0;
}