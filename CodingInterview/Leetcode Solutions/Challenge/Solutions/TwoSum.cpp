class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap{std::make_pair(nums[0], 0)};
        
        for (size_t i = 1; i < nums.size(); ++i){
            auto it = hashmap.find(target - nums[i]);
            if (it != hashmap.end() && it->second != i){
                return {it->second, i};
            }
            hashmap[nums[i]] = i;
        }
        
        return {};
    }
};
