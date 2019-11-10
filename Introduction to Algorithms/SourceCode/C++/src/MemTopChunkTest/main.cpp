#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <vector>
void testfree(unsigned char*buf)
{
    free(buf);
}
int main()
{
    unsigned char* buf[200];
    size_t len = 1024*1024*31;
    size_t len_short = 1024*1024*10;
    int num = 0;
    std::vector<std::thread> th_v;
    unsigned char* p = (unsigned char*)malloc(1024*1024*31*sizeof(unsigned char));
    if(p == NULL)
    {
        printf("malloc failed\n");
        return 0;
    }
    for(size_t idx = 0; idx < len; idx++)
    {
        p[idx] = idx%(unsigned char)-1;
    }
    num = p[15];
    pid_t pid  = getpid();
    std::string cmd = std::string("ps -axu|grep ")+ std::to_string((int)pid) + std::string(" |grep -v grep");
    while(true)
    {
        for(int i = 0; i < 200; i++)
        {
            buf[i] = (unsigned char*)malloc(len_short*sizeof(unsigned char));
            if(buf[i] == NULL)
            {
                printf("malloc failed\n");
                return 0;
            }
            for(size_t idx = 0; idx < len_short; idx++)
            {
                buf[i][idx] = idx%(unsigned char)-1;
            }
            num += buf[i][15];
        }
        printf("malloc finsh\n");
        system(cmd.c_str());
        for(int i = 0; i < 200; ++i)
        {
            th_v.push_back(std::thread(testfree, buf[i]));
        }
        system(cmd.c_str());
        for (auto& th : th_v) th.join();
        system(cmd.c_str());
        sleep(5);
        system(cmd.c_str());
        printf("free finsh and wait 10s\n");
        th_v.clear();
    }
    return 0;
}
