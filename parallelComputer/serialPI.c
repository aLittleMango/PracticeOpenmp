/*
 * @Description: 计算圆周率pi
 * @Author: aLittleMango
 * @Date: 2021-07-09 11:46:02
 * @LastEditTime: 2021-07-09 15:29:15
 * @FilePath: \PracticeOpenmp\parallelComputer\serialPI.c
 */
#include <stdio.h>
#include <omp.h>

static long num_steps = 10 ^ 600;
double step;
//通过填充sum数组来消除错误共享
#define PAD 8 
#define NUM_THREADS 4
int main()
{
    int i, nthreads;
    double x, pi, sum[NUM_THREADS][PAD];  //填充数组，使每个sum值在不同的缓存行中
    step = 1.0 / (double)num_steps;
    omp_set_num_threads(NUM_THREADS);
#pragma omp parallel
    {
        int i, id, nthrds;
        double x;
        id = omp_get_thread_num();
        nthrds = omp_get_num_threads();
        if (id == 0)
            nthreads = nthrds;
        for (i = id, sum[id][0] = 0.0; i < num_steps; i = i + nthrds)
        {
            x = (i + 0.5) * step;
            sum[id][0] += +4.0 / (1.0 + x * x);
        }
    }
    for (i = 0, pi = 0.0; i < nthreads; i++)
        pi += sum[i][0] * step;

    printf("pi = %f\n" , pi);
    return 0;
}