/*
A query word matches a given pattern if we can insert lowercase letters to the pattern word so that it equals the query. (We may insert each character at any position, and may insert 0 characters.)

Given a list of queries, and a pattern, return an answer list of booleans, where answer[i] is true if and only if queries[i] matches the pattern.

 

Example 1:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FB"
Output: [true,false,true,true,false]
Explanation: 
"FooBar" can be generated like this "F" + "oo" + "B" + "ar".
"FootBall" can be generated like this "F" + "oot" + "B" + "all".
"FrameBuffer" can be generated like this "F" + "rame" + "B" + "uffer".
Example 2:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBa"
Output: [true,false,true,false,false]
Explanation: 
"FooBar" can be generated like this "Fo" + "o" + "Ba" + "r".
"FootBall" can be generated like this "Fo" + "ot" + "Ba" + "ll".
Example 3:

Input: queries = ["FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"], pattern = "FoBaT"
Output: [false,true,false,false,false]
Explanation: 
"FooBarTest" can be generated like this "Fo" + "o" + "Ba" + "r" + "T" + "est".
 

Note:

1 <= queries.length <= 100
1 <= queries[i].length <= 100
1 <= pattern.length <= 100
All strings consists only of lower and upper case English letters.
*/

class Solution {
public:
    vector<bool> camelMatch(vector<string>& q, string p) {
        
        vector<bool> res;
        vector<string> subs;
        int p_size=p.length();
        string str="";
        int flag=0,i=0,countp=0;
        
        while(1){
            if(isupper(p[i])){
                countp++;
                if(i==0) {//subs.push_back(p[0]);
                    i++;
                    continue;
                }
                str+=p[i-1];
                subs.push_back(str);
                str="";
                i++;
                if(i==p_size){
                    str+=p[i-1];
                    subs.push_back(str);
                    break;
                }
            }
            else{
                str+=p[i-1];
                i++;
                if(i==p_size){
                    str+=p[i-1];
                    subs.push_back(str);
                    break;
                }    
            }
        }
        
        //for(int i=0;i<p_size;i++)
        
        for(int i=0;i<q.size();i++){
            size_t found=-1;
            flag=0;
            for(int j=0;j<subs.size();j++){
                while(true){
                    found = q[i].find(subs[j],found+1);
                    if (found != string::npos)
                        flag++;
                    else { found=-1; break;}
                }    
            }
            if(flag == subs.size()){ 
                int countq=0;
                for(int k=0;k<q[i].size();k++){
                    if(isupper(q[i][k])) countq++;
                }
                if(countp==countq) res.push_back(true);
                else res.push_back(false);
            }    
            else res.push_back(false);
        }
        return res;
    }
};

_____________________________________

class Solution {
    inline bool check(const string& q, const string& p) const
    {
        int j = 0;
        for(auto c: q) {
            if(c == p[j])
                ++j;
            else if(isupper(c))
                return false;
        }

        return j == p.size();
    }
    
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ret;
        
        ret.reserve(queries.size());
        for(const auto& q: queries)
            ret.push_back(check(q, pattern));
        
        return ret;
    }
};