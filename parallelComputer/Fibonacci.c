/*
 * @Description: 实现并行的斐波那契
 * @Author: aLittleMango
 * @Date: 2021-07-13 10:58:43
 * @LastEditTime: 2021-07-13 11:25:10
 * @FilePath: \PracticeOpenmp\parallelComputer\Fibonacci.c
 */
#include <stdio.h>
#include <omp.h>

int fib(int n)
{
    int x, y; //x,y对当前任务是私有的
    if (n < 2)
        return n;
//must be shared on child tasks so they don't create their own firstprivate copies
#pragma omp task shared(x) 
    x = fib(n - 1);
#pragma omp task shared(y)
    y = fib(n - 2);
//一个任务只有在树中它下面的所有任务都完成后才能完成，由taskwait强制执行
#pragma omp taskwait
    return (x + y);
}

void main()
{
    int NW = 6;
#pragma omp parallel
    {
//单一构造，由一个线程执行的代码块。在单个块的末尾隐含一个barrier
#pragma omp single
        printf("Fibonacci %d is %d\n", NW, fib(NW));
    }
}