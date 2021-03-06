/*
 * global_execution_queue.cpp
 *
 * @date Dec 8, 2018
 * @author Andrey Belomutskiy, (c) 2012-2018
 */

#include "signal_executor.h"
#include "event_queue.h"

// this global instance is used by integration tests via 'scheduleByTimestamp' global methods below
EventQueue schedulingQueue;

bool_t debugSignalExecutor = false;

void scheduleForLater(scheduling_s *scheduling, int delayUs,
		schfunc_t callback, void *param) {
	if (debugSignalExecutor) {
		printf("scheduleTask %d\r\n", delayUs);
	}
	scheduleByTimestamp(scheduling, getTimeNowUs() + delayUs, callback, param);
}

void scheduleByTimestamp(scheduling_s *scheduling,
		efitimeus_t time, schfunc_t callback, void *param) {
	if (debugSignalExecutor) {
		printf("scheduleByTime %d\r\n", time);
	}
	schedulingQueue.insertTask(scheduling, time, callback, param);
}

void initSignalExecutorImpl(void) {
}

