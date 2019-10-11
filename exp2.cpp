/**
 * @file : exp2.cpp
 * @author : d0ot
 * @date : 2019/10/11
 */

#include <iostream>
#include <vector>
#include <array>
#include <climits>


int cost[] = {4, 1, 3, 2, 2, 1, 7, 15, 5, 10, 11, 5};

int adjMatrix[12][12] = {
//      1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 1
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 2
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 3
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 4
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 5
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 6
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 7
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 8
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 9
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 10
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 11
    {   0,  0,  0,  0,  0,  0,  0,  0,  0,  00, 00, 00},             // 12
};

// positive value and zero indicate weight
// -1 indicates infinite

/** 
 * @type function
 * @brief return the minimum path found
 */

std::vector<int> dijkstraAlgorithm(int* adjMat, size_t maxSize, size_t startVertex, size_t endVertex)
{
    auto w = [adjMat, maxSize](size_t posX, size_t posY){
        return adjMat[posY + maxSize * posX];
    };

    // it records the vertics on the path found
    std::vector<int> retPath;
    
    // minimum length to startVertex of every vertics
    std::vector<int> L(maxSize, INT_MAX);

    // 0 : not processed
    // 1 : processed
    std::vector<char> s(maxSize, 0);

    // init
    L[startVertex] = 0;

    while(true)
    {
        int min = INT_MAX;
        int u = -1;

        for(size_t i = 0; i < maxSize; ++i)
        {
            if(L[i] < min && !s[i])
            {
                min = L[i];
                u = i;
            }
        }

        if(u == -1)
        {
            break;
        }

        s[u] = 1;
        std::cout << "u = " << u << std::endl;

        for(size_t v = 0; v < maxSize; ++v)
        {
            if(w(u, v) != -1 && L[u] + w(u, v) < L[v] && !s[v])
            {
                L[v] = L[u] + w(u, v);
                std::cout << "L[" << v << "] = " << "L[" << u << "] + w(" << u << ", " << v << ")\n";
            }
        }
    }

    for(size_t i = 0; i < maxSize; ++i)
    {
        std::cout << "L[" << i << "] = " << L[i] << std::endl;
    }

    return retPath; 
}

int main(void)
{
    int adjmat[] =
    {
        -1,  1, -1, 2, -1,
        -1, -1,  3, -1, -1,
        -1, -1, -1, 1, 5,
        -1, -1, -1, -1, 1,
        -1, -1, -1, -1, -1
    };

    dijkstraAlgorithm(adjmat, 5, 0, 4);
    return 0;
}