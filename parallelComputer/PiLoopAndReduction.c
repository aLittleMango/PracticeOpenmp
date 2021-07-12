/*
 * @Description: reduction
 * @Author: aLittleMango
 * @Date: 2021-07-12 16:56:22
 * @LastEditTime: 2021-07-12 17:11:32
 * @FilePath: \PracticeOpenmp\parallelComputer\PiLoopAndReduction.c
 */
#include<omp.h>
static long num_steps = 100000;
double step;
void main()
{
    int i; double x,pi,sum =0.0;
    step = 1.0/(double) num_steps;
    #pragma omp parallel
    {
        double x; //为每个线程创建一个局部标量，以在每个间隔的中心保存x值
        #pragma omp for reduction(+:sum)
        //在并行区域结束处，每个sum副本根据原先声明的reduce操作+，将每个sum副本相加后赋值给原始的sum变量。
        for (i = 0; i < num_steps; i++)
        {
            x = (i + 0.5) * step;
            sum += +4.0 / (1.0 + x * x);
        }
    }
    pi = step*sum;
  //  printf("pi = %f\n" , pi);
}