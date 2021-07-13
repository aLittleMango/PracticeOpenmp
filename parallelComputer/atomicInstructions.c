/*
 * @Description: atomic指令
 * @Author: aLittleMango
 * @Date: 2021-07-13 11:51:22
 * @LastEditTime: 2021-07-13 11:55:29
 * @FilePath: \PracticeOpenmp\parallelComputer\atomicInstructions.c
 */
#include <omp.h>
#include <stdio.h>
int main()
{
    int x = 0;
#pragma omp parallel num_threads(6)
    {
        for (int i = 0; i < 1000; ++i)
#pragma omp atomic  
            x++;
    }
    printf("%d", x);
}