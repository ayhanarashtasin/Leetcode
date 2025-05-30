class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        string result=s;
        for(int i=1; i<=s.length()-1; i++){
            string temp = s.substr(i) + s.substr(0,i);
            result = min(temp,result);
        }
        return result;
    }
};