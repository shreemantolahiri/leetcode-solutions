class Solution {
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> res= new ArrayList<>();

        List<Integer> first=new ArrayList<>();
        first.add(1);
        res.add(first);
        for(int i=1;i<numRows;i++){
            List<Integer> curr= new ArrayList<>();
            curr.add(1);
            int width=i-1;
            for(int j=0;j<width;j++){
                int curr_ind=j+1;
                int prev_ind=j;
                // System.out.println("i: "+i+" j: "+j+" curr_ind: "+curr_ind+" width: "+width);
                curr.add(res.get(i-1).get(curr_ind)+res.get(i-1).get(prev_ind));
            }
            curr.add(1);
            res.add(curr);
        }

        return res;
    }
}