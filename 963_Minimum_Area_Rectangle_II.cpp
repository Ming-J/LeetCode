#include <algorithm>
#include <iostream>
#include <numeric>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
  public:
    double minAreaFreeRect(vector<vector<int>> &points) {
        unordered_map<string, vector<vector<int>>> midpoints;
        vector<vector<vector<int>>> res;
        res = combination(points, 2);
        double area = numeric_limits<double>::max();
        for (auto comb : res) {
            vector<double> midp = midPoint(comb[0], comb[1]);
            string mid_str = to_string(distanceSqr(comb[0], comb[1])) + ' ' +
                             pointToString(midp);
            if (midpoints.find(mid_str) == midpoints.end())
                midpoints[mid_str] = {comb[0], comb[1]};
            else {
                cout << mid_str << " p1: " << pointToString(comb[0])
                     << " p2: " << pointToString(comb[1]) << endl;
                area = min(area,
                           calArea(midp, midpoints[mid_str], comb[0], comb[1]));
            }
        }
        return (area != numeric_limits<double>::max()) ? area : 0;
        ;
    }

  private:
    template <class T> string pointToString(vector<T> point) {
        return to_string(point[0]) + "_" + to_string(point[1]);
    }
    double calArea(vector<double> midpoints, vector<vector<int>> dia,
                   vector<int> p1, vector<int> p2) {
        double a = sqrt(distanceSqr(p1, dia[0]));
        double b = sqrt(distanceSqr(p2, dia[0]));
        return a * b;
    }

    template <class T>
    void helper(vector<T> &nums, vector<vector<T>> &result, vector<T> &current,
                int index, int c) {
        if (current.size() == c) {
            result.push_back(current);
            return;
        }
        for (int i = index; i < nums.size(); ++i) {
            current.push_back(nums[i]);
            helper(nums, result, current, i + 1, c);
            current.pop_back();
        }
    }

    template <class T> vector<vector<T>> combination(vector<T> nums, int c) {
        vector<T> current;
        vector<vector<T>> result;
        helper(nums, result, current, 0, c);
        return result;
    }

    vector<double> midPoint(vector<int> p1, vector<int> p2) {
        vector<double> mid(2, 0);
        mid[0] = (p1[0] + p2[0]) / 2.0;
        mid[1] = (p1[1] + p2[1]) / 2.0;
        return mid;
    }

    int distanceSqr(vector<int> p1, vector<int> p2) {
        int deltaX = p1[0] - p2[0];
        int deltaY = p1[1] - p2[1];
        return deltaX * deltaX + deltaY * deltaY;
    }
};

int main() {

    Solution t;
    vector<vector<int>> input = {
        {23375, 11200}, {23375, 28800}, {10640, 21105}, {24732, 11849},
        {10705, 21560}, {27337, 14084}, {18767, 29344}, {22639, 10952},
        {22580, 10935}, {11880, 24785}, {17680, 29135}, {24785, 28120},
        {22580, 29065}, {18895, 29360}, {24329, 28372}, {19224, 29393},
        {20000, 29425}, {25704, 27503}, {24620, 28215}, {28215, 15380},
        {12460, 25655}, {11785, 24620}, {17420, 29065}, {13937, 27216},
        {16625, 28800}, {25015, 12020}, {14345, 27540}, {22320, 10865},
        {29048, 17361}, {10935, 22580}, {13500, 26825}, {28800, 23375},
        {28151, 15268}, {22135, 10820}, {29344, 18767}, {27503, 14296},
        {27540, 25655}, {25655, 12460}, {20776, 29393}, {16200, 28625},
        {25655, 27540}, {29367, 18956}, {20776, 10607}, {15215, 28120},
        {23800, 11375}, {21105, 29360}, {10575, 20000}, {27216, 26063},
        {10607, 20776}, {28625, 16200}};
    cout << t.minAreaFreeRect(input) << endl;
    ;
}