 
/**
 * @file test_select.cpp
 * @author kymowind@gmail.com
 * @date 2016/10/15 21:32:27
 * @brief 
 *  
 **/

#include  <stdio.h>
#include  <iostream>
#include  <unistd.h>
#include  <fcntl.h>
#include  <errno.h>
#include  <sys/types.h>
#include  <sys/socket.h>
#include  <sys/epoll.h>
#include  <netinet/in.h>
#include  <arpa/inet.h>
#include "select.h"
#include "event.h"
#include <fcntl.h>
#include "define.h"
#include "server.h"

using namespace sub_framework;

// 逻辑回调函数

int req_task_call_back(void *a, void *b) {
    char* buf = (char*) a;
    char *ret = (char*) b; 
    char *json = "{'key' : 'value'}";

    char write_buf[128] = "HTTP/1.1 200 OK\r\nContent-Length: 11\r\n\r\n{\"key\":\"value\"}"; 
    strcpy(ret, write_buf);
    return 1;
}

int main() {
    // init task_mgr
    SubTaskMgr::_get_instance()->_init();
    // 设置核心逻辑的回调函数
    SubTaskMgr::_get_instance()->_set_call_back_proc(REQ_TASK, req_task_call_back);
    // 启动线程池
    SubThreadPool::_get_instance()->_init();
    SubThreadPool::_get_instance()->_set_thread_cnt(1);
    SubThreadPool::_get_instance()->_start();
    SubEventQueue::_get_instance()->_init();
    // 启动服务
    SubServer*svr = SubServer::_get_instance();
    svr->_run();
    return 0;
}









/* vim: set expandtab ts=4 sw=4 sts=4 tw=100: */
