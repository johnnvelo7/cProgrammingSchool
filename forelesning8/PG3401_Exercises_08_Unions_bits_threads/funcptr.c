#include <stdio.h>
#include <stdarg.h>

void PrintString(const char *pszStr)
{
   printf("String: %s\n", pszStr);
}

typedef void (FNPRINT)(const char *);

int main(void)
{

   FNPRINT *pfnPrint = &PrintString;

   pfnPrint("Hallo");
   PrintString("Pa Badet");

}
