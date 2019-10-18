// using prim algrithm to solve real problem

#include <iostream>
#include <vector>
#include <climits>

const int N = 8;

// mst
void prim(int (*map)[N], int startVertex)
{
    int mst[N];
    // start vertex of mindist[i]

    int mindist[N]; 
    // i is the end of edge and mindist[i] is the minimal distance to MST

    int weightSum = 0;


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
            weightSum += mindist[v];
            std::cout << "add edge (" << mst[v] + 1 <<", " << v + 1 << ") to MST, w = " << mindist[v] << std::endl;

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

    std::cout << "Min Sum of Weight : " << weightSum << std::endl;

}




const int INF = INT_MAX / 2;


void test(void)
{
    // set N to 6, before start this test
    /* int map[N][N] = {
        {0, 6, 1, 5, INF, INF},
        {6, 0, 5, INF, 3, INF},
        {1, 5, 0, 5, 6, 4 },
        {5, INF, 5, 0, INF, 2},
        {INF, 3, 6, INF, 0, 6},
        {INF, INF, 4, 2, 6, 0}
    };

    prim(map, 0);*/

}

int main(void)
{
    int x = INF;
    int map[N][N] = {
        {0, 13, 21, 9,  7, 18, 20, 18},
        {13, 0, 9, 18, 12, 28, 23, 11},
        {21, 9, 0, 26, 17, 25, 19, 10},
        {9, 18, 26, 0,  7, 16, 15,  9},
        {7, 12, 17, 7,  0,  9, 11,  8},
        {18,28, 25, 16, 9,  0,  6, 10},
        {20,23, 19, 15,11,  6,  0,  5},
        {18,11, 10,  9, 8,  10, 5,  0}
    };

    int directedMap[N][N] = {
        {0, 13, 21, 9,  7, 18, 20, 18},
        {x,  0, 9, 18, 12, 28, 23, 11},
        {x,  x, 0, 26, 17, 25, 19, 10},
        {x,  x, x,  0,  7, 16, 15,  9},
        {x,  x, x,  x,  0,  9, 11,  8},
        {x,  x, x,  x, x,  0,  6, 10},
        {x,  x, x,  x, x,  x,  0,  5},
        {x,  x, x,  x, x,  x,  x, 0}
    };

    std::cout << "Undirected\n";
    prim(map, 0);

    std::cout << "Directed\n";
    prim(directedMap, 0);
}