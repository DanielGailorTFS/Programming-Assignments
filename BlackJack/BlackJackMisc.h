#pragma once



//bet winnings
void betWinnings()
{
	winnings = currentBet * 2;
	playerMoney += winnings;
	cout << "Congratulations! You've won " << currentBet << " credits!" << endl;
	playAgain();
}

//Here, we allow the dealer to hit
void dealerTurn()
{
	//Displaying the dealer's hand and score, using recursion to hit if necessary
	cout << "Dealer's hand: " << endl;
	for (int i = 0; i < dealerHand.size(); i++)
	{
		cout << dealerHand[i] << endl;
		cout << " " << endl;
	}
	cout << "Dealer's score: " << getScore(dealerHand) << endl;
	//If the dealer has less than 17, they must hit, if they have over 17, they must stand. If they bust, the player wins. If they don't, we compare scores
	if (getScore(dealerHand) < 17)
	{
		cout << "Dealer hits." << endl;
		dealerHand.push_back(deck[0]);
		deck.erase(deck.begin());
		dealerTurn();
	}
	else if (getScore(dealerHand) > 21)
	{
		cout << "Dealer busted! You win!" << endl;
		betWinnings();
	}
	else
	{
		if (getScore(playerHand) > getScore(dealerHand))
		{
			cout << "You win!" << endl;
			betWinnings();
		}
		else if (getScore(playerHand) < getScore(dealerHand))
		{
			cout << "Dealer wins!" << endl;
			playAgain();
		}
		else
		{
			cout << "Push!" << endl;
			playAgain();
			playerMoney += currentBet;
		}
	}
}