#pragma once
#include <iostream>
#include <string.h>
#include <boost/atomic.hpp>
#include <boost/thread/thread.hpp>
#include <boost/lockfree/stack.hpp>
#include <boost/lockfree/queue.hpp>
#include <boost/lockfree/spsc_queue.hpp>
#define BOOSTDATALENGTH 1024

class BoostLockFree {
public:
    BoostLockFree();
    ~BoostLockFree();
    void AddFunction(std::function<void(void)>& func);

public:
    //�޵ȴ���������/�������߶���
    //boost::lockfree::spsc_queue<std::function<void(void)>, boost::lockfree::capacity<1024> > spsc_queue;
    //��д��/���ȡջ
    boost::lockfree::stack<std::function<void(void)>, boost::lockfree::capacity<1024>> free_stack_;
};