#define SCHEDULER_TYPE_ROUND_ROBIN_NONPREMPTIVE 0

void initScheduler();
void startScheduler();
void addTask(void (*new_task) (const char*), const char*);
