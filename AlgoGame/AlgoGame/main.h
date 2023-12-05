#ifndef __STDIO_H__
#define __STDIO_H__

#include <stdio.h>

#endif

#ifndef __WINDOWS_H__
#define __WINDOWS_H__

#include <windows.h>

#endif

#ifndef __TIME_H__
#define __TIME_H__

#include <time.h>

#endif

#ifndef __CONIO_H__
#define __CONIO_H__

#include <conio.h>

#endif

#ifndef __MMSYSTEM_H__
#define __MMSYSTEM_H__

#include <mmsystem.h>

#endif


#ifndef STRUCT_INFO
#define STRUCT_INFO

#define QUEUE_MAX 24

typedef struct Queue
{
	int array[QUEUE_MAX];
	int front;
	int rear;
} Queue;

typedef struct PCInfo {
	int x;
	int y;
	int dir;
} PCInfo;

#endif