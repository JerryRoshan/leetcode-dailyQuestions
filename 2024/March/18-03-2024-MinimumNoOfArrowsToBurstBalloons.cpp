//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/submissions/1206908250?envType=daily-question&envId=2024-03-18
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        sort(points.begin(), points.end());
        //The above line sorts the vector points in ascending order based on the default comparison operator for vectors.
        //By default, this will sort the balloons based on their start points.
        int arrows = 1;
        int end = points[0][1];

        for (int i = 1; i < points.size(); ++i) {
            //Inside the loop, we check if the start point of the current balloon is greater than the current end. 
            //If it is, we increment arrows by 1 and update end to the end point of the current balloon. 
            //This signifies that a new arrow is needed to burst the current balloon.
            //If the start point of the current balloon is less than or equal to end,
            //we update end to the minimum of the current end and the end point of the current balloon. 
            //This accounts for overlapping balloons that can be burst with a single arrow.
            if (points[i][0] > end) {
                arrows++;
                end = points[i][1];
            } else {
                end = min(end, points[i][1]);
            }
        }

        return arrows;
    }
};

/*
[ Time taken: 23 m 17 s ] using greedy approach

1. Sort the balloons based on their start points.
2. Initialize a variable `end` to store the end point of the first balloon.
3. Iterate through the sorted balloons and for each balloon:
   - If the current balloon's start point is greater than `end`, it means a new arrow is required. Increment the arrow count and update `end` to the current balloon's end point.
   - If the current balloon's start point is less than or equal to `end`, update `end` to the minimum of `end` and the current balloon's end point.
4. The final value of the arrow count will be the minimum number of arrows required to burst all balloons.

This approach  sorts the balloons based on their start points instead of end points. By considering the start points first, we can efficiently find the minimum number of arrows needed to burst all balloons.
*/
