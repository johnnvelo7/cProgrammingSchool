#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>

#include "./include/oppgave_5.h"

#define USERINPUT_BUFFER 4096

int main(int argc, char *argv[]) {

    char szUserInput[USERINPUT_BUFFER] = "";

    FILE *f = NULL;
    f = fopen("text.txt", "a"); // Can use "w" to start the file as blank each time you run the program

    // Create buffer
    BUFFER *pBuf = malloc(sizeof(BUFFER)); 
    pBuf->f = f;
    pBuf->iExitProgram = 0; 
    //can be put on stack because its small 

    // Init semaphore
    sem_init(&pBuf->semNewTask, 0, 0);
    sem_init(&pBuf->semTaskCompleted, 0, 0);

    // Create thread
    pthread_t tWorker;

    // Start thread
    pthread_create(&tWorker, NULL, workerThread, (void *) pBuf);

    printf("Skriv tekststrenger adskilt med ENTER tast (tast 'quit' for å avlsutte programmet): \n");
    while(pBuf->iExitProgram == 0) {
        char *pszReturn = fgets(szUserInput, USERINPUT_BUFFER, stdin);
			//fgets not scanf to hinder buffer overflow 
        if (strcmp(szUserInput, "quit\n") != 0) {

            int iStart = 0;

            // Read the whole input
            while(iStart <= (strlen(szUserInput) - 1)) {

                // Copy 10 and 10 bytes for the thread to write to file
                strncpy(pBuf->szBuffer, &szUserInput[iStart], 10);
                pBuf->szBuffer[10] = 0;
                
                // Signal to worker thread that a new task is ready to be executed
                sem_post(&pBuf->semNewTask);
                
                // Wait for worker thread to finish task
                sem_wait(&pBuf->semTaskCompleted);
                
                iStart += 10;
                
                //THe last two codes are simple and very efficient 
                
            }
        } else {
            pBuf->iExitProgram = 1;

            // Signal to worker thread that a new task is ready to be executed, this time to just to terminate thread
            sem_post(&pBuf->semNewTask);
        } 
    }

    // Wait for thread to terminate and close file
    pthread_join(tWorker, NULL);
    fclose(f);

    // Destroy semaphores and free allocated buffer
    sem_destroy(&pBuf->semNewTask);
    sem_destroy(&pBuf->semTaskCompleted);
    free(pBuf);

	//Everything that was created and mem allocated should also be free
    return 0;
}

void *workerThread(void *buffer) {
    
    BUFFER *pBuf = (BUFFER*) buffer;
    while(pBuf->iExitProgram == 0) {

        // Wait for signal to execute task
        sem_wait(&pBuf->semNewTask);

        // Exit the while loop if exit variable in struct is not 0
        if(pBuf->iExitProgram != 0) {
            break;
        }

        fprintf(pBuf->f, "%s", pBuf->szBuffer);

        // Can use fflush to write to file as the program runs
        //fflush(pBuf->f);

        // Signal that task is completed
        sem_post(&pBuf->semTaskCompleted);
    }
    
    return NULL;
}

// Use mutex and Semaphore / condition together as good code practice 
