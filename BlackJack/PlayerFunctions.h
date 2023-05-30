#pragma once


//Here, we allow the player to hit
void hit()
{
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your score: " << getScore(playerHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "You busted! Dealer wins!" << endl;
		playAgain();
	}
	if (getScore(playerHand) == 21)
	{
		cout << "You have 21!" << endl;
		betWinnings();
	}
	else
	{
		cout << "Would you like to hit(H) again or stand(S)?" << endl;
		char choice;
		cin >> choice;
		if (choice == 'H' || choice == 'h')
		{
			hit();
		}
		if (choice == 'H' || choice == 'h')
		{
			dealerTurn();
		}
	}
}

//Player can double their bet and hit one more time
void doubleDown()
{
	while (currentBet > playerMoney)
	{
		cout << "You don't have that much money. Please enter a valid bet." << endl;
		placeBet();
	}
	playerMoney -= currentBet;
	currentBet *= 2;
}

//Player can choose to end their turn and let the dealer play
void stand()
{
	cout << "You stand." << endl;
	dealerTurn();
}

//player can choose to end the round
void pass()
{
	cout << "You pass. The Dealer wins!" << endl;
	playerMoney -= currentBet;
	playAgain();
}

//Here, we allow the player to hit their second hand
void hitSecond()
{
	playerSplitHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your second hand: " << endl;
	for (int i = 0; i < playerSplitHand.size(); i++)
	{
		cout << playerSplitHand[i] << endl;
	}
	cout << "Your second score: " << getScore(playerSplitHand) << endl;
	if (getScore(playerSplitHand) > 21)
	{
		cout << "Your second hand busted!" << endl;
	}
	else
	{
		char choice;
		cout << "Would you like to hit your second hand again? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitSecond();
		}
		else if (choice == 'N' || choice == 'n')
		{
			dealerTurn();
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			hitSecond();
		}
	}
}

//Here, we allow the player to hit their first hand
void hitFirst()
{
	playerHand.push_back(deck[0]);
	deck.erase(deck.begin());
	cout << "Your first hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your first score: " << getScore(playerHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "Your first hand busted!" << endl;
	}
	else
	{
		char choice;
		cout << "Would you like to hit your first hand again? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitFirst();
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "Would you like to hit your second hand? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				hitSecond();
			}
			else if (choice == 'N' || choice == 'n')
			{
				dealerTurn();
			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
				hitFirst();
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			hitFirst();
		}
	}
}

//Here, we allow the player to split a pair on the first turn
void split()
{
	//Adding the second card to the second hand.
	playerSplitHand.push_back(playerHand[1]);
	//Removing the second card from the first hand and adding it to the second hand.
	playerHand.erase(playerHand.begin() + 1);
	//Adding a card to the first player hand.
	playerHand.push_back(deck[0]);
	//Removing the card from the deck.
	deck.erase(deck.begin());
	//Adding a card to the second player hand.
	playerSplitHand.push_back(deck[0]);
	//Removing the card from the deck.
	deck.erase(deck.begin());
	//Displaying the hands and scores.
	cout << "Your first hand: " << endl;
	for (int i = 0; i < playerHand.size(); i++)
	{
		cout << playerHand[i] << endl;
	}
	cout << "Your first score: " << getScore(playerHand) << endl;
	cout << "Your second hand: " << endl;
	for (int i = 0; i < playerSplitHand.size(); i++)
	{
		cout << playerSplitHand[i] << endl;
	}
	cout << "Your second score: " << getScore(playerSplitHand) << endl;
	if (getScore(playerHand) > 21)
	{
		cout << "Your first hand busted!" << endl;

	}
	if (getScore(playerSplitHand) > 21)
	{
		cout << "Your second hand busted!" << endl;
	}
	if (getScore(playerHand) > 21 && getScore(playerSplitHand) > 21)
	{
		cout << "Both hands busted! Dealer wins!" << endl;
		playAgain();
	}
	else
	{
		char choice;
		cout << "Would you like to hit your first hand? (Y/N)" << endl;
		cin >> choice;
		if (choice == 'Y' || choice == 'y')
		{
			hitFirst();
		}
		else if (choice == 'N' || choice == 'n')
		{
			cout << "Would you like to hit your second hand? (Y/N)" << endl;
			cin >> choice;
			if (choice == 'Y' || choice == 'y')
			{
				hitSecond();
			}
			else if (choice == 'N' || choice == 'n')
			{
				dealerTurn();
			}
			else
			{
				cout << "Invalid choice. Try again." << endl;
				split();
			}
		}
		else
		{
			cout << "Invalid choice. Try again." << endl;
			split();
		}
	}
}

//This is the UI function for the player's turn
void playerTurnMenu()
{
	char choice;
	cout << "Would you like to hit, stand, double down or pass? (H/S/D/X)" << endl;
	cin >> choice;
	if (choice == 'H' || choice == 'h')
	{
		hit();
	}
	else if (choice == 'S' || choice == 's')
	{
		stand();
	}
	else if (choice == 'D' || choice == 'd')
	{
		doubleDown();
	}
	else if (choice == 'X' || choice == 'x')
	{
		pass();
	}
	else
	{
		cout << "Invalid choice. Try again." << endl;
		playerTurnMenu();
	}
}

//place bet function
void placeBet()
{
	cout << "You have $" << playerMoney << ". How much would you like to bet?" << endl;
	cin >> currentBet;
	while (currentBet > playerMoney)
	{
		cout << "You don't have that much money. Please enter a valid bet." << endl;
		cin >> currentBet;
	}
	playerMoney -= currentBet;
	cout << "You have bet $" << currentBet << ".  $" << playerMoney << " remaining." << endl;

	dealCards();
}