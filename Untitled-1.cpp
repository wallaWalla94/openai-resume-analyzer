#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

vector<int> twoSum(const vector<int> &array, int target){
    unordered_map<int, int> map;
    for(int i = 0; i < array.size(); i++){
        int objective = target - array[i];
        if(map.count(objective)){
            return {map[objective],i};
        }
        map[array[i]] = i;
    }
    return {};
}


 int main() {

        vector<int> array = {3, 5, -4, 8, 11, 1, -1, 6};
        int target = 9;
        vector<int> result = twoSum(array, target);

        cout << result[0] << " " << result[1] << endl;
    return 0;
}

