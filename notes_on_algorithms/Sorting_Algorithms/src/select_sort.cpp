#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int>& nums) {
    int n = nums.size();
    if (nums.empty() || !n)
        return;

    for (int i = 0; i < n; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (nums[j] < nums[min])
                min = j;
        }
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
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
    vector<int> a = {7,3,5,8,9,1,2,4,6};
    cout << "Before sorting:" << endl;
    print_nums(a);

    select_sort(a);

    cout <<  "After sorting:" << endl;
    print_nums(a);

    return 0;
}