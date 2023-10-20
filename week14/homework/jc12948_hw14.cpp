
#include <iostream>
#include <vector>
using namespace std;

vector<int> find_min_max(const vector<int> &vector, int low, int high);
vector<int> compare(const vector<int> &vector_half_one, const vector<int> &vector_half_two);

int main() {
    vector<int> nums = {10};
    vector<int> min_max = find_min_max(nums, 0, nums.size()-1);
    cout << "The min is: " << min_max[0] << " and the max is: " << min_max[1] << endl;

    return 0;
}

vector<int> find_min_max(const vector<int> &v, int low, int high) {
    if (low == high) {
        return vector<int>(2, v[low]);
    } else {
        int mid = low + (high - low) / 2;
        vector<int> vector_half_one = find_min_max(v, low, mid);
        vector<int> vector_half_two = find_min_max(v, mid + 1, high);
        return compare(vector_half_one, vector_half_two);
    }
}

vector<int> compare(const vector<int> &vector_half_one, const vector<int> &vector_half_two) {
    vector<int> min_max(2);
    min_max[0] = min(vector_half_one[0], vector_half_two[0]);
    min_max[1] = max(vector_half_one[1], vector_half_two[1]);
    return min_max;
}

