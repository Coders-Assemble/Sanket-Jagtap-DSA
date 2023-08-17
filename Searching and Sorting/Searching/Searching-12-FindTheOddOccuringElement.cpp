#include<iostream>
#include<vector>
using namespace std;

int singleNonDuplicate(vector<int> &arr){
    int s = 0;
    int e = arr.size() - 1;
    int mid;

    while(s<=e){
        mid = s + (e - s)/2;

        if(s == e){
            return s;
        }

        if(mid%2 == 0){
            if(arr[mid] == arr[mid+1]){
                s = mid+2;
            }
            else{
                e = mid;
            }
        }
        else{
            if(arr[mid] == arr[mid-1]){
                s = mid + 1;
            }
            else{
                e = mid - 1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> v{1,1,2,2,3,3,4,4,3,600,600,4,4};

    int ans = singleNonDuplicate(v);

    cout<<"Index of single number "<<v[ans]<<" is "<<ans<<endl;

    return 0;
}