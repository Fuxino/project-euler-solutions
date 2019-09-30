/* In the game, Monopoly, the standard board is set up in the following way:
 *
 *       GO   A1   CC1   A2   T1   R1   B1   CH1   B2   B3   JAIL
 *
 *       H2	 	                                              C1
 *
 *       T2	 	                                              U1
 *
 *       H1	 	                                              C2
 *
 *       CH3	 	                                           C3
 *
 *       R4	 	                                              R2
 *
 *       G3	 	                                              D1
 *
 *       CC3	 	                                           CC2
 *
 *       G2	 	                                              D2
 *
 *       G1	 	                                              D3
 *
 *       G2J   F3   U2   F2   F1   R3   E3   E2   CH2   E1   FP
 *
 * A player starts on the GO square and adds the scores on two 6-sided dice to determine the number of squares they advance
 * in a clockwise direction. Without any further rules we would expect to visit each square with equal probability: 2.5%.
 * However, landing on G2J (Go To Jail), CC (community chest), and CH (chance) changes this distribution.
 *
 * In addition to G2J, and one card from each of CC and CH, that orders the player to go directly to jail, if a player rolls
 * three consecutive doubles, they do not advance the result of their 3rd roll. Instead they proceed directly to jail.
 *
 * At the beginning of the game, the CC and CH cards are shuffled. When a player lands on CC or CH they take a card from the top
 * of the respective pile and, after following the instructions, it is returned to the bottom of the pile. There are sixteen cards
 * in each pile, but for the purpose of this problem we are only concerned with cards that order a movement; any instruction
 * not concerned with movement will be ignored and the player will remain on the CC/CH square.
 *
 * Community Chest (2/16 cards):
 *
 * Advance to GO
 * Go to JAIL
 *
 * Chance (10/16 cards):
 * Advance to GO
 * Go to JAIL
 * Go to C1
 * Go to E3
 * Go to H2
 * Go to R1
 * Go to next R (railway company)
 * Go to next R
 * Go to next U (utility company)
 * Go back 3 squares.
 *
 * The heart of this problem concerns the likelihood of visiting a particular square. That is, the probability of finishing
 * at that square after a roll. For this reason it should be clear that, with the exception of G2J for which the probability 
 * of finishing on it is zero, the CH squares will have the lowest probabilities, as 5/8 request a movement to another square,
 * and it is the final square that the player finishes at on each roll that we are interested in. We shall make no distinction
 * between "Just Visiting" and being sent to JAIL, and we shall also ignore the rule about requiring a double to "get out of jail",
 * assuming that they pay to get out on their next turn.
 *
 * By starting at GO and numbering the squares sequentially from 00 to 39 we can concatenate these two-digit numbers to produce
 * strings that correspond with sets of squares.
 *
 * Statistically it can be shown that the three most popular squares, in order, are JAIL (6.24%) = Square 10, E3 (3.18%) = Square 24,
 * and GO (3.09%) = Square 00. So these three most popular squares can be listed with the six-digit modal string: 102400.
 *
 * If, instead of using two 6-sided dice, two 4-sided dice are used, find the six-digit modal string.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 1000000

/* Define the squares, the type of Community Chest cards and the type of Chance cards.*/
typedef enum {GO, A1, CC1, A2, T1, R1, B1, CH1, B2, B3, JAIL,
   C1, U1, C2, C3, R2, D1, CC2, D2, D3, FP, E1, CH2, E2, E3, R3, F1,
   F2, U2, F3, G2J, G1, G2, CC3, G3, R4, CH3, H1, T2, H2} squares;
typedef enum {GO_cc, JAIL_cc, NOP_cc} cc_card;
typedef enum {GO_ch, JAIL_ch, C1_ch, E3_ch, H2_ch, R1_ch, R_ch1, R_ch2, U_ch, M3, NOP_ch} ch_card;

void shuffle_cc(cc_card cc[]);
void shuffle_ch(ch_card ch[]);
void play(long int *count_squares);

