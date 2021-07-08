
/*
 * @Description: 线程创建:并行区域 
 * @Author: aLittleMango
 * @Date: 2021-07-08 11:02:55
 * @LastEditTime: 2021-07-08 17:24:51
 * @FilePath: \Openmp\parallelComputer\paralleltest.c
 */

#include <omp.h>
#include <stdio.h>


//runtime function to request a certain number of threads
//运行时函数请求一定数量的线程
int main()
{
    int ID, nthrds;
    omp_set_num_threads(6);

#pragma omp parallel
    {
        //返回线程ID的运行时函数
        ID = omp_get_thread_num();

        printf("hello from thread = %d\n", ID);

        if (ID == 0)
        {
            nthrds = omp_get_num_threads();
            printf("Number of threads = %d\n", nthrds);
        }
    }
    //所有线程join主线程并结束
    //each thread executes a copy of the code within the structured block
}
