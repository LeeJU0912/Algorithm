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

using namespace std;

int N;
int counter;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N;

    int temp = 0;
    int j = 0;

    for (int i = 1; i <= N; i++) {
        temp = i;
        while (temp != 0) {
            int temp2 = temp % 10;
            v.push_back(temp2);
            temp /= 10;
        }

        j = 0;

        if (v.size() <= 2) {
            counter++;
            v.clear();
            continue;
        }

        else if (v.size() > 2) {
            while (j <= v.size() - 3) {
                if (v[j + 1] - v[j] == v[j + 2] - v[j + 1]) {
                    j++;
                }
                else {
                    break;
                }
            }
            if (j == v.size() - 2) {
                counter++;
            }
        }

        v.clear();
    }

    cout << counter;

    return 0;
}