int main(int argc, char **argv)
{
   int i, j, max, max_i;
   long int count_squares[40] = {0};
   char sq[3], *res;
   double elapsed;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   srand(time(NULL));

   /* Play Monopoly.*/
   play(count_squares);

   if((res = (char *)malloc(7*sizeof(char))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   /* Find the three squares with maximum count.*/ 
   for(i = 0; i < 3; i++)
   {
      max = -1;

      for(j = 0; j < 40; j++)
      {
         if(count_squares[j] > max)
         {
            max = count_squares[j];
            max_i = j;
         }
      }

      if(max_i < 10)
      {
         sprintf(sq, "0%d", max_i);
      }
      else
      {
         sprintf(sq, "%d", max_i);
      }

      res = strcat(res, sq);

      count_squares[max_i] = 0;
   }

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 84\n");
   printf("Answer: %s\n", res);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   free(res);

   return 0;
}

/* Shuffle the Community Chest cards.*/
void shuffle_cc(cc_card cc[])
{
   int i;
   cc_card c;

   for(i = 0; i < 16; i++)
   {
      cc[i] = NOP_cc;
   }

   c = GO_cc;

   do
   {
      do
      {
         i = rand() % 16;
      }while(cc[i] != NOP_cc);

      cc[i] = c;
      c++;
   }while(c < NOP_cc);
}

/* Shuffle the Chance cards.*/
void shuffle_ch(ch_card ch[])
{
   int i;
   ch_card h;

   for(i = 0; i < 16; i++)
   {
      ch[i] = NOP_ch;
   }

   h = GO_ch;

   do
   {
      do
      {
         i = rand() % 16;
      }while(ch[i] != NOP_ch);

      ch[i] = h;
      h++;
   }while(h < NOP_ch);
}

/* Function to play Monopoly, rolling the dice N times.*/
void play(long int *count_squares)
{
   int i, d1, d2, cc_i, ch_i, count_doubles;
   squares current;
   cc_card cc[16];
   ch_card ch[16];
  
   /* Start from GO.*/
   current = GO;
   count_squares[GO]++;
   cc_i = 0;
   ch_i = 0;
   count_doubles = 0;

   shuffle_cc(cc);
   shuffle_ch(ch);

   for(i = 0; i < N; i++)
   {
      /* Roll the dice.*/
      d1 = 1 + rand() % 4;
      d2 = 1 + rand() % 4;

      /* Check if it's a double. Increment the doubles counter if yes,
       * reset it if no.*/
      if(d1 == d2)
      {
         count_doubles++;
      }
      else
      {
         count_doubles=0;
      }

      /* If this is the third double in a row, go to JAIL and reset
       * the doubles counter.*/
      if(count_doubles == 3)
      {
         current = JAIL;
         count_doubles = 0;
      }
      else
      {
         /* Move based on the dice roll.*/
         current = (current + d1 + d2) % 40;

         /* If you get to the Go to JAIL square, go to JAIL.*/
         if(current == G2J)
         {
            current = JAIL;
         }
         /* If you get to one of the Community Chest squares, get a CC card.*/
         else if(current == CC1 || current == CC2 || current == CC3)
         {
            /* Go to GO.*/
            if(cc[cc_i] == GO_cc)
            {
               current = GO;
            }
            /* Go to JAIL.*/
            else if(cc[cc_i] == JAIL_cc)
            {
               current = JAIL;
            }
            /* Otherwise do nothing.*/

            cc_i = (cc_i + 1) % 16;
         }
         /* If you get to one of the Chance squares, get a CH card.*/
         else if(current == CH1 || current == CH2 || current == CH3)
         {
            /* Go to GO.*/
            if(ch[ch_i] == GO_ch)
            {
               current = GO;
            }
            /* Go to JAIL.*/
            else if(ch[ch_i] == JAIL_ch)
            {
               current = JAIL;
            }
            /* Go to C1.*/
            else if(ch[ch_i] == C1_ch)
            {
               current = C1;
            }
            /* Go to E3.*/
            else if(ch[ch_i] == E3_ch)
            {
               current = E3;
            }
            /* Go to H2.*/
            else if(ch[ch_i] == H2_ch)
            {
               current = H2;
            }
            /* Go to R1.*/
            else if(ch[ch_i] == R1_ch)
            {
               current = R1;
            }
            /* Go to the next Railway station.*/
            else if(ch[ch_i] == R_ch1 || ch[ch_i] == R_ch2)
            {
               do
               {
                  current = (current + 1) % 40;
               }while(current != R1 && current != R2 && current != R3 && current != R4);
            }
            /* Go to the next Utility company.*/
            else if(ch[ch_i] == U_ch)
            {
               do
               {
                  current = (current + 1) % 40;
               }while(current != U1 && current != U2);
            }
            /* Go back three squares.*/
            else if(ch[ch_i] == M3)
            {
               current = current - 3;

               /* If you get to Community Chest 3, get a card.*/
               if(current == CC3)
               {
                  if(cc[cc_i] == GO_cc)
                  {
                     current = GO;
                  }
                  else if(cc[cc_i] == JAIL_cc)
                  {
                     current=JAIL;
                  }

                  cc_i = (cc_i + 1) % 16;
               }
            }

            ch_i = (ch_i + 1) % 16;
         }
      }

      /* Increase the counter for the current square.*/
      count_squares[current]++;
   }
}
