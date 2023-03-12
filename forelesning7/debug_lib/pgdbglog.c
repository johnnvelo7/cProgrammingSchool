#include <stdio.h>
#include "pgdbglog.h"
#include <stdarg.h>
#include <time.h>


static FILE *fLogFile = NULL;

void PgDbgLogger (unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

	if (fLogFile == NULL){
		char szFileName[MAX_FILENAME_LEN] = {0};
		time_t tTimeAndDate = 0;
		tTimeAndDate = time(NULL);
		snprintf(szFileName, MAX_FILENAME_LEN -1, "debug_%i.txt", tTimeAndDate);
		
		fLogFile = fopen(szFileName, "w");
		if (fLogFile == NULL){
			fprintf(stderr, "Failed to open log file '%s'!", szFileName);
			return;
		}
	}

	va_list vaArgumentPointer;
	char outputString[256] = {0};
	const char *type = (ulErrorType == 1) ? "Error" : "Debug";
	
	va_start(vaArgumentPointer, pszFormat);
	vsnprintf(outputString, sizeof(outputString) -1, pszFormat, vaArgumentPointer);
	va_end(vaArgumentPointer);
	
	fprintf(fLogFile, "%s (in source code:%s, line: %d)\n", outputString, szFile, iLine);
	fflush(fLogFile);
	
	printf("HEllo madafakas.\n");
}



