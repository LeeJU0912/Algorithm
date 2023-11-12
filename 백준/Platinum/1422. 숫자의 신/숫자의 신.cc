#include <bits/stdc++.h>
#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
using namespace std;

int K, N;
vector<string> save;

vector<string> ans;

bool comp1(const string& a, const string& b) {
    if (a.length() < b.length()) {
        return false;
    }
    else if (a.length() > b.length()) {
        return true;
    }
    else {
        return a > b;
    }
}

bool comp2(const string& a, const string& b) {
    if (a.length() < b.length()) {
        for (int i = 0; i < b.length(); i += a.length()) {
            for (int j = 0; i + j < min(b.length(), i + a.length()); j++) {
                if (a[j] < b[i + j]) return false;
                else if (a[j] > b[i + j]) return true;
            }
        }

        for (int i = 0; i < a.length(); i++) {
            if (a[i] < a[(b.length() % a.length() + i) % a.length()]) return true;
            else if (a[i] > a[(b.length() % a.length() + i) % a.length()]) return false;
        }

    }
    else if (a.length() > b.length()) {
        for (int i = 0; i < a.length(); i += b.length()) {
            for (int j = 0;  i + j < min(a.length(), i + b.length()); j++) {
                if (a[i + j] < b[j]) return false;
                else if (a[i + j] > b[j]) return true;
            }
        }

        for (int i = 0; i < b.length(); i++) {
            if (b[i] < b[(a.length() % b.length() + i) % b.length()]) return false;
            else if (b[i] > b[(a.length() % b.length() + i) % b.length()]) return true;
        }
    }
    else {
        return a > b;
    }
}

int main() {
    FastIO

    cin >> K >> N;
    save = vector<string>(K);

    for (int i = 0; i < K; i++) {
        cin >> save[i];
    }

    sort(save.begin(), save.end(), comp1);

    for (int i = 0; i < N - K; i++) {
        ans.push_back(save[0]);
    }
    for (int i = 0; i < K; i++) {
        ans.push_back(save[i]);
    }

    sort(ans.begin(), ans.end(), comp2);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
    }

    return 0;
}