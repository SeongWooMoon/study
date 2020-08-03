class Solution {
public:
  int pivotIndex(vector<int>& nums) {
      
    if (nums.size() == 0)
      return -1;
            
    int total = 0;
    for (int x : nums) total += x;
    
    int sum = 0;
    for (int i = 0; i < nums.size(); sum+=nums[i++]){
      if (sum * 2 == (total - nums[i])) return i;
    }
    
    return -1;
  }
};
