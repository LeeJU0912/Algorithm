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

using namespace std;

int N;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    while(true) {
        cin >> N;
        if (N == 0) {
            break;
        }

        int counter = 0;


        for (int i = N + 1; i <= N * 2; i++) {
            bool check = false;
            if (i == 2) {
                counter++;
                continue;
            }
            else if (i % 2 == 0) {
                continue;
            }
            for (int j = 3; j <= sqrt(i); j += 2) {
                if (i % j == 0) {
                    check = true;
                    break;
                }
            }
            if (!check) {
                counter++;
            }
        }
        cout << counter << '\n';
    }
    
    return 0;
}