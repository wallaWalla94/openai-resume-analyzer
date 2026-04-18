#include <vector>
#include <algorithm>
#include <iostream>


using namespace std;

vector<pair<int,int>> mergeArray(vector<pair<int,int>> intervals) {
    if (intervals.empty()) return {};

    sort(intervals.begin(), intervals.end());

    vector<pair<int,int>> result;
    result.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i].first <= result.back().second) {
            result.back().second = max(result.back().second, intervals[i].second);
        } else {
            result.push_back(intervals[i]);
        }
    }

    return result;
}

int main() {
    vector<pair<int,int>> intervals = {{1,3}, {2,6}, {8,10}, {15,18}};

    vector<pair<int,int>> result = mergeArray(intervals);

    cout << "Merged intervals: ";
    for (int i = 0; i < result.size(); i++) {
        cout << "[" << result[i].first << "," << result[i].second << "] ";
    }
    cout << endl;

    return 0;
}