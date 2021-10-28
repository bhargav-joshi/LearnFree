class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<int> v;
        int k=0;
        vector<vector<int>> mr(r , vector<int> (c, 0));;
        int a=mat.size();
        int b=mat[0].size();
        if(a*b != r*c)
        {
            return mat;
        }
            
        for(int i=0;i<mat.size();i++)
        {
            
            for(int j=0;j<mat[i].size();j++)
            {
               v.push_back(mat[i][j]);
            }
        }
       
       for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
               mr[i][j]=v[k++];
               
            }
        }
        v.clear();
        
        
        return mr;
    }
};
