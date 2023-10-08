#include <iostream>
using namespace std;

int sortedSearch(int sortArr[], int sortArrSize, int val);

int main() {
    int sortArr[10] = {1, 3, 5, 9, 11, 13, 15, 17, 19};
    cout<<sortedSearch(sortArr, 10, 13)<<endl;
    return 0;
}

int sortedSearch(int sortArr[], int sortArrSize, int val) {
    int low;
    int high;
    bool found = false;
    int mid;
    int ind;
    low = 0;
    high = sortArrSize - 1;

    while((low <= high) && (found == false)) {
        mid = (low  + high) / 2;
        if(sortArr[mid] == val) {
            ind = mid;
            found = true;
        }
        else if(val < sortArr[mid]) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    if(found == true) {
            return ind;
        }
        else {
            return -1;
        }

}