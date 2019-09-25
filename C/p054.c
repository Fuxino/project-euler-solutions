/* In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
 *
 * High Card: Highest value card.
 * One Pair: Two cards of the same value.
 * Two Pairs: Two different pairs.
 * Three of a Kind: Three cards of the same value.
 * Straight: All cards are consecutive values.
 * Flush: All cards of the same suit.
 * Full House: Three of a kind and a pair.
 * Four of a Kind: Four cards of the same value.
 * Straight Flush: All cards are consecutive values of same suit.
 * Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
 * The cards are valued in the order:
 * 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
 *
 * If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives 
 * (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared
 * (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
 *
 * Consider the following five hands dealt to two players:
 *
 * Hand	 	Player 1	 	      Player 2	 	      Winner
 *  1	 	5H 5C 6S 7S KD    2C 3S 8S 8D TD        Player 2
 *       Pair of Fives     Pair of Eights
 *
 *  2	 	5D 8C 9S JS AC    2C 5C 7D 8S QH        Player 1
 *      Highest card Ace   Highest card Queen
 *
 *  3	 	2D 9C AS AH AC    3D 6D 7D TD QD        Player 2
 *        Three Aces      Flush with Diamonds
 *
 *  4	 	4D 6S 9H QH QC    3D 6D 7H QD QS        Player 1
 *       Pair of Queens    Pair of Queens
 *      Highest card Nine Highest card Seven
 *
 *  5	 	2H 2D 4C 4D 4S    3C 3D 3S 9S 9D        Player 1
 *         Full House  	    Full House
 *      With Three Fours  With Three Threes
 *
 *      The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards
 *      (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
 *      You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order,
 *      and in each hand there is a clear winner.
 *
 *      How many hands does Player 1 win?*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "projecteuler.h"

/* Define the values of the cards.*/
typedef enum{two, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace} values;

/* Define a structure for a card, with value and suit.*/
typedef struct card
{
   values value;
   char suit;
}Card;

int eval(char *hands);

