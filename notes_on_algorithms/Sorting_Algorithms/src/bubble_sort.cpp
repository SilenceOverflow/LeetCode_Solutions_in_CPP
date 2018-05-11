#include <iostream>
#include <vector>

using namespace std;

vector<int> bubble_sort(vector<int>& nums) {

    if (nums.empty() || !nums.size())
        return nums;

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        for (int j = n - 1; j > i; j--) {
            if (nums[j] < nums[j-1]) {
                swap(nums[j], nums[j-1]);
            }
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
//    vector<int> a ( {7,3,5,8,9,1,2,4,6} );
    vector<int> a = {9,7,5,3,1,0,2,4,6,8};
    cout << "Before sorting:" << endl;
    print_nums(a);

    vector<int> res = bubble_sort(a);

    cout <<  "After sorting:" << endl;
    print_nums(res);

    return 0;
}

