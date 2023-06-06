#!/usr/bin/python

# In the card game poker, a hand consists of five cards and are ranked, from lowest to highest, in the following way:
#
# High Card: Highest value card.
# One Pair: Two cards of the same value.
# Two Pairs: Two different pairs.
# Three of a Kind: Three cards of the same value.
# Straight: All cards are consecutive values.
# Flush: All cards of the same suit.
# Full House: Three of a kind and a pair.
# Four of a Kind: Four cards of the same value.
# Straight Flush: All cards are consecutive values of same suit.
# Royal Flush: Ten, Jack, Queen, King, Ace, in same suit.
# The cards are valued in the order:
# 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace.
#
# If two players have the same ranked hands then the rank made up of the highest value wins; for example, a pair of eights beats a pair of fives 
# (see example 1 below). But if two ranks tie, for example, both players have a pair of queens, then highest cards in each hand are compared
# (see example 4 below); if the highest cards tie then the next highest cards are compared, and so on.
#
# Consider the following five hands dealt to two players:
#
# Hand	 	Player 1	 	      Player 2	 	      Winner
#  1	 	5H 5C 6S 7S KD    2C 3S 8S 8D TD        Player 2
#                Pair of Fives     Pair of Eights
#
#  2	 	5D 8C 9S JS AC    2C 5C 7D 8S QH        Player 1
#      Highest card Ace   Highest card Queen
#
#  3	 	2D 9C AS AH AC    3D 6D 7D TD QD        Player 2
#        Three Aces      Flush with Diamonds
#
#  4	 	4D 6S 9H QH QC    3D 6D 7H QD QS        Player 1
#       Pair of Queens    Pair of Queens
#      Highest card Nine Highest card Seven
#
#  5	 	2H 2D 4C 4D 4S    3C 3D 3S 9S 9D        Player 1
#         Full House  	    Full House
#      With Three Fours  With Three Threes
#
#      The file, poker.txt, contains one-thousand random hands dealt to two players. Each line of the file contains ten cards
#      (separated by a single space): the first five are Player 1's cards and the last five are Player 2's cards.
#      You can assume that all hands are valid (no invalid characters or repeated cards), each player's hand is in no specific order,
#      and in each hand there is a clear winner.
#
#      How many hands does Player 1 win?

import sys
from enum import IntEnum
from timeit import default_timer


class Value(IntEnum):
    Two = 1
    Three = 2
    Four = 3
    Five = 4
    Six = 5
    Seven = 6
    Eight = 7
    Nine = 8
    Ten = 9
    Jack = 10
    Queen = 11
    King = 12
    Ace = 13


class Card():

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.value = None
        self.suit = None

    def set_card(self, card):
        if card[0] == '2':
            self.value = Value.Two
        elif card[0] == '3':
            self.value = Value.Three
        elif card[0] == '4':
            self.value = Value.Four
        elif card[0] == '5':
            self.value = Value.Five
        elif card[0] == '6':
            self.value = Value.Six
        elif card[0] == '7':
            self.value = Value.Seven
        elif card[0] == '8':
            self.value = Value.Eight
        elif card[0] == '9':
            self.value = Value.Nine
        elif card[0] == 'T':
            self.value = Value.Ten
        elif card[0] == 'J':
            self.value = Value.Jack
        elif card[0] == 'Q':
            self.value = Value.Queen
        elif card[0] == 'K':
            self.value = Value.King
        elif card[0] == 'A':
            self.value = Value.Ace

        self.suit = card[1]


class Hand():

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.cards = list()

    def sort(self):
        self.cards.sort(key=lambda x: x.value)


class Game():

    def __init__(self, *args, **kwargs):
        super().__init__(*args, **kwargs)

        self.hand1 = None
        self.hand2 = None

    def play(self):

#       If player 1 has a Royal Flush, player 1 wins.
        if self.hand1.cards[4].value == Value.Ace and self.hand1.cards[3].value == Value.King and\
                self.hand1.cards[2].value == Value.Queen and self.hand1.cards[1].value == Value.Jack and\
                self.hand1.cards[0] == Value.Ten and self.hand1.cards[0].suit == self.hand1.cards[1].suit and\
                self.hand1.cards[0].suit == self.hand1.cards[2].suit and\
                self.hand1.cards[0].suit == self.hand1.cards[3].suit and\
                self.hand1.cards[0].suit == self.hand1.cards[4].suit:
            return 1

