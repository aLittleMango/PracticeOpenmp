/*
 * @Description: 并行区域嵌套设置
 * @Author: aLittleMango
 * @Date: 2021-07-08 20:43:01
 * @LastEditTime: 2021-07-08 20:57:27
 * @FilePath: \PracticeOpenmp\parallelComputer\parallelNested.c
 */

#include <omp.h>
#include <stdio.h>

int main()
{
    omp_set_dynamic(1);     //启动动态分配线程数
    omp_set_num_threads(3); //设置线程数为6个

    int out_ID, out_nthrds;
    omp_set_nested(0);
#pragma omp parallel private(out_ID)
    {

        out_ID = omp_get_thread_num();
        printf("hello from out thread = %d\n", out_ID);

        if (out_ID == 0)
        {
            out_nthrds = omp_get_num_threads();
            printf("Number of out threads = %d\n", out_nthrds);
        }
        int in_ID, in_nthrds;
#pragma omp parallel private(in_ID)
        {
            in_ID = omp_get_thread_num();
            printf("hello from in thread = %d,out thread = %d\n", in_ID, out_ID);

            if (in_ID == 0)
            {
                in_nthrds = omp_get_num_threads();
                printf("Number of in threads = %d,out thread = %d\n", in_nthrds, out_nthrds);
            }
        }
    }
}
