#include <unordered_map>

class Solution {
 public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    std::unordered_map<int, int> amount;
    for (int number : nums1) {
      amount[number]++;
    }
    std::vector<int> answer;
    answer.reserve(nums2.size());
    for (int number : nums2) {
      auto pos = amount.find(number);
      if (pos == amount.end()) {
        continue;
      }
      pos->second--;
      answer.push_back(number);
      if (pos->second == 0) {
        amount.erase(pos);
      }
    }
    return answer;
  }
};
