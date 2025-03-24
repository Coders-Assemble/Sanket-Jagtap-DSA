#include <iostream>
#include <vector>
using namespace std;

int findMissingNumber(vector<int> &nums){
    int s = 0;
    int n = nums.size();
    int e = n - 1;

    if(nums[0] != 1) return 1;
    if(nums[n-1] != n + 1) return n + 1;

    while (s <= e){
        int mid = s + (e - s) / 2;
        if(nums[mid] == mid + 1) {
            s = mid + 1;
        } else if (nums[mid] > mid + 1) {
            e = mid - 1;
        }
    }
    return e + 2;
}

int main(){
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout<<"Missing Number: "<<findMissingNumber(vec)<<endl;
    return 0;
}

// int findMissingElememt(int arr[], int size)
// {

//     if (arr[0] != 1)
//         return 1;

//     if (arr[size - 1] != (size + 1))
//         return size + 1;

//     int start = 0;
//     int end = size - 1;

//     int mid = start + ((end - start) / 2);

//     while (end - start > 1)
//     {

//         if (arr[start] - start != arr[mid] - mid)
//         {
//             end = mid;
//         }
//         else if (arr[end] - end != arr[mid] - mid)
//         {
//             start = mid;
//         }
//         mid = start + ((end - start) / 2);
//     }

//     return arr[start] + 1;
// }

// int main()
// {

//     int arr[] = {1, 2, 3, 5, 6, 7, 8};
//     int size = sizeof(arr) / sizeof(arr[0]);

//     int missElement = findMissingElememt(arr, size);

//     cout << "Missing element: " << missElement << endl;

//     return 0;
// }

// int findMissingElememt(vector<int> arr)
// {

//     if (arr[0] != 1)
//         return 1;

//     if (arr[arr.size() - 1] != (arr.size() + 1))
//         return arr.size() + 1;

//     int start = 0;
//     int end = arr.size() - 1;

//     int mid = start + ((end - start) / 2);

//     while (end - start > 1)
//     {

//         if (arr[start] - start != arr[mid] - mid)
//         {
//             end = mid;
//         }
//         else if (arr[end] - end != arr[mid] - mid)
//         {
//             start = mid;
//         }
//         mid = start + ((end - start) / 2);
//     }

//     return arr[start] + 1;
// }

// int main()
// {

//     vector<int> v{2, 3, 4, 5, 6, 7, 8};

//     int missElement = findMissingElememt(v);

//     cout << "Missing element: " << missElement << endl;

//     return 0;
// }