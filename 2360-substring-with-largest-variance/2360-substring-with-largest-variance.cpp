class Solution {
public:
    int largestVariance(string s) {
        vector<int>count(26);
        for(int i=0; i<s.length(); i++){
            count[s[i]-'a']++;
        }
        int result = 0;
        for(char first='a'; first<='z';first++){
            for(char second = 'a'; second<='z'; second++){
                if(count[first-'a']==0 || count[second-'a']==0){
                    continue;
                }
                int firstcount = 0;
                int secondcount = 0;
                
                bool seen = false;
                for(char &ch : s){
                    if(ch==first){
                        firstcount++;
                    }
                    if (ch==second){
                        secondcount++;
                    }
                    if(secondcount>0){
                        result = max(result,firstcount-secondcount);
                    }
                    else{
                        if(seen==true){
                            result = max(result,firstcount-1);
                        }
                    }
                    if (secondcount>firstcount){
                        firstcount = 0;
                        secondcount = 0;
                        seen = true;
                    }
                }
                
            }
        }
        return result;
    }
};