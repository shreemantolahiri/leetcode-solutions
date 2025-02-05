class Solution {
    public boolean areAlmostEqual(String s1, String s2) {
        int diff=0;

        int n=s1.length();
        int ind1=-1; int ind2=-1;
        for(int i=0;i<n;i++){
            if(s1.charAt(i)!=s2.charAt(i)){
                diff++; 
                if(ind1==-1) ind1=i;
                else ind2=i;
            }
            if(diff>2) return false;
        }

        if(diff==1) return false;
        else if(diff==0) return true;
        else{
            //count==2
            if(s1.charAt(ind1)==s2.charAt(ind2) && 
            s1.charAt(ind2)==s2.charAt(ind1)) return true;
            else return false;
        }
    }
}