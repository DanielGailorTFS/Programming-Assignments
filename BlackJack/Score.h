#pragma once



//Here, we keep track of the score, checking the hand vector for strings that contain the rank of the card, and then adding the appropriate value to the score.
int getScore(vector<string> hand)
{
	int score = 0;
	for (int i = 0; i < hand.size(); i++)
	{
		if (hand[i].find("Two") != string::npos)
		{
			score += 2;
		}
		else if (hand[i].find("Three") != string::npos)
		{
			score += 3;
		}
		else if (hand[i].find("Four") != string::npos)
		{
			score += 4;
		}
		else if (hand[i].find("Five") != string::npos)
		{
			score += 5;
		}
		else if (hand[i].find("Six") != string::npos)
		{
			score += 6;
		}
		else if (hand[i].find("Seven") != string::npos)
		{
			score += 7;
		}
		else if (hand[i].find("Eight") != string::npos)
		{
			score += 8;
		}
		else if (hand[i].find("Nine") != string::npos)
		{
			score += 9;
		}
		else if (hand[i].find("Ten") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Jack") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Queen") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("King") != string::npos)
		{
			score += 10;
		}
		else if (hand[i].find("Ace") != string::npos)
		{
			//If the score is over 21, we want the Ace to be worth 1 instead of 11.
			score += 11;
			if (score > 21)
			{
				score -= 10;
			}
		}

	}
	return score;
}

//Here, we check for a winner by comparing the scores of the player and the dealer against the value of 21 and then against eachother.
void checkWinner()
{
	int playerScore = getScore(playerHand);
	int dealerScore = getScore(dealerHand);
	if (playerScore > 21)
	{
		cout << "You busted! Dealer wins!" << endl;
	}
	else if (dealerScore > 21)
	{
		cout << "Dealer busted! You win!" << endl;
	}
	else if (playerScore > dealerScore)
	{
		cout << "You win!" << endl;
	}
	else if (dealerScore > playerScore)
	{
		cout << "Dealer wins!" << endl;
	}
	else if (dealerScore == playerScore)
	{
		cout << "It's a tie!" << endl;
	}
}