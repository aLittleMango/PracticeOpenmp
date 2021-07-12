/*
 * @Description: 工作共享结构中实现for语句
 * @Author: aLittleMango
 * @Date: 2021-07-12 15:22:15
 * @LastEditTime: 2021-07-12 15:57:16
 * @FilePath: \PracticeOpenmp\parallelComputer\loopWorksharing.c
 */
#include <omp.h>
#include <stdio.h>
void main()
{
//一、顺序代码：for(i=0;i<N;i++){a[i]=a[i]+b[i];}

/*
二、OPENMP并行区
#pragma omp parallel
    {
        int N = 16;
        int id, i, Nthrds, istart, iend;
        id = omp_get_thread_num();//获取线程的id，并行区域外，获取的是master线程的id，为0；在并行区域内，获取的是当前执行线程的id
        Nthrds = omp_get_num_threads(); //获取线程数量
        istart = id * N / Nthrds;
        iend = (id + 1) * N / Nthrds;
        if (id == Nthrds - 1)
            iend = N;
        for (i = istart; i < iend; i++)
        {
            printf("thread %d excute i = %d\n", id, i);
        }
    }
*/
//三、OPENMP并行区和工作共享构造
#pragma omp parallel
    {
        int N = 16;
        int id, i;
        id = omp_get_thread_num();
#pragma omp for

        for (i = 0; i < N; i++)
        {
            printf("thread %d excute i = %d\n", id, i);
        }
    }
}