#include <unordered_set>

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_set<int> unique;
        for( int number : nums){
            if(unique.find(number) != unique.end()) {
                return true;
            } else {
                unique.insert(number);
            }
        }
        return false;
    }
};
