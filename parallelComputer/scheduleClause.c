/*
 * @Description: schedule子句的动态和静态方式
 * @Author: aLittleMango
 * @Date: 2021-07-12 16:28:51
 * @LastEditTime: 2021-07-12 16:48:05
 * @FilePath: \PracticeOpenmp\parallelComputer\scheduleClause.c
 */
#include <omp.h>
#include <stdio.h>
void main()
{
    int i;
    int chunk = 3;
#pragma omp parallel shared(chunk) private(i)
    {
#pragma omp for schedule(static, chunk) 
        for (i = 0; i < 20; i++)
        {
            printf("static:thread %d excute i = %d\n", omp_get_thread_num(), i);
        }
//不是按照线程id顺序，而是根据线程运行情况动态分配块
#pragma omp for schedule(dynamic, chunk) 
        for (i = 0; i < 20; i++)
        {
            printf("dynamic:thread %d excute i = %d\n", omp_get_thread_num(), i);
        }
    }
}

double ave=0.0,A[MAX];
int i;
#pragma omp parallel for reduction(+:ave)
for(i=0;i<MAX;i++){
    ave+= A[i];
}
ave = ave/MAX;