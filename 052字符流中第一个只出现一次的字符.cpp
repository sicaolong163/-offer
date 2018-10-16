class Solution
{
 private:
    string str;
    int dict[128]={0};
public:
  //Insert one char from stringstream
    void Insert(char ch)
    {
         str.push_back(ch);
          dict[ch]++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(auto c:str)
            if(dict[c]==1)
                return c;
        return '#';
    }

};
