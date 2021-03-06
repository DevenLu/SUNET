 
/**
 * @file thread.cpp
 * @author kymowind@gmail.com
 * @date 2016/10/09 14:05:45
 * @brief 
 *  
 **/

#include "thread.h"

namespace sub_framework {


SubThread::SubThread(SubThreadHandler* handler, void* args) {
    _handler = handler;
    _thread_stat = THREAD_NEW;
    _tid = 0;
    _args = args;
}

void* thread_proc(void *args) {
    SubThread* sub_thread = (SubThread*) args;

    if (NULL != sub_thread) {
        sub_thread->_run();
    }
}


SubThread::SubThread() {
    _handler = NULL;
    _thread_stat = THREAD_NEW;
    _tid = 0;
}

int SubThread::_get_stat() {
    return _thread_stat;
}

void SubThread::_stop() {
    if (NULL == _handler) {
        FATAL_LOG("Handler is NULL!");
        return ;
    }
    _handler->_stop();
}

bool SubThread::_is_stop() {
    if (NULL == _handler) {
        FATAL_LOG("Handler is NULL!");
        return false;
    }
    return _handler->_is_stop();
}

int SubThread::_start() {
    int tid = 0;
    tid = pthread_create(&_tid, NULL, thread_proc, this);
    DEBUG_LOG("Thread[%d] starts!", tid);
    return tid;
}

void SubThread::_join() {
    pthread_join(_tid, NULL);
}

void SubThread::_run() {
    if (NULL == _handler) {
        FATAL_LOG("Handler is NULL!");
        return ;
    }
    _handler->_thread_proc_handler(_args);
}
}




















/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
