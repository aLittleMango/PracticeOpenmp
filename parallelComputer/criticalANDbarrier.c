/*
 * @Description: 同步的critical和barrier
 * @Author: aLittleMango
 * @Date: 2021-07-09 15:41:48
 * @LastEditTime: 2021-07-09 17:30:15
 * @FilePath: \PracticeOpenmp\parallelComputer\criticalANDbarrier.c
 */

#include <stdio.h>
#include <omp.h>

int main()
{
    float res;
#pragma omp parallel
    {
        float B;
        int i, id, nthrds;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        for (i = id; i < niters; i += nthrds)
        {
            B = big_job(i);
#pragma omp critical
            res += consume(B); //线程等待它们的轮到——每次只有一个线程调用consume()
        }
    }
    return 0;
}
 
 //barrier
 double Arr[8],Brr[8];
 int numthrds;
 omp_set_num_threads(8);
 #pragma omp parallel
 {
     int id,nthrds;
     id = omp_get_thread_num();
     nthrds = omp_get_num_threads();
     if(id ==0) numthrds = nthrds;
     Arr[id] = big_ugly_calc(id,nthrds);
     #pragma omp barrier
     //线程会一直等待，直到所有线程都到达屏障。然后他们可以继续。
     Brr[id] = really_big_and_ugly(id,nthrds,Arr);

 }
 