class Solution {
public:
    static bool cmp(int a,int b)
    {
        return to_string(a)+to_string(b)<to_string(b)+to_string(a);
    }
    string PrintMinNumber(vector<int> numbers)
    {
        string res;
        const int n=numbers.size();
        sort(numbers.begin(),numbers.end(),cmp);
        for(auto i:numbers)
            res+=to_string(i);
        return res;
    }
};
