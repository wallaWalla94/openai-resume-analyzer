#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;

bool validParenthesis(string s) {
    stack<char> stringStack;
    for ( char c : s){
        if (c == '(' || c ==  '{' || c == '[' ){
            stringStack.push(c);
        } else{
            if(stringStack.empty()) {
                return false;
            }
            if(c == ')' && stringStack.top() != '('){
                return false;}
            if( c == '}' && stringStack.top() != '{'){
                return false;
            }
            if(c == ']' && stringStack.top() != '['){
                return false;
            }
            stringStack.pop();
    }
    return true;
}


 int main() {
    
        string s = "({[]})";
        cout << validParenthesis(s) << endl;
        return 0;
}

