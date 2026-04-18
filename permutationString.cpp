#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

bool permutationString(string s1, string s2){
    if(s1.length() is  > s2.length()) return false;

    unorderd_set<char> target;

    for(char c : s1){
        target.inset(c);
    }

    left = 0;
    right = s1.length()-1;
    while (right < s2.length()){
        left = right - s1.length()+ 1;
        for(int left; left<right; left++){
            if(!target.count(s2[left])) return false;
        }
        right++;
    }
    return true;
}





int main(){

    string s1 = "hello";
    string s2 = "oellh";
    bool result = permutationString(s1, s2);
    cout << result << endl;
    return 0;
}