int main(int argc, char **argv)
{
   int i, count = 0;
   double elapsed;
   char **hands;
   FILE *fp;
   struct timespec start, end;

   clock_gettime(CLOCK_MONOTONIC, &start);

   if((fp = fopen("poker.txt", "r")) == NULL)
   {
      fprintf(stderr, "Error while opening file %s\n", "poker.txt");
      return 1;
   }

   if((hands = (char **)malloc(1000*sizeof(char *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      return 1;
   }

   for(i=0; i<1000; i++)
   {
      if((hands[i] = (char *)malloc(31*sizeof(char))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         return 1;
      }
   }

   for(i = 0; i < 1000; i++)
   {
      fgets(hands[i], 31*sizeof(char), fp);

      /* Count how many hands player 1 wins, using an evaluation function.*/
      if(eval(hands[i]) > 0)
      {
         count++;
      }
      free(hands[i]);
   }

   fclose(fp);
   free(hands);

   clock_gettime(CLOCK_MONOTONIC, &end);

   elapsed = (end.tv_sec - start.tv_sec) + (double)(end.tv_nsec - start.tv_nsec) / 1000000000;

   printf("Project Euler, Problem 54\n");
   printf("Answer: %d\n", count);

   printf("Elapsed time: %.9lf seconds\n", elapsed);

   return 0;
}

int compare(void *card1, void *card2)
{
   Card *c1, *c2;

   c1 = (Card *)card1;
   c2 = (Card *)card2;

   return c1->value - c2->value;
}

void get_value(Card *card, char value)
{
   if(value == '2')
   {
      card->value = two;
   }
   else if(value == '3')
   {
      card->value = three;
   }
   else if(value == '4')
   {
      card->value = four;
   }
   else if(value == '5')
   {
      card->value = five;
   }
   else if(value == '6')
   {
      card->value = six;
   }
   else if(value == '7')
   {
      card->value = seven;
   }
   else if(value == '8')
   {
      card->value = eight;
   }
   else if(value == '9')
   {
      card->value = nine;
   }
   else if(value == 'T')
   {
      card->value = ten;
   }
   else if(value == 'J')
   {
      card->value = jack;
   }
   else if(value == 'Q')
   {
      card->value = queen;
   }
   else if(value == 'K')
   {
      card->value = king;
   }
   else if(value == 'A')
   {
      card->value = ace;
   }
}

int eval(char *hands)
{
   int i, straightflush1 = 0, straightflush2 = 0, four1 = 0, four2 = 0, full1 = 0, full2 = 0, flush1 = 0, flush2 = 0;
   int straight1 = 0, straight2 = 0, three1 = 0, three2 = 0, twopairs1 = 0, twopairs2 = 0;
   int pair1 = 0, pair2 = 0;
   char *card;
   Card **cards1, **cards2;
   values value;

   if((cards1 = (Card **)malloc(5*sizeof(Card *))) == NULL ||
         (cards2 = (Card **)malloc(5*sizeof(Card *))) == NULL)
   {
      fprintf(stderr, "Error while allocating memory\n");
      exit(1);
   }

   for(i = 0; i < 5; i++)
   {
      if((cards1[i] = (Card *)malloc(sizeof(Card))) == NULL ||
            (cards2[i] = (Card *)malloc(sizeof(Card))) == NULL)
      {
         fprintf(stderr, "Error while allocating memory\n");
         exit(1);
      }
   }

   card = strtok(hands, " ");

   /* Get current hand for player 1.*/
   get_value(cards1[0], card[0]);
   cards1[0]->suit = card[1];

   for(i = 1; i < 5; i++)
   {
      card = strtok(NULL, " ");
      get_value(cards1[i], card[0]);
      cards1[i]->suit = card[1];
   }

   /* Get current hand for player 2.*/
   for(i = 0; i < 5; i++)
   {
      card = strtok(NULL, " ");
      get_value(cards2[i], card[0]);
      cards2[i]->suit = card[1];
   }

   /* Sort the two hands by value of the cards to make the evaluation easier.*/
   insertion_sort((void **)cards1, 0, 4, compare);
   insertion_sort((void **)cards2, 0, 4, compare);

   /* If player 1 has a Royal Flush, player 1 wins.*/
   if(cards1[4]->value == ace && cards1[3]->value == king && cards1[2]->value == queen && 
         cards1[1]->value == jack && cards1[0]->value == ten && cards1[0]->suit == cards1[1]->suit &&
         cards1[0]->suit == cards1[2]->suit && cards1[0]->suit == cards1[3]->suit &&
         cards1[0]->suit == cards1[4]->suit)
   {
      return 1;
   }

   /* If player 2 has a Royal Flush, player 2 wins.*/
   if(cards2[4]->value == ace && cards2[3]->value == king && cards2[2]->value == queen && 
         cards2[1]->value == jack && cards2[0]->value == ten && cards2[0]->suit == cards2[1]->suit &&
         cards2[0]->suit == cards2[2]->suit && cards2[0]->suit == cards2[3]->suit &&
         cards2[0]->suit == cards2[4]->suit)
   {
      return -1;
   }

   /* Check if player 1 has a straight flush.*/
   if(cards1[0]->suit == cards1[1]->suit && cards1[0]->suit == cards1[2]->suit && cards1[0]->suit == cards1[3]->suit &&
         cards1[0]->suit == cards1[4]->suit)
   {
      value = cards1[0]->value;

      for(i = 1; i < 5; i++)
      {
         if(++value != cards1[i]->value)
         {
            break;
         }
      }

      if(i == 5)
      {
         straightflush1=1;
      }
   }

   /* Check if player 2 has a straight flush.*/
   if(cards2[0]->suit == cards2[1]->suit && cards2[0]->suit == cards2[2]->suit && 
         cards2[0]->suit == cards2[3]->suit && cards2[0]->suit == cards2[4]->suit)
   {
      value = cards2[0]->value;

      for(i = 1; i < 5; i++)
      {
         if(++value != cards2[i]->value)
         {
            break;
         }
      }

      if(i == 5)
      {
         straightflush2=1;
      }
   }

   /* If player 1 has a straight flush and player 2 doesn't, player 1 wins.*/
   if(straightflush1 && !straightflush2)
   {
      return 1;
   }

   /* If player 2 has a straight flush and player 1 doesn't, player 2 wins.*/
   if(!straightflush1 && straightflush2)
   {
      return -1;
   }

   /* If both players have a straight flush, the one with the highest value wins.
    * Any card can be compared, because in the straight flush the values are consecutive
    * by definition.*/
   if(straightflush1 && straightflush2)
   {
      if(cards1[0]->value > cards2[0]->value)
      {
         return 1;
      }
      else
      {
         return -1;
      }
   }

   /* Check if player 1 has a four of a kind.*/
   if((cards1[0]->value == cards1[1]->value && cards1[0]->value == cards1[2]->value && cards1[0]->value == cards1[3]->value) ||
         (cards1[1]->value == cards1[2]->value && cards1[1]->value == cards1[3]->value && cards1[1]->value == cards1[4]->value))
   {
      four1 = 1;
   }

   /* Check if player 2 has a four of a kind.*/
   if((cards2[0]->value == cards2[1]->value && cards2[0]->value == cards2[2]->value && cards2[0]->value == cards2[3]->value) ||
         (cards2[1]->value == cards2[2]->value && cards2[1]->value == cards2[3]->value && cards2[1]->value == cards2[4]->value))
   {
      four2 = 1;
   }

   /* If player 1 has four of a kind and player 2 doesn't, player 1 wins.*/
   if(four1 && !four2)
   {
      return 1;
   }

   /* If player 2 has four of a kind and player 1 doesn't, player 2 wins.*/
   if(!four1 && four2)
   {
      return -1;
   }

   /* If both players have four of a kind, check who has the highest value for
    * those four cards. If they are equal, check the higest value for the different
    * card.*/
   if(four1 && four2)
   {
      if(cards1[1]->value > cards2[1]->value)
      {
         return 1;
      }
      else if(cards1[1]->value < cards2[1]->value)
      {
         return -1;
      }
      else
      {
         for(i = 4; i <= 0; i--)
         {
            if(cards1[i]->value > cards2[i]->value)
            {
               return 1;
            }

            if(cards1[i]->value < cards2[i]->value)
            {
               return -1;
            }
         }
      }
   }

   /* Check if player 1 has a full house.*/
   if(cards1[0]->value == cards1[1]->value && cards1[1]->value == cards1[2]->value && 
         cards1[1]->value == cards1[3]->value && cards1[1]->value == cards1[4]->value)
   {
      full1 = 1;
   }

   /* Check if player 2 has a full house.*/
   if(cards2[0]->value == cards2[1]->value && cards2[1]->value == cards2[2]->value && 
         cards2[1]->value == cards2[3]->value && cards2[1]->value == cards2[4]->value)
   {
      full2 = 1;
   }

   /* If player 1 has a full house and player 2 doesn't, player 1 wins.*/
   if(full1 && !full2)
   {
      return 1;
   }

   /* If player 2 has a full house and player 1 doesn't, player 2 wins.*/
   if(!full1 && full2)
   {
      return -1;
   }

   /* If both players have a full house, check who has the highest value
    * for the three equal cards (the third card in the array will be part
    * of the set of three). If they are equal, check the highest value
    * for the other two cards.*/
   if(full1 && full2)
   {
      if(cards1[2]->value > cards2[2]->value)
      {
         return 1;
      }

      if(cards1[2]->value < cards2[2]->value)
      {
         return -1;
      }

      for(i = 4; i >= 0; i--)
      {
         if(cards1[i]->value > cards2[i]->value)
         {
            return 1;
         }

         if(cards1[i]->value < cards2[i]->value)
         {
            return -1;
         }
      }
   }

   /* Check if player 1 has a flush.*/
   if(cards1[0]->suit == cards1[1]->suit && cards1[0]->suit == cards1[2]->suit &&
         cards1[0]->suit == cards1[3]->suit && cards1[0]->suit == cards1[4]->suit)
   {
      flush1 = 1;
   }

   /* Check if player 2 has a flush.*/
   if(cards2[0]->suit == cards2[1]->suit && cards2[0]->suit == cards2[2]->suit &&
         cards2[0]->suit == cards2[3]->suit && cards2[0]->suit == cards2[4]->suit)
   {
      flush2 = 1;
   }

   /* If player 1 has a flush and player 2 doesn't, player 1 wins.*/
   if(flush1 && !flush2)
   {
      return 1;
   }

   /* If player 2 has a flush and player 1 doesn't, player 2 wins.*/
   if(!flush1 && flush2)
   {
      return -1;
   }

   /* If both players have a flush, check who has the highest card, if
    * the highest is equal check the second highest and so on.*/
   if(flush1 && flush2)
   {
      for(i = 4; i <= 0; i--)
      {
         if(cards1[i]->value > cards2[i]->value)
         {
            return 1;
         }

         if(cards1[i]->value < cards2[i]->value)
         {
            return -1;
         }
      }
   }

   /* Check if player 1 has a straight.*/
   value = cards1[0]->value;

   for(i = 1; i < 5; i++)
   {
      if(++value != cards1[i]->value)
      {
         break;
      }
   }

   if(i == 5)
   {
      straight1 = 1;
   }

   /* Check if player 2 has a straight.*/
   value = cards2[0]->value;

   for(i = 1; i < 5; i++)
   {
      if(++value != cards2[i]->value)
      {
         break;
      }
   }

   if(i == 5)
   {
      straight2 = 1;
   }

   /* If player 1 has a straight and player 2 doesn't, player 1 wins.*/
   if(straight1 && !straight2)
   {
      return 1;
   }

   /* If player 2 has a straight and player 1 doesn't, player 2 wins.*/
   if(!straight1 && straight2)
   {
      return -1;
   }

   /* If both players have a straight, check who has the highest card.*/
   if(straight1 && straight2)
   {
      if(cards1[4]->value > cards2[4]->value)
      {
         return 1;
      }
      else
      {
         return -1;
      }
   }

   /* Check if player 1 has three of a kind.*/
   if((cards1[0]->value == cards1[1]->value && cards1[0]->value == cards1[2]->value) ||
         (cards1[1]->value == cards1[2]->value && cards1[1]->value == cards1[3]->value) ||
         (cards1[2]->value == cards1[3]->value && cards1[2]->value == cards1[4]->value))
   {
      three1 = 1;
   }

   /* Check if player 2 has three of a kind.*/
   if((cards2[0]->value == cards2[1]->value && cards2[0]->value == cards2[2]->value) ||
         (cards2[1]->value == cards2[2]->value && cards2[1]->value == cards2[3]->value) ||
         (cards2[2]->value == cards2[3]->value && cards2[2]->value == cards2[4]->value))
   {
      three2 = 1;
   }

   /* If player 1 has three of a kind and player 2 doesn't, player 1 wins.*/
   if(three1 && !three2)
   {
      return 1;
   }

   /* If player 2 has three of a kind and player 1 doesn't, player 2 wins.*/
   if(!three1 && three2)
   {
      return -1;
   }

   /* If both players have three of a kind, check who has the highest value for
    * these three cards. If it's equal, check who has the highest value for the
    * other cards.*/
   if(three1 && three2)
   {
      if(cards1[2]->value > cards2[2]->value)
      {
         return 1;
      }
      
      if(cards1[2]->value < cards2[2]->value)
      {
         return -1;
      }

      for(i = 4; i <= 0; i--)
      {
         if(cards1[i]->value > cards2[i]->value)
         {
            return 1;
         }

         if(cards1[i]->value < cards2[i]->value)
         {
            return -1;
         }
      }
   }

   /* Check if player 1 has two pairs.*/
   if((cards1[0]->value == cards1[1]->value && cards1[2]->value == cards1[3]->value) ||
         (cards1[0]->value == cards1[1]->value && cards1[3]->value == cards1[4]->value) ||
         (cards1[1]->value == cards1[2]->value && cards1[3]->value == cards1[4]->value))
   {
      twopairs1 = 1;
   }

   /* Check if player 2 has two pairs.*/
   if((cards2[0]->value == cards2[1]->value && cards2[2]->value == cards2[3]->value) ||
         (cards2[0]->value == cards2[1]->value && cards2[3]->value == cards2[4]->value) ||
         (cards2[1]->value == cards2[2]->value && cards2[3]->value == cards2[4]->value))
   {
      twopairs2 = 1;
   }

   /* If player 1 has two pairs and player 2 doesn't, player 1 wins.*/
   if(twopairs1 && !twopairs2)
   {
      return 1;
   }

   /* If player 2 has two pairs and player 1 doesn't, player 2 wins.*/
   if(!twopairs1 && twopairs2)
   {
      return -1;
   }

   /* If both players have two pairs, check who has the highest pair. If it's equal,
    * check the other pair. If it's still equal, check the remaining card.*/
   if(twopairs1 && twopairs2)
   {
      if(cards1[3]->value > cards2[3]->value)
      {
         return 1;
      }

      if(cards1[3]->value < cards2[3]->value)
      {
         return -1;
      }

      if(cards1[1]->value > cards2[1]->value)
      {
         return 1;
      }

      if(cards1[1]->value < cards2[1]->value)
      {
         return -1;
      }

      for(i = 4; i <= 0; i--)
      {
         if(cards1[i]->value > cards2[i]->value)
         {
            return 1;
         }

         if(cards1[i]->value < cards2[i]->value)
         {
            return -1;
         }
      }
   }

   /* Check if player 1 has a pair.*/
   if(cards1[0]->value == cards1[1]->value || cards1[1]->value == cards1[2]->value ||
         cards1[2]->value == cards1[3]->value || cards1[3]->value == cards1[4]->value)
   {
      pair1 = 1;
   }

   /* Check if player 2 has a pair.*/
   if(cards2[0]->value == cards2[1]->value || cards2[1]->value == cards2[2]->value ||
         cards2[2]->value == cards2[3]->value || cards2[3]->value == cards2[4]->value)
   {
      pair2 = 1;
   }

   /* If player 1 has a pair and player 2 doesn't, player 1 wins.*/
   if(pair1 && !pair2)
   {
      return 1;
   }

   /* If player 2 has a pair and player 1 doesn't, player 2 wins.*/
   if(!pair1 && pair2)
   {
      return -1;
   }

   /* If both players have a pair, check who has the highest pair. Since the cards are
    * ordered by value, either card[1] will be part of the pair (card[0]=card[1] or
    * card[1]=card[2]) or card[3] will be part of the pair (card[2]=card[3] or
    * card[3]=card[4]). */
   if(pair1 && pair2)
   {
      if(cards1[0]->value == cards1[1]->value || cards1[1]->value == cards1[2]->value)
      {
         value = cards1[1]->value;

         if(cards2[0]->value == cards2[1]->value || cards2[1]->value == cards2[2]->value)
         {
            if(value > cards2[1]->value)
            {
               return 1;
            }

            if(value < cards2[1]->value)
            {
               return -1;
            }
         }

         if(cards2[2]->value == cards2[3]->value || cards2[3]->value == cards2[4]->value)
         {
            if(value > cards2[3]->value)
            {
               return 1;
            }

            if(value < cards2[3]->value)
            {
               return -1;
            }
         }
      }
      else
      {
         value = cards1[3]->value;
         
         if(cards2[0]->value == cards2[1]->value || cards2[1]->value == cards2[2]->value)
         {
            if(value > cards2[1]->value)
            {
               return 1;
            }

            if(value < cards2[1]->value)
            {
               return -1;
            }
         }

         if(cards2[2]->value == cards2[3]->value || cards2[3]->value == cards2[4]->value)
         {
            if(value > cards2[3]->value)
            {
               return 1;
            }

            if(value < cards2[3]->value)
            {
               return -1;
            }
         }
      }
   }

   /* If the players have the same pair, or if both don't have a pair, check who has
    * the highest card, if it's equal check the second highest and so on.*/
   for(i = 4; i >= 0; i--)
   {
      if(cards1[i]->value > cards2[i]->value)
      {
         return 1;
      }

      if(cards1[i]->value < cards2[i]->value)
      {
         return -1;
      }
   }

   return 0;
}
