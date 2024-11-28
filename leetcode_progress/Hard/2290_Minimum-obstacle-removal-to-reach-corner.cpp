#include<bits/stdc++.h>

using namespace std;

using int2 = pair<int, int>; // (dist, idx(i, j))
const static int d[5] = {0, 1, 0, -1, 0};

class Solution {
public:
    inline static bool isOutside(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    inline static int idx(int i, int j, int m) {
        return i * m + j;
    }
    int minimumObstacles(vector<vector<int>>& grid) {
        const int n = grid.size(), m = grid[0].size(), N=100000;
        unsigned dist[N];
        fill(dist, dist + n*m, INT_MAX);

        int2 q[N]; // circular deque
        int back = N/2, front = N/2; //Middle of array for space to prepend/append

        q[back++] = {0, 0}; // Start at (0, 0)
        dist[0] = 0;

        while (back != front) {
            auto [currD, ij] = q[front]; // Increment front with wrap-around
            front=(front==N-1)?0:front+1;
            auto [i, j] = div(ij, m);

            // Reach the target
            if (i == n - 1 && j == m - 1)
                return currD;

            // Explore all four directions
            for (int a = 0; a < 4; a++) {
                int r = i + d[a], s = j + d[a + 1];
                if (isOutside(r, s, n, m))
                    continue;

                int nextD = currD + grid[r][s];
                int rs = idx(r, s, m);

                // Update if this path has a shorter distance
                if (nextD < dist[rs]) {
                    dist[rs] = nextD;
                    int2 next = {dist[rs], rs};

                    // Prepend or append based on weight
                    if (grid[r][s] == 0) {
                        front=(front==0)?N-1:front-1;
                        q[front] = next; // Prepend for weight 0
                    } 
                    else {
                        q[back] = next; // Append for weight 1
                        back=(back==N-1)?0:back+1;
                    }
                }
            }
        }
        return -1; // Never reach
    }
};

int main(){
    Solution s;
    vector<vector<int>> grid = {{0, 1, 1}, {1, 1, 0}, {1, 1, 0}};
    cout << s.minimumObstacles(grid) << endl;
    return 0;
}