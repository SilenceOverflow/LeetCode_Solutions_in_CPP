#include <iostream>
#include <vector>

using namespace std;

vector<int> insert_sort(vector<int>& nums) {

    if (nums.empty() || !nums.size())
        return nums;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = i; j > 0 && (nums[j] < nums[j-1]); j--) {
            swap(nums[j], nums[j-1]);
        }
    }
    return nums;
}


void print_nums(const vector<int>& nums)
{
    if (nums.empty() || !nums.size())
        return;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}


int main() {
    vector<int> a ( {7,3,5,8,9,1,2,4,6,0} );
//    vector<int> a = {9,7,5,3,1,0,2,4,6,8};
    cout << "Before sorting:" << endl;
    print_nums(a);

    vector<int> res = insert_sort(a);

    cout <<  "After sorting:" << endl;
    print_nums(res);

    return 0;
}