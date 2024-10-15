class Solution {
public:
    int partitionString(string s) {
        int flag=0;
        int count=1;
        for(int i=0;i<s.length();i++){
            char ch=s[i];

            int mask=1;
            int c=ch-'a';
            mask=mask<<c;
            
            if((flag&mask)!=0){
                //already exists
                //reset flag
                cout<<"reset"<<endl;
                flag=0;
                count++;
            }
            
            flag=flag|mask;
            
            
        }

        return count;
    }
};