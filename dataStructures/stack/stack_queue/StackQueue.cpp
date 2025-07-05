#include "StackQueue.h"
#include <stdexcept>

void StackQueue::push(int value)
{
    q1.push(value);

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }

    std::swap(q1, q2);
}

int StackQueue::pop()
{
    if (q2.empty())
    {
        throw std::runtime_error("Stack is empty");
    }

    int value = q2.front();
    q2.pop();
    return value;
}