
/*
 * @Description: 线程创建:并行区域 
 * @Author: aLittleMango
 * @Date: 2021-07-08 11:02:55
 * @LastEditTime: 2021-07-08 20:40:11
 * @FilePath: \PracticeOpenmp\parallelComputer\paralleltest.c
 */

#include <omp.h>
#include <stdio.h>


//runtime function to request a certain number of threads
//运行时函数请求一定数量的线程
int main()
{
    int ID, nthrds;
    omp_set_dynamic(1);//启动动态分配线程数
    omp_set_num_threads(6); //设置线程数为6个

//fork一组线程，给每个线程自己独立的变量拷贝
#pragma omp parallel private(ID)
    {

        //获取然后打印线程id
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
