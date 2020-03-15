class MaxQueue
{
public:
    MaxQueue()
    {
    }

    int max_value()
    {
        if (maximum.empty())
            return -1;
        return maximum.front();
    }

    void push_back(int value)
    {
        data.push_back(value);
        while (!maximum.empty() && maximum.back() < value)
            maximum.pop_back();
        maximum.push_back(value);
    }

    int pop_front()
    {
        if (maximum.empty())
            return -1;
            
        int res = data.front();
        data.pop_front();
        if (res == maximum.front())
            maximum.pop_front();
        return res;
    }

private:
    deque<int> data;
    deque<int> maximum;
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */