/**
 * @文件名:exp1.cpp
 * @作者:耿宝源
 *      使用普林算法来解决实际问题
 */

#include <iostream>
#include <vector>
#include <climits>
#include <iomanip>

const int N = 8;


// 最小生成树，普林算法实现
void prim(float (*map)[N], int s)
{
    int mst[N];
    // w(mst[i], i) 等于 mindist[i]
    // 如果mst[i] 等于 -1 ，则代表该结点已经加入最小生成树

    float mindist[N];
    // mindist[i]代表所有在最小生成树中的结点到 i 结点的最小的权值
    // 该最小权值对应的边的起点是mst[i]


    // 每次找到一个结点加入最小生成树中，都要更新mst数组和mindist数组

    float weightSum = 0;

    std::cout << "Start Vertex is " << (s+1) << std::endl;
    for(int i = 0; i < N; ++i)
    {
        mindist[i] = map[s][i];
        mst[i] = s;
    }

    mst[s] = -1; // 开始结点被认为已经加入最小生成树

    for(int i = 1; i < N; ++i)
    {
        int v = -1;

        float min = INT_MAX/2;

        // 找到最小的mindist[i]的值
        for(int j = 0; j < N; ++j)
        {
            if(mst[j] != -1 && min > mindist[j])
            {
                v = j; //设置v，来记录我们找的下一个结点
                min = mindist[j];
            }
        }

        if(v != -1)
        {
            std::cout << "Add Vertex " << (v+1) << " to MST" << std::endl;
            weightSum += mindist[v];
            std::cout << "and the edge added is <" << mst[v] + 1 <<", " << v + 1 << "> , w = " << mindist[v] << std::endl;

            // 添加v结点到最小生成树
            mst[v] = -1;

            // 更新 mst 和 mindist
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

    std::cout << "Min sum of weigh : " << weightSum << std::endl;

}





int main(void)
{
    float map[N][N] = {
        {  0, 1.3, 2.1, 0.9, 0.7, 1.8, 2.0, 1.8},
        {1.3,   0, 0.9, 1.8, 1.2, 2.8, 2.3, 1.1},
        {2.1, 0.9, 0,   2.6, 1.7, 2.5, 1.9, 1.0},
        {0.9, 1.8, 2.6,   0, 0.7, 1.6, 1.5, 0.9},
        {0.7, 1.2, 1.7, 0.7,   0, 0.9, 1.1, 0.8},
        {1.8, 2.8, 2.5, 1.6, 0.9,   0, 0.6, 1.0},
        {2.0, 2.3, 1.9, 1.5, 1.1, 0.6,   0, 0.5},
        {1.8, 1.1, 1.0, 0.9, 0.8, 1.0, 0.5,   0}
    };

    std::cout << "The Adjacent Matrix is \n";


    for(int i = 0; i < N; ++i)
    {
        for(int j = 0; j < N; ++j)
        {
            std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1) << map[i][j] << "   ";
        }
        std::cout << std::endl;

    }

    std::cout << "Start Prim Algorithm\n";
    prim(map, 0);
    std::cout << "End Prim Algorithm\n";


    return 0;
}
