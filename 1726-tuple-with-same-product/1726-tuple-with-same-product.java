class Solution {
    public int tupleSameProduct(int[] nums) {
        int n = nums.length;
        Map<Integer, Integer> map = new HashMap<>();
        if (n < 4)
            return 0;
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                // i _ _ j
                int x = nums[i] * nums[j];
                map.put(x, map.getOrDefault(x, 0) + 1);

                // if(map.get(x)>1) count+=8;
            }
        }
        for (int value : map.values()) {
            if (value > 1) {
                int summation=value*(value-1)/2;
                count+=8*summation;
            }
        }
        return count;
    }
}