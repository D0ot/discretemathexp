// using prim algrithm to solve real problem

#include <iostream>
#include <vector>
#include <climits>

const int N = 6;

// mst
void prim(int (*map)[N], int startVertex)
{
    int mst[N];
    // start vertex of mindist[i]

    int mindist[N]; 
    // i is the end of edge and mindist[i] is the minimal distance to MST


    for(int i = 0; i < N; ++i)
    {
        mindist[i] = map[startVertex][i];
        mst[i] = startVertex;
    }

    mst[startVertex] = -1; // the start vertex is added into MST

    for(int i = 1; i < N; ++i)
    {
        int v = -1;

        int min = INT_MAX/2; 

        // find the min value in mindist
        for(int j = 0; j < N; ++j)
        {
            if(mst[j] != -1 && min > mindist[j])
            {
                v = j;
                min = mindist[j];
            }
        }

        if(v != -1)
        {
            std::cout << mst[v] << ' '
            << v << ' '
            << mindist[v] << ' '
            << std::endl;

            // add v to MST
            mst[v] = -1;

            for(int j = 0; j < N; ++j)
            {
                if(mst[j] != -1 && map[v][j] < mindist[j])
                {
                    mindist[j] = map[v][j];
                    mst[j] = v;
                }
            }

        } 
    }

}





int main(void)
{
    int INF = INT_MAX / 2;
    int map[N][N] = {
        {0, 6, 1, 5, INF, INF},
        {6, 0, 5, INF, 3, INF},
        {1, 5, 0, 5, 6, 4 },
        {5, INF, 5, 0, INF, 2},
        {INF, 3, 6, INF, 0, 6},
        {INF, INF, 4, 2, 6, 0}
    };

    prim(map, 0);

}