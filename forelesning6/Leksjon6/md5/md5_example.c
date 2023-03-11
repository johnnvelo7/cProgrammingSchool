#include <stdio.h>
#include <md5.h>

/*
Output should be:
d41d8cd98f00b204e9800998ecf8427e
900150983cd24fb0d6963f7d28e17f72
d174ab98d277d9f5a5611c2c9f419d9f
*/

void print_hash(char hash[])
{
   int idx;
   for (idx=0; idx < 16; idx++)
      printf("%02x",hash[idx]);
   printf("\n");
}

int main()
{
   char hash[16],
        in1[]={""},
        in2[]={"abc"},
        in3_1[]={"ABCDEFGHIJKLMNOPQRSTUVWXYZabcde"},
        in3_2[]={"fghijklmnopqrstuvwxyz0123456789"};
   unsigned int len;
   MD5_CTX ctx;

   // First hash
   md5_init(&ctx);
   md5_update(&ctx,in1,strlen(in1));
   md5_final(&ctx,hash);
   print_hash(hash);

   // Second hash (note the MD5 object can be reused)
   md5_init(&ctx);
   md5_update(&ctx,in2,strlen(in2));
   md5_final(&ctx,hash);
   print_hash(hash);

   // Third hash (note the data is being added in two chunks)
   md5_init(&ctx);
   md5_update(&ctx,in3_1,strlen(in3_1));
   md5_update(&ctx,in3_2,strlen(in3_2));
   md5_final(&ctx,hash);
   print_hash(hash);

   getchar();
   return 0;
}
