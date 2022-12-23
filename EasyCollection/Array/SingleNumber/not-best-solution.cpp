#include <unordered_set>

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::unordered_set<int> unique;
        for( int number : nums){
            if(unique.find(number) == unique.end()) {
                unique.insert(number);
            } else {
                unique.erase(number);
            }
        }
        return (*unique.begin());
    }
};
