/* Each character on a computer is assigned a unique code and the preferred standard is ASCII (American Standard Code for Information Interchange).
 * For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.
 *
 * A modern encryption method is to take a text file, convert the bytes to ASCII, then XOR each byte with a given value, taken from a secret key.
 * The advantage with the XOR function is that using the same encryption key on the cipher text, restores the plain text; for example, 65 XOR 42 = 107,
 * then 107 XOR 42 = 65.
 *
 * For unbreakable encryption, the key is the same length as the plain text message, and the key is made up of random bytes. The user would keep
 * the encrypted message and the encryption key in different locations, and without both "halves", it is impossible to decrypt the message.
 *
 * Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. If the password is shorter than
 * the message, which is likely, the key is repeated cyclically throughout the message. The balance for this method is using a sufficiently long
 * password key for security, but short enough to be memorable.
 *
 * Your task has been made easy, as the encryption key consists of three lower case characters. Using cipher.txt, a file containing the
 * encrypted ASCII codes, and the knowledge that the plain text must contain common English words, decrypt the message and find the sum of the
 * ASCII values in the original text.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(int argc, char **argv)
{
   int i, j, n, sum, found = 0;
   double elapsed;
   char c1, c2, c3, dummy;
   char *enc_text, *plain_text;
   FILE *fp;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("cipher.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "cipher.txt");
      return 1;
   }

   n = 0;

   /* Count the number of characters (i.e. ASCII values) in the file.*/
   while(fscanf(fp, "%d%c", &i, &dummy) != EOF)
   {
      n++;
   }

   fclose(fp);

   if((enc_text = (char *)malloc(n*sizeof(char))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   if((plain_text = (char *)malloc((n+1)*sizeof(char))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   if((fp = fopen("cipher.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "cipher.txt");
      return 1;
   }

   /* Save the encrypted text.*/
   for(i = 0; i < n; i++)
   {
      fscanf(fp, "%d%c", &j, &dummy);
      enc_text[i] = (char)j;
   }

   fclose(fp);

   /* Try every combination of three lowercase letters until the key is found.*/
   for(c1 = 'a'; c1 <= 'z' && !found; c1++)
   {
      for(c2 = 'a'; c2 <= 'z' && !found; c2++)
      {
         for(c3 = 'a'; c3 <= 'z' && !found; c3++)
         {
            /* Try the current key.*/
            for(i = 0; i < n - 2; i += 3)
            {
               plain_text[i] = enc_text[i] ^ c1;
               plain_text[i+1] = enc_text[i+1] ^ c2;
               plain_text[i+2] = enc_text[i+2] ^ c3;
            }

            /* Since a step of 3 was used, the last two characters or
             * just the last one might not have been decrypted yet.*/
            if(i == n - 2)
            {
               plain_text[i] = enc_text[i] ^ c1;
               plain_text[i+1] = enc_text[i+1] ^ c2;
            }
            
            if(i == n - 1)
            {
               plain_text[i] = enc_text[i] ^ c1;
            }

            /* Set string terminator.*/
            plain_text[n] = 0;

            /* Check if the decrypted text contains the 8 most common English words. If it does,
             * the right key was likely found.*/
            if(strstr(plain_text, "the") != NULL && strstr(plain_text, "be") != NULL &&
                  strstr(plain_text, "to") != NULL && strstr(plain_text, "of") != NULL &&
                  strstr(plain_text, "and") != NULL & strstr(plain_text, "in") != NULL &&
                  strstr(plain_text, "that") != NULL && strstr(plain_text, "have") != NULL)
            {
               sum = 0;

               /* Sum the ASCII values.*/
               for(i = 0; i < n; i++)
               {
                  sum += (int)plain_text[i];
               }

               found = 1;
               printf("%c%c%c\n", c1, c2, c3);
            }
         }
      }
   }

   free(enc_text);
   free(plain_text);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed=(end.tv_sec-start.tv_sec)+(double)(end.tv_nsec-start.tv_nsec)/1000000000;

   printf("Project Euler, Problem 59\n");
   printf("Answer: %d\n", sum);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}
