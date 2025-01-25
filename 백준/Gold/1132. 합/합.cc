#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int N;
string s[50];

bool notZero[50];
vector<pair<long long, int>> cnt;

int convert[10];
long long ans;

void calc() {
    long long tmp = 0;
    long long now = 0;

    for (int i = 0; i < N; i++) {
        now = 0;

        for (int j = 0; j < s[i].size(); j++) {
            now *= 10;
            now += convert[s[i][j] - 'A'];
        }

        tmp += now;
    }

    ans = max(ans, tmp);
}

int main() {
    FastIO

    memset(convert, -1, sizeof(convert));
    cnt = vector<pair<long long, int>>(10);

    for (int i = 0; i < 10; i++) {
        cnt[i].second = i;
    }

    cin >> N;
    for (int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;

        s[i] = tmp;

        notZero[tmp[0] - 'A'] = true;

        long long multi = 1;
        for (int j = tmp.size() - 1; j >= 0; j--) {
            cnt[tmp[j] - 'A'].first += multi;
            multi *= 10;
        }
    }

    sort(cnt.begin(), cnt.end());

    for (auto x : cnt) {
        if (!notZero[x.second]) {
            convert[x.second] = 0;
            break;
        }
    }

    int number = 1;
    for (int i = 0; i < cnt.size(); i++) {
        if (convert[cnt[i].second] == -1) {
            convert[cnt[i].second] = number++;
        }
    }

    calc();

    cout << ans;

    return 0;
}