#include <iostream>
using namespace std;

int main()
{
    int arr[] = {0, 0, 0, 0};
    int count = 0;
    for (int i = 0; i <= 9; i++) {
        arr[0] = i;
        for (int j = 0; j <= 9; j++) {
            arr[1] = j;
            for (int k = 0; k <= 9; k++) {
                arr[2] = k;
                for (int m = 0; m <= 9; m++) {
                    arr[3] = m;
                    if ((i == j && i == k && i != m && j != m && k != m) || 
                    (j == i && j == k) || 
                    (i == j && i == k && i != m && j == m && k == m) ||
                    ()) {
                        count++;
                    }
                }
            }
        }
    }
    cout << "count of all different is: " << count << endl;

    int arr2[] = {0, 0, 0, 0};
    int count2 = 0;
    for (int i = 0; i <= 9; i++) {
        arr2[0] = i;
        for (int j = 0; j <= 9; j++) {
            arr2[1] = j;
            for (int k = 0; k <= 9; k++) {
                arr2[2] = k;
                for (int m = 0; m <= 9; m++) {
                    arr2[3] = m;
                    if (i < j && i < k && i < m && j < k && j < m && k < m) {
                        count2++;
                    }
                }
            }
        }
    }
    cout << "count of all different, strictly increasing is: " << count2 << endl;
    return 0;
}