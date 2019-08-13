#include <stdint.h>
#include <string.h>
#include "include/scheduler.h"

#define MAX_TASKS 10
#define MAX_TASK_DESCRIPTION_LENGTH 64

static uint8_t num_tasks;
static void (*ready_tasks[MAX_TASKS]) (const char*);
static char task_description[MAX_TASKS][MAX_TASK_DESCRIPTION_LENGTH];

void initScheduler() 
{
	// Currently nothing to be done.	
}

void startScheduler()
{
	int curr_task = 0;

	while(1) {
		ready_tasks[curr_task] (task_description[curr_task]);
		curr_task = (curr_task + 1) % num_tasks;
	}
}

void addTask(void (*new_task) (const char*), const char* description) {

	ready_tasks[num_tasks] = new_task;
	memcpy(&(task_description[num_tasks]), description, MAX_TASK_DESCRIPTION_LENGTH);
	num_tasks++;
}
