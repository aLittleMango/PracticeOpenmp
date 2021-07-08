/*
 * @Description: 
 * @Author: aLittleMango
 * @Date: 2021-07-08 17:23:16
 * @LastEditTime: 2021-07-08 20:09:35
 * @FilePath: \PracticeOpenmp\parallelComputer\hello.c
 */

// opneMP include file
#include <omp.h>
#include <stdio.h>
int main()
{
    // paralle region with default number of threads
    #pragma omp parallel
    {
        printf("hello ");
        printf("world\n");
        getchar();
    } //end of the parallel region 
}