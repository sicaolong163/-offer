class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) 
    {
        //map<int,int>dict;
        int dict[128]={0};// 这里一定要初始化；
        for(int i=0;i<length;i++)
            dict[numbers[i]]++;
        int i=0;
        for(i=0;i<length;i++)
            if(dict[numbers[i]]!=1)
            {
                *duplication=numbers[i];
                break;
            }
        return i==length?false:true;
    }
};
