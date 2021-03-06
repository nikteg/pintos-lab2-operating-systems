/* Tests cetegorical mutual exclusion with different numbers of threads.
 * Automatic checks only catch severe problems like crashes.
 */
#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/synch.h"
#include "threads/thread.h"

#include "devices/batch-scheduler.c"



void test_batch_scheduler(void)
{
    int i = 0;
    init_bus();

    int start_count = get_thread_count();

    batchScheduler(0, 0, 0, 0);
    batchScheduler(1, 0, 0, 0);
    batchScheduler(0, 0, 0, 1);
    batchScheduler(0, 4, 0, 0);
    batchScheduler(0, 0, 4, 0);
    batchScheduler(3, 3, 3, 3);
    batchScheduler(4, 3, 4 ,3);
    batchScheduler(7, 23, 17, 1);
    batchScheduler(40, 30, 0, 0);
    batchScheduler(30, 40, 0, 0);
    batchScheduler(23, 23, 1, 11);
    batchScheduler(22, 22, 10, 10);
    batchScheduler(0, 0, 11, 12);
    batchScheduler(0, 10, 0, 10);
    batchScheduler(0, 10, 10, 0);

    batchScheduler(40, 30, 0, 0);
    timer_sleep((int64_t)5000);
    printf("Scheduling some more priorities\n");
    batchScheduler(0, 0, 11, 12);

    while(get_thread_count() - start_count > 0)
    {
        i++;
    }
    pass();
}
