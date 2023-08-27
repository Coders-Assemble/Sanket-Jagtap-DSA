#include <iostream>
#include <vector>
using namespace std;

int findUnique(vector<int> v)
{
    int ans = 0;

    for (int i = 0; i < v.size(); i++)
    {
        ans = ans ^ v[i];
    }

    return ans;
}

int main()
{
    // Unique Element

    // int n;
    // cout << "Enter size of vector : ";
    // cin >> n;

    // vector<int> v(n);

    // for (int i = 0; i < v.size(); i++) {
    //   cin >> v[i];
    // }

    // int uniqueElement = findUnique(v);

    // cout << "Unique Element is : " << uniqueElement << endl;

    // Union of two arrays
    // vector<int> v1{2, 4, 6, 8};
    // int sizev1 = 4;
    // vector<int> v2{1, 3, 5};
    // int sizev2 = 3;

    // vector<int> ans;

    // // Push all elements of vector v1
    // for (int i = 0; i < sizev1; i++) {
    //   ans.push_back(v1[i]);
    // }

    // // Push all elements of vector v2
    // for (int i = 0; i < sizev2; i++) {
    //   ans.push_back(v2[i]);
    // }

    // // Printing ans array
    // cout << "Elements of ans array : ";
    // for (int i = 0; i < ans.size(); i++) {
    //   cout << ans[i] << " ";
    // }

    // Intersection of two vectors
    // vector<int> arr{1, 2, 3, 3, 4, 6, 8};
    // vector<int> brr{3, 3, 4, 10};

    // vector<int> ans;

    // for (int i = 0; i < arr.size(); i++) {
    //   for (int j = 0; j < brr.size(); j++) {
    //     if (arr[i] == brr[j]) {
    //       // Marking if elements exists twice
    //       brr[j] = -1;
    //       ans.push_back(arr[i]);
    //     }
    //   }
    // }

    // for (auto ele : ans) {
    //   cout << ele << " ";
    // }
    // cout << endl;

    // Pair Sum
    // vector<int> v1{5, 3, 2, 8, 1, 4, 6};
    // int sum = 9;

    // for (int i = 0; i < v1.size(); i++) {
    //   for (int j = i + 1; j < v1.size(); j++) {
    //     if (v1[i] + v1[j] == sum) {
    //       cout << v1[i] << " and " << v1[j] << endl;
    //     }
    //   }
    // }

    // Triplet Sum
    // vector<int> arr{10, 20, 30, 40};
    // int sum = 80;

    // for (int i = 0; i < arr.size(); i++) {
    //   for (int j = i + 1; j < arr.size(); j++) {
    //     for (int k = j + 1; k < arr.size(); k++) {
    //       if (arr[i] + arr[j] + arr[k] == sum) {
    //         cout << arr[i] << "," << arr[j] << "," << arr[k] << endl;
    //       }
    //     }
    //   }
    // }

    // Sort zeros and ones
    vector<int> arr{0, 1, 0, 0, 1, 1, 0, 0, 1};

    int start = 0;
    int end = arr.size() - 1;
    int i = 0;

    while (i != end)
    {
        if (arr[i] == 0)
        {
            swap(arr[start], arr[i]);
            i++;
            start++;
        }
        else
        {
            swap(arr[i], arr[end]);
            end--;
        }
    }

    // Another method
    // while (start < end) {
    //   if (arr[start] == 0 && arr[end] == 1) {
    //     start++;
    //     end--;
    //   } else if (arr[start] == 1 && arr[end] == 0) {
    //     swap(arr[start], arr[end]);
    //     start++;
    //     end--;
    //   }

    //   if (arr[start] == 0) {
    //     start++;
    //   }

    //   if (arr[end] == 1) {
    //     end--;
    //   }
    // }

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}