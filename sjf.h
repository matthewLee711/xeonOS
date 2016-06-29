#ifndef SJF_HEADER
#define SJF_HEADER

#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

void SJFscheduler(List * list);
void SJFschedulerDynamic(int id, int arrival_time, int burst_time, int priority);
void SJFdisplayPCB(List * list);

#endif