#       If player 2 has a Royal Flush, player 2 wins.
        if self.hand2.cards[4].value == Value.Ace and self.hand2.cards[3].value == Value.King and\
                self.hand2.cards[2].value == Value.Queen and self.hand2.cards[1].value == Value.Jack and\
                self.hand2.cards[0] == Value.Ten and self.hand2.cards[0].suit == self.hand2.cards[1].suit and\
                self.hand2.cards[0].suit == self.hand2.cards[2].suit and\
                self.hand2.cards[0].suit == self.hand2.cards[3].suit and\
                self.hand2.cards[0].suit == self.hand2.cards[4].suit:
            return -1

        straightflush1 = 0
        straightflush2 = 0

#       Check if player 1 has a straight flush.
        if self.hand1.cards[0].suit == self.hand1.cards[1].suit and self.hand1.cards[0].suit == self.hand1.cards[2].suit and\
                self.hand1.cards[0].suit == self.hand1.cards[3].suit and self.hand1.cards[0].suit == self.hand1.cards[4].suit:
            value = self.hand1.cards[0].value

            straightflush1 = 1

            for i in range(1, 5):
                value = value + 1

                if self.hand1.cards[i].value != value:
                    straightflush1 = 0
                    break

#       Check if player 2 has a straight flush.
        if self.hand2.cards[0].suit == self.hand2.cards[1].suit and self.hand2.cards[0].suit == self.hand2.cards[2].suit and\
                self.hand2.cards[0].suit == self.hand2.cards[3].suit and self.hand2.cards[0].suit == self.hand2.cards[4].suit:
            value = self.hand2.cards[0].value

            straightflush2 = 1

            for i in range(1, 5):
                value = value + 1

                if self.hand2.cards[i].value != value:
                    straightflush2 = 0
                    break

#       If player 1 has a straight flush and player 2 doesn't, player 1 wins
        if straightflush1 and not straightflush2:
            return 1

#       If player 2 has a straight flush and player 1 doesn't, player 2 wins
        if not straightflush1 and straightflush2:
            return -1

#       If both players have a straight flush, the one with the highest value wins.
#       Any card can be compared, because in the straight flush the values are consecutive
#       by definition.
        if straightflush1 and straightflush2:
            if self.hand1.cards[0].value > self.hand2.cards[0].value:
                return 1

            return -1

        four1 = 0
        four2 = 0

#       Check if player 1 has four of a kind. Since cards are ordered, it is sufficient
#       to check if the first card is equal to the fourth or if the second is equal to the fifth.
        if self.hand1.cards[0].value == self.hand1.cards[3].value or self.hand1.cards[1].value == self.hand1.cards[4].value:
            four1 = 1

#       Check if player 2 has four of a kind
        if self.hand2.cards[0].value == self.hand2.cards[3].value or self.hand2.cards[1].value == self.hand2.cards[4].value:
            four2 = 1

#       If player 1 has four of a kind and player 2 doesn't, player 1 wins.
        if four1 and not four2:
            return 1

#       If player 2 has four of a kind and player 1 doesn't, player 2 wins.
        if not four1 and four2:
            return -1

#       If both players have four of a kind, check who has the highest value for those four cards.
        if four1 and four2:
            if self.hand1.cards[1].value > self.hand2.cards[1].value:
                return 1
            if self.hand1.cards[1].value < self.hand2.cards[1].value:
                return -1

        full1 = 0
        full2 = 0

#       Check if player 1 has a full house.
        if self.hand1.cards[0].value == self.hand1.cards[1].value and self.hand1.cards[3].value == self.hand1.cards[4].value and\
                (self.hand1.cards[1].value == self.hand1.cards[2].value or self.hand1.cards[2].value == self.hand1.cards[3].value):
            full1 = 1

#       Check if player 2 has a full house.
        if self.hand2.cards[0].value == self.hand2.cards[1].value and self.hand2.cards[3].value == self.hand2.cards[4].value and\
                (self.hand2.cards[1].value == self.hand2.cards[2].value or self.hand2.cards[2].value == self.hand2.cards[3].value):
            full2 = 1

#       If player 1 has a full house and player 2 doesn't, player 1 wins.
        if full1 and not full2:
            return 1

#       If player 2 has a full house and player 1 doesn't, player 2 wins.
        if not full1 and full2:
            return -1

#       If both players have a full house, check who has the highest value
#       for the three equal cards (the third card in the array will be part
#       of the set of three).
        if full1 and full2:
            if self.hand1.cards[2].value > self.hand2.cards[2].value:
                return 1

            if self.hand1.cards[2].value < self.hand2.cards[2].value:
                return -1

        flush1 = 0
        flush2 = 0

