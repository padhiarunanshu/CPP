#include <bits/stdc++.h>
using namespace std;

class X {
private:
    std::set<char> _subStr;
    // std::string _str;

public:

    int lengthOfLongestSubstring(const std::string str) {
        int len = 0;
        for(char c : str) {
            if(_subStr.insert(c).second != false) {

            } else {

            }
        }
        return len;
    }

};

int main() {

    X ox;
    std::string str = "pwwpkw";

    cout << "Max length = " << ox.lengthOfLongestSubstring(str) << endl;
}