#include <iostream>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        unordered_set<char> occ;
        int n = s.size();
        int right_point = -1;
        int length = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                occ.erase(s[i - 1]);
            }

            while (right_point + 1 < n && occ.count(s[right_point + 1])) {
                occ.insert(s[right_point + 1]);
                ++right_point;
            }

            length = max(length, right_point + 1 - i);
        }
        return length;
    }
};
