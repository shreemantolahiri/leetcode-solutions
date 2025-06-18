class Solution {
    public int[][] arrayListToArray(ArrayList<ArrayList<Integer>> arr){
        int m=arr.size();
        int n=arr.get(0).size();
        // System.out.println(m+" "+n);
        int nums[][]=new int[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                nums[i][j]=arr.get(i).get(j);
            }
        }
        return nums;
    }
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n=nums.length;
        int subArrays=n/3;
        ArrayList<ArrayList<Integer>> arr=new ArrayList<>();
        
        for(int i=0;i<n;i+=3){
            int min=nums[i];
            int max=nums[i+2];
            if(max-min>k) return (new int[0][0]);
            else{
                ArrayList<Integer> temp=new ArrayList<>();
                temp.add(nums[i]);
                temp.add(nums[i+1]);
                temp.add(nums[i+2]);
                arr.add(temp);
            }
        }
        // System.out.println("done");
        int res[][]=arrayListToArray(arr);

        return res;
    }
}