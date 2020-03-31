#pragma once
#include "pch.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <Windows.h>

using namespace std;

class Card {
public:
	int color; // 1-heart 2-spade 3-club 4-diamond
	int value;
};

struct chosenCard {
		chosenCard * next;
		Card CantBeUsed;
};


	
Card AssignCard(chosenCard* &head);
void addToGoodCard(chosenCard* &head, Card goodCard);
bool isCardUnique(chosenCard* &head, Card randomized);
Card RandomizeCard();
string ColorChanger(int color);
string ValueChanger(int value);
int MakingDecision(int ComputerBet);
void LogMoneyState(int PlayerMoney, int ComputerMoney, int pot);
void LogHand(Card PlayerCard1, Card PlayerCard2);
int Turn(int &pot, int decision, int &PlayerMoney, bool &turn);
void Call(int Equalizer, int &pot, int &PlayerMoney);
int ComputerTurn(int &pot, int &ComputerMoney, bool &turn, Card CompCard1, Card CompCard2, int round, int PlayerBet);
void ConsoleColorChanger(string color);
void PrintRound(int round);




