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

int N, M;

deque<int> dq;

int counter;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;

        int idx = 0;

        for (int j = 0; j < dq.size(); j++) {
            if (temp == dq[j]) {
                idx = j;
                break;
            }
        }

        while(dq.front() != temp) {
            counter++;
            if (dq.size() / 2 < idx) { // 뒤로 돌리기
                int temp2 = dq.back();
                dq.pop_back();
                dq.push_front(temp2);
            }
            else {
                int temp2 = dq.front();
                dq.pop_front();
                dq.push_back(temp2);
            }
        }

        dq.pop_front();
    }

    cout << counter;

    return 0;
}