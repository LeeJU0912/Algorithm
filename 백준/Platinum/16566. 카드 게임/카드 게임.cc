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

int N, M, K;
vector<int> pick;
int god;
int parent[4000001];

int Find_parent(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find_parent(parent[x]);
}

void Union(int x, int y) {
    parent[x] = y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    cin >> N >> M >> K;

    for (int i = 1; i <= 4000000; i++) {
        parent[i] = i;
    }

//    for (int i = 1; i <= M; i++) {
//        int temp;
//        cin >> temp;
//        parent[i] = temp;
//    }



    for (int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        pick.emplace_back(temp);
    }


    sort(pick.begin(), pick.end());

    for (int i = 0; i < K; i++) {
        cin >> god;

        int temp;

        if (pick.back() <= god) {
            temp = 1;
        }
        else {
            temp = lower_bound(pick.begin(), pick.end(), god) - pick.begin();
            if (pick[temp] == god) {
                temp += 1;
            }
        }

        temp = Find_parent(temp);


        cout << pick[temp] << '\n';

        Union(temp, temp + 1);
        //pick.erase(pick.begin() + temp);

    }

    return 0;
}