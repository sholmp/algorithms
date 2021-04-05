#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <vector>
#include <algorithm>

template <typename T>
class BinaryHeap
{
public:
    BinaryHeap()
    {
        T dummy;
        array.push_back(dummy); // [dummy, root, child_left, child_right, ...]
    }

    void insert(int elem)
    {
        array.push_back(elem);
        percolateUp(array.size() - 1);
    }

    int getMin()
    {
        return array[1];
    }

private:
    std::vector<T> array;

private:
    void percolateUp(int hole)
    {
        if ((hole / 2) == 0)
            return;
        else if (array[hole] >= array[hole / 2])
            return;
        else
        {
            std::swap(array[hole], array[hole / 2]);
            percolateUp(hole / 2);
        }
    }
};

#endif