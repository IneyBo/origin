#pragma once

class Counter
{
private:
    int count;

public:
    Counter(int count);

    Counter();

    void increment();

    void decrement();

    int getCount();
};