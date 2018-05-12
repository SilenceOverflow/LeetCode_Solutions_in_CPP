#include <iostream>
#include <vector>

using namespace std;

vector<int> shell_sort(vector<int>& nums) {

    if (nums.empty() || !nums.size())
        return nums;

    int n = nums.size();

    int h = 1;
    while (h < n/3)
        h = 3 * h + 1;

    while (h >= 1) {

        for (int i = h; i < n; i++) {
            for (int j = i; j >= h && (nums[j] < nums[j - h]); j -= h) {
                swap(nums[j], nums[j - h]);
            }
        }

        h /= 3;
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

    vector<int> res = shell_sort(a);

    cout <<  "After sorting:" << endl;
    print_nums(res);

    return 0;
}