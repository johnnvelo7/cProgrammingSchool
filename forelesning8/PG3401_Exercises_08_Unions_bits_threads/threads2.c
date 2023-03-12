#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int iCounter = 0;

void *PrintMessage (void *pvData)
{
   char *pszMessage = (char *)pvData;

   iCounter += 1;
   printf ("In %s: iCounter=%d\n", pszMessage, iCounter);
   usleep(200);

   iCounter += 1;
   printf ("In %s: iCounter=%d\n", pszMessage, iCounter);
   usleep(200);

   return NULL;
}

void main (void)
{
   pthread_t pThread1, pThread2;
   char *pszMessage1 = "Thread 1";
   char *pszMessage2 = "Thread 2";

   printf("Before threads started.\n");

   pthread_create (&pThread1, NULL, PrintMessage, (void *) pszMessage1);
   pthread_create (&pThread2, NULL, PrintMessage, (void *) pszMessage2);

   printf("After threads started.\n");

   pthread_join(pThread1, NULL);  // Wait for thread 1 to finish.
   pthread_join(pThread2, NULL);  // Wait for thread 2 to finish.

   printf("After threads finished.\n");
}
