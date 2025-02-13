#include<bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N, k;
vector<pair<int, int>> save;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> waitingLine;

struct compare {
    bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
        if (a.first.first == b.first.first) {
            return a.first.second < b.first.second;
        }
        else return a.first.first > b.first.first;
    }
};

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, compare> outOrder;

long long ans;

int main() {
    FastIO

    cin >> N >> k;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        save.push_back({a, b});
    }

    for (int i = 1; i <= k; i++) {
        waitingLine.push({0, i});
    }

    for (int i = 0; i < N; i++) {
        int nowID = save[i].first;
        int nowTime = save[i].second;

        int nowLineTime = waitingLine.top().first;
        int nowLineIdx = waitingLine.top().second;
        waitingLine.pop();

        outOrder.push({{nowLineTime + nowTime, nowLineIdx}, nowID});
        waitingLine.push({nowLineTime + nowTime, nowLineIdx});
    }

    for (long long i = 1; i <= N; i++) {
        ans += i * outOrder.top().second;
        outOrder.pop();
    }
    cout << ans;

    return 0;
}