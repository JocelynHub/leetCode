//递归实现
#include <vector>
using namespace std;
bool binary_search(vector<int> &sort_array,int begin,int end,int target)
{
    if(begin > end)
        return false;
    int mid = (begin + end) / 2;
    if(target == sort_array[mid])
    {
        return true;
    }
    if(target < sort_array[mid])
        return binary_search(sort_array,begin,mid - 1,target);
    if(target > sort_array[mid])
        return binary_search(sort_array,mid + 1,end,target);
}

//循环实现
bool binary_search1(vector<int>&sort_array,int target)
{
    int begin = 0;
    int end = sort_array.size() - 1;
    while(begin < end)
    {
        int mid = (begin + end) / 2;
        if(target == sort_array[mid])
            return true;
        if(target < sort_array[mid])
            end = mid - 1;
        if(target > sort_array[mid])
            begin = mid + 1;
    }
    return false;

}