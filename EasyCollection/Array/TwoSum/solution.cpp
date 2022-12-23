#include <unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> unique;
        for (int pos = 0; pos < nums.size(); ++pos) {
            int number = nums[pos];
            auto existing_element = unique.find(number);
            if (existing_element != unique.end()) {
                if (2 * number == target) {
                    return {existing_element->second, pos};
                }
            } else {
                unique[number] = pos;
            }
        }
        for (int pos = 0; pos < nums.size(); ++pos) {
            if (target - nums[pos] == nums[pos]) {
                continue;
            }
            auto finding_pos = unique.find(target - nums[pos]);
            if (finding_pos == unique.end()) {
                continue;
            }
            return {pos, finding_pos->second};
        }
        return {};
    }
};
