#include <iostream>
#include <vector>

size_t count = 0;

void full(std::vector<int> st, std::vector<int> st2);

int main(void)
{
    std::vector<int> st{1,2,3,4,5,6};
    std::vector<int> st2;
    full(st, st2);
    std::cout << "count : " << count << std::endl;
}

void full(std::vector<int> st, std::vector<int> st2)
{
    if(st.size() == 1)
    {
        count++;
        for(auto& x:st2)
        {
            std::cout << x << ' ';
        }
        std::cout << st[0] << std::endl;
        return;
    }

    for(size_t i = 0; i < st.size(); ++i)
    {
        std::vector<int> newst2 = st2;
        std::vector<int> newst1 = st;

        int e = st[i];

        newst2.push_back(e);

        for(size_t j = i + 1; j < newst1.size(); ++j)
        {
            newst1[j - 1] = newst1[j];
        };

        newst1.pop_back();

        full(newst1, newst2);
    }
}