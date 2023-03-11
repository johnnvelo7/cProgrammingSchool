// print_md5.c: Lession 6 - examples
//
// Example: Read a file and calculate the MD5 checksum.
//

#include <stdio.h>
#include "md5.h"

#define BUFFER_SIZE 1024

void PrintHash (BYTE byHash[]);

int main (int iArgC, char *apszArgV[])
{
   FILE *f;
   MD5_CTX ctx;                // Needed by the library.
   BYTE byHash[16];            // BYTE is defined in md5.h as "typedef unsigned char BYTE"
   BYTE byBuffer[BUFFER_SIZE]; // Used to read the file in chunks.
   int iReadBytes;             // Number of bytes read

   if (iArgC < 2) {
      printf ("Usage: print_md5 <file name>\n");
      return 1;
   }
   f = fopen (apszArgV[1], "rb+");
   if (f != NULL) {

      md5_init(&ctx);   // Initialize the ctx.

      while (!feof(f)) {
         iReadBytes = fread(byBuffer, sizeof(BYTE), BUFFER_SIZE, f);
         md5_update(&ctx, byBuffer, iReadBytes);  // Add data to the hash
         if (iReadBytes < BUFFER_SIZE) break;
      }

      md5_final(&ctx, byHash);

      // (Hint: file position is now at the end of the file. If you now write to
      //  the file, this will be added to the end of it)

      printf("File:%s Md5:", apszArgV[1]);
      PrintHash (byHash);
      printf ("\n");

      fclose (f);
   }
}

void PrintHash (BYTE byHash[])
{
   for (int i = 0; i < 15; i++) {
      printf ("%02X", byHash[i]);
   }
}