#       Check if player 1 has a flush.
        if self.hand1.cards[0].suit == self.hand1.cards[1].suit and self.hand1.cards[0].suit == self.hand1.cards[2].suit and\
                self.hand1.cards[0].suit == self.hand1.cards[3].suit and self.hand1.cards[0].suit == self.hand1.cards[4].suit:
            flush1 = 1

#       Check if player 2 has a flush.
        if self.hand2.cards[0].suit == self.hand2.cards[1].suit and self.hand2.cards[0].suit == self.hand2.cards[2].suit and\
                self.hand2.cards[0].suit == self.hand2.cards[3].suit and self.hand2.cards[0].suit == self.hand2.cards[4].suit:
            flush2 = 1

#       If player 1 has a flush and player 2 doesn't, player 1 wins.
        if flush1 and not flush2:
            return 1

#       If player 2 has a flush and player 1 doesn't, player 2 wins.
        if not flush1 and flush2:
            return -1

        straight1 = 1
        straight2 = 1

#       Check if player 1 has a straight.
        value = self.hand1.cards[0].value

        for i in range(1, 5):
            value = value + 1

            if self.hand1.cards[i].value != value:
                straight1 = 0
                break

#       Check if player 2 has a straight.
        value = self.hand2.cards[0].value

        for i in range(1, 5):
            value = value + 1

            if self.hand2.cards[i].value != value:
                straight2 = 0
                break

#       If player 1 has a straight and player 2 doesn't, player 1 wins.
        if straight1 and not straight2:
            return 1

#       If player 2 has a straight and player 1 doesn't, player 2 wins.
        if not straight1 and straight2:
            return -1

        three1 = 0
        three2 = 0

#       Check if player 1 has three of a kind.
        if (self.hand1.cards[0].value == self.hand1.cards[1].value and self.hand1.cards[0].value == self.hand1.cards[2].value) or\
                (self.hand1.cards[1].value == self.hand1.cards[2].value and self.hand1.cards[1].value == self.hand1.cards[3].value) or\
                (self.hand1.cards[2].value == self.hand1.cards[3].value and self.hand1.cards[2].value == self.hand1.cards[4].value):
            three1 = 1

#       Check if player 2 has three of a kind.
        if (self.hand2.cards[0].value == self.hand2.cards[1].value and self.hand2.cards[0].value == self.hand2.cards[2].value) or\
                (self.hand2.cards[1].value == self.hand2.cards[2].value and self.hand2.cards[1].value == self.hand2.cards[3].value) or\
                (self.hand2.cards[2].value == self.hand2.cards[3].value and self.hand2.cards[2].value == self.hand2.cards[4].value):
            three2 = 1

#       If player 1 has three of a kind and player 2 doesn't, player 1 wins.
        if three1 and not three2:
            return 1

#       If player 2 has three of a kind and player 1 doesn't, player 2 wins.
        if not three1 and three2:
            return -1

        if three1 and three2:
            if self.hand1.cards[2].value > self.hand2.cards[2].value:
                return 1

            if self.hand1.cards[2].value < self.hand2.cards[2].value:
                return -1

        twopairs1 = 0
        twopairs2 = 0

#       Check if player 1 has two pairs.
        if (self.hand1.cards[0].value == self.hand1.cards[1].value and self.hand1.cards[2].value == self.hand1.cards[3].value) or\
                (self.hand1.cards[0].value == self.hand1.cards[1].value and self.hand1.cards[3].value == self.hand1.cards[4].value) or\
                (self.hand1.cards[1].value == self.hand1.cards[2].value and self.hand1.cards[3].value == self.hand1.cards[4].value):
            twopairs1 = 1

#       Check if player 2 has two pairs.
        if (self.hand2.cards[0].value == self.hand2.cards[1].value and self.hand2.cards[2].value == self.hand2.cards[3].value) or\
                (self.hand2.cards[0].value == self.hand2.cards[1].value and self.hand2.cards[3].value == self.hand2.cards[4].value) or\
                (self.hand2.cards[1].value == self.hand2.cards[2].value and self.hand2.cards[3].value == self.hand2.cards[4].value):
            twopairs2 = 1

#       If player 1 has two pairs and player 2 doesn't, player 1 wins.
        if twopairs1 and not twopairs2:
            return 1

#       If player 2 has two pairs and player 1 doesn't, player 2 wins.
        if not twopairs1 and twopairs2:
            return -1

