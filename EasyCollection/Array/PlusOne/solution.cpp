class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    std::vector<int> answer(digits);
    for (auto pos = answer.rbegin(); pos != answer.rend(); ++pos) {
      if (*pos != 9) {
        (*pos)++;
        return answer;
      } else {
        *pos = 0;
      }
    }
    answer.insert(answer.begin(), 1);
    return answer;
  }
};
