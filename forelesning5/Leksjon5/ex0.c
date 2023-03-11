// ex0.c: Lession 5, exercise 0:
//
// cl /Od /Zi ex0.c
// gcc -O2 ex0.c -o ex0
//
// -or- make TARGET=ex0
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main (void)
{
   typedef struct {
      int iId;          // 4
      char szName[10];  // 10 + 2
      int iSalery;      // 4
   } EMPLOYEE1;

#pragma pack(1)
   typedef struct {
      int iId;          // 4
      char szName[10];  // 10
      int iSalery;      // 4
   } EMPLOYEE2;
#pragma pack()

   EMPLOYEE1 e1;
   EMPLOYEE2 e2;

   printf ("Unpacked: %d\n", (int)sizeof(e1));
   printf ("Packed: %d\n\n", (int)sizeof(e2));

   e2.iId = 7;
   strcpy (e2.szName, "Bolla");
   e2.iSalery = 42;

   EMPLOYEE1 *pe;
   pe = (EMPLOYEE1 *) malloc (sizeof(EMPLOYEE1));

   pe->iId = e2.iId;
   strcpy (pe->szName, e2.szName);
   pe->iSalery = e2.iSalery;

   printf ("Id=%d\n", pe->iId);
   printf ("Name=%s\n", pe->szName);
   printf ("Salery=%d\n\n", pe->iSalery);

   // e1 = e2;  // Doesn't compile. "=" for same struct types is Ok.

   memcpy (&e1, &e2, sizeof(e2)); // Another way to copy.

   printf ("Id=%d\n", e2.iId);
   printf ("Name=%s\n", e2.szName);
   printf ("Salery=%d\n\n", e2.iSalery);

   printf ("Id=%d\n", e1.iId);
   printf ("Name=%s\n", e1.szName);
   printf ("Salery=%d\n", e1.iSalery);

}
