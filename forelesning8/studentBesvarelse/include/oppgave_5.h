#ifndef _THREADING_H_
#define _THREADING_H_

typedef struct _BUFFER {
    char szBuffer[11]; // The student wrote 11 cuz of zero termination
    FILE *f;
    sem_t semNewTask;
    sem_t semTaskCompleted;
    int iExitProgram;
} BUFFER;

void *workerThread(void *buffer);

#endif // ndef _THREADING_H_
