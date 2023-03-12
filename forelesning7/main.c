#include <stdio.h>
#include "pgdbglog.h"


int main (int iArgC, char *apszArgV[]) {


	PgDbgInitializer();
	unsigned long ulBytes = 100;
	printf("Hello.\n");
	pgdebug("Test");
	printf("Hello.\n");
	pgerror("Malloc failed to allocate %i bytes", ulBytes);
	return 0;

}

// bengt@ostby.net
// fag = Etisk Hacking / Cyberforsvar 


