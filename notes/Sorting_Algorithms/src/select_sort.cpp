//
// Created by youjiexia on 18/5/8.
//

#include <iostream>
#include <vector>

using namespace std;

void select_sort(vector<int>& nums) {
    int size = nums.size();
    if (nums.empty() || !size)
        return;

    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i+1; j < size; j++) {
            if (nums[j] < nums[min])
                min = j;
        }
        int temp = nums[i];
        nums[i] = nums[min];
        nums[min] = temp;
    }
}


int main() {
//    vector<int> a ( {7,3,5,8,9,1,2,4,6} );
    vector<int> a = {7,3,5,8,9,1,2,4,6};
    cout << "Before sorting:" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    select_sort(a);

    cout << endl <<  "After sorting:" << endl;
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }

    return 0;
}