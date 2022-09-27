#include "counter.h"

Counter::Counter(int count)
{
    this->count = count;
}

Counter::Counter()
{
    count = 1;
}

void Counter::increment()
{
    count++;
}

void Counter::decrement()
{
    count--;
}

int Counter::getCount()
{
    return count;
}