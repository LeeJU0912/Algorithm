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
#include <list>

using namespace std;

int L, C;
char save[16];

void solve(int idx, int moeum_counter, int jaum_counter, string go) {
    go += save[idx];

    if (save[idx] == 'a' || save[idx] == 'e' || save[idx] == 'i' || save[idx] == 'o' || save[idx] == 'u') {
        moeum_counter++;
    }
    else {
        jaum_counter++;
    }

    if (go.length() == L) {
        if (moeum_counter == 0 || jaum_counter < 2) return;
        cout << go << '\n';
        return;
    }


    for (int i = idx + 1; i < C; i++) {
        solve(i, moeum_counter, jaum_counter, go);
    }


}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> L >> C;

    for (int i = 0; i < C; i++) {
        char temp;
        cin >> temp;
        save[i] = temp;
    }
    sort(save, save + C);

    for (int i = 0; i < C; i++) {
        solve(i, 0, 0, "");
    }

    return 0;
}