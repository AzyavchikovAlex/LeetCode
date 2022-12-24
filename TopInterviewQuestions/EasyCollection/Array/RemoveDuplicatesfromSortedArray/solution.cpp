class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int pastle_pos = 1;
        for(int i = 1; i < nums.size(); ++i){
            if (nums[i] != nums[i-1]) {
                nums[pastle_pos++] = nums[i];
            }
        }
        return pastle_pos;
    }
};
