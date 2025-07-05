/**
 * @author Erno Mitrovic
 *
 * Build a stack using two queues. Specific implementation to demonstrate the algorithm.
 * Suboptimal solution for educational purposes.
 */

#ifndef STACK_QUEUE_H
#define STACK_QUEUE_H

#include <queue>

class StackQueue
{
private:
    std::queue<int> q1;
    std::queue<int> q2;

public:
    void push(int);
    int pop();
};

#endif