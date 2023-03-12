#include <stdio.h>
#include "pgdbglog.h"
#include <stdarg.h>


void PgDbgLogger (unsigned long ulErrorType, int iLine, const char *szFile, const char *pszFormat, ...){

	static FILE *fLogFile = NULL;
	static int lineNumber = 1;
	
	if (fLogFile == NULL) {
		fLogFile = fopen("debug.txt", "w");
	}
	
	va_list args;
	va_start(args, pszFormat);
	
	char outputString[256] = {0};
	
	vsnprintf(outputString, sizeof(outputString) -1, pszFormat, args);
	va_end(args);
	
	const char *type = (ulErrorType == 1) ? "Error" : "Debug";
	fprintf(fLogFile, "%s:%d %s %s\n", szFile, iLine, type, outputString);
	fflush(fLogFile);
	
	printf("HEllo madafakas.\n");
}