#       If both players have two pairs, check who has the highest pair. If it's equal,
#       check the other pair. If it's still equal, check the remaining card.
        if twopairs1 and twopairs2:
            if self.hand1.cards[3].value > self.hand2.cards[3].value:
                return 1

            if self.hand1.cards[3].value < self.hand2.cards[3].value:
                return -1

            if self.hand1.cards[1].value > self.hand2.cards[1].value:
                return 1

            if self.hand1.cards[1].value < self.hand2.cards[1].value:
                return -1

            for i in range(4, -1, -1):
                if self.hand1.cards[i].value > self.hand2.cards[i].value:
                    return 1

                if self.hand1.cards[i].value < self.hand2.cards[i].value:
                    return -1

        pair1 = 0
        pair2 = 0

#       Check if player 1 has a pair of cards.
        if self.hand1.cards[0].value == self.hand1.cards[1].value or self.hand1.cards[1].value == self.hand1.cards[2].value or\
                self.hand1.cards[2].value == self.hand1.cards[3].value or self.hand1.cards[3].value == self.hand1.cards[4].value:
            pair1 = 1

#       Check if player 2 has a pair of cards.
        if self.hand2.cards[0].value == self.hand2.cards[1].value or self.hand2.cards[1].value == self.hand2.cards[2].value or\
                self.hand2.cards[2].value == self.hand2.cards[3].value or self.hand2.cards[3].value == self.hand2.cards[4].value:
            pair2 = 1

#       If player 1 has a pair of cards and player 2 doesn't, player 1 wins.
        if pair1 and not pair2:
            return 1

#       If player 2 has a pair of cards and player 1 doesn't, player 2 wins.
        if not pair1 and pair2:
            return -1

#       If both players have a pair of cards, check who has the highest pair. Since cards are
#       ordered by value, either card[1] will be part of the pair (card[0]=card[1] or
#       card[1]=card[2]) or card[3] will be part of the pair (card[2]=card[3] or
#       card[3]=card[4]).
        if pair1 and pair2:
            if self.hand1.cards[0].value == self.hand1.cards[1].value or self.hand1.cards[1].value == self.hand1.cards[2].value:
                value = self.hand1.cards[1].value

                if self.hand2.cards[0].value == self.hand2.cards[1].value or self.hand2.cards[1].value == self.hand2.cards[2].value:
                    if value > self.hand2.cards[1].value:
                        return 1
                    if value < self.hand2.cards[1].value:
                        return -1

                if self.hand2.cards[2].value == self.hand2.cards[3].value or self.hand2.cards[3].value == self.hand2.cards[4].value:
                    if value > self.hand2.cards[3].value:
                        return 1
                    if value < self.hand2.cards[3].value:
                        return -1
            else:
                value = self.hand1.cards[3].value

                if self.hand2.cards[0].value == self.hand2.cards[1].value or self.hand2.cards[1].value == self.hand2.cards[2].value:
                    if value > self.hand2.cards[1].value:
                        return 1
                    if value < self.hand2.cards[1].value:
                        return -1
                elif self.hand2.cards[2].value == self.hand2.cards[3].value or self.hand2.cards[3].value == self.hand2.cards[4].value:
                    if value > self.hand2.cards[3].value:
                        return 1
                    if value < self.hand2.cards[3].value:
                        return -1

#       If all other things are equal, check who has the highest card, if it's equal check the second highest and so on.
        for i in range(4, -1, -1):
            if self.hand1.cards[i].value > self.hand2.cards[i].value:
                return 1
            if self.hand1.cards[i].value < self.hand2.cards[i].value:
                return -1

#       If everything is equal, return 0
        return 0


def main():
    start = default_timer()

    try:
        with open('poker.txt', 'r', encoding='utf-8') as fp:
            games = fp.readlines()
    except FileNotFoundError:
        print('Error while opening file poker.txt')
        sys.exit(1)

    count = 0

    for i in games:
        line = ''.join(i).strip().split(' ')

        count_hand = 0
        hand1 = Hand()
        hand2 = Hand()

        for j in line:
            card = Card()
            card.set_card(j)

            if count_hand < 5:
                hand1.cards.append(card)
            else:
                hand2.cards.append(card)

            count_hand = count_hand + 1

        hand1.sort()
        hand2.sort()

        for k in hand1.cards:
            game = Game()
            game.hand1 = hand1
            game.hand2 = hand2

        if game.play() == 1:
            count = count + 1

    end = default_timer()

    print('Project Euler, Problem 54')
    print(f'Answer: {count}')

    print(f'Elapsed time: {end - start:.9f} seconds')


if __name__ == '__main__':
    main()
