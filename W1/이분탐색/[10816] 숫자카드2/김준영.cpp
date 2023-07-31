#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int upperBound(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size();

    while (left < right) {
        int mid = (left + right) / 2;

        if (arr[mid] <= target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> cards(n);

    for (int i = 0; i < n; ++i) {
        cin >> cards[i];
    }

    sort(cards.begin(), cards.end());

    int m;
    cin >> m;

    vector<int> targets(m);

    for (int i = 0; i < m; ++i) {
        cin >> targets[i];
    }

    for (int i = 0; i < m; ++i) {
        int lower = lowerBound(cards, targets[i]);
        int upper = upperBound(cards, targets[i]);
        int count = upper - lower;
        cout << count << ' ';
    }

    return 0;
}
