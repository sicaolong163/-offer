class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k)
    {
        if(data.size()==0)return 0;
        int dict[128]={0};
        for(auto i:data)
           dict[i]++;
        return dict[k];
    }
};
