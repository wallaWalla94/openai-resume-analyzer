#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> path;
        backtrack(0, s, path, result);
        return result;
    }

private:
    void backtrack(int start, const string& s, vector<string>& path, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (isPalindrome(s, start, end)) {
                path.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, path, result);
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "aab";

    vector<vector<string>> result = sol.partition(s);

    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& part : group) {
            cout << "\"" << part << "\" ";
        }
        cout << "]" << endl;
    }

    return 0;
}