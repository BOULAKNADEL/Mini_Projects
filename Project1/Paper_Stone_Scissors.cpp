#include <iostream>
#include <cstdlib>
using namespace std;

enum enWinner
{
	Player = 1,
	Computer = 2,
	Draw = 3
};

enum enChoice
{
	Stone = 1,
	Paper = 2,
	Scissors = 3
};

struct stRoundInfo
{
	short Round_Number = 0;
	enChoice Player_Choice;
	enChoice Computer_Choice;
	enWinner Round_Winner;
	string Round_Winner_Name;
};

struct stGameResult
{
	short Number_Of_Rounds_Played = 0;
	short Player_Score = 0;
	short Computer_Score = 0;
	short Draw_Number = 0;
	enWinner Game_Winner;
	string Game_Winner_Name;
};

int Random_Number(int From, int To)
{
	int RandNum = rand() % (To - From + 1) + From;
	return (RandNum);
}

enChoice Read_Player_Choice()
{
	short Choice;

	do
	{
		cout << "\nYour Choice : \n";
		cout << "1) Stone\n";
		cout << "2) Paper\n";
		cout << "3) Scissors\n\n";
		cin >> Choice;
	} while (Choice < 1 || Choice > 3);

	return ((enChoice)Choice);
}

enChoice Get_Computer_Choice()
{
	return ((enChoice) Random_Number(1, 3));
}

enWinner Winner_Of_The_Round(stRoundInfo RoundInfo)
{
	if (RoundInfo.Computer_Choice == RoundInfo.Player_Choice)
	{
		return (enWinner::Draw);
	}

	switch (RoundInfo.Player_Choice)
	{
	case enChoice::Paper:
		
		if (RoundInfo.Computer_Choice == enChoice::Scissors)
		{
			return (enWinner::Computer);
		}
		break;

	case enChoice::Scissors:

		if (RoundInfo.Computer_Choice == enChoice::Stone)
		{
			return (enWinner::Computer);
		}
		break;

	case enChoice::Stone:

		if (RoundInfo.Computer_Choice == enChoice::Paper)
		{
			return (enWinner::Computer);
		}
		break;
	}

	return (enWinner::Player);
}

string Winner_Name(enWinner Winner)
{
	string arrWinnerName[3] = { "Player", "Computer", "Draw" };

	return (arrWinnerName[Winner - 1]);
}

void Screen_Color(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player:
		system("color 2F"); //Green
		break;

	case enWinner::Computer:
		system("color 4F"); //Red
		break;

	case enWinner::Draw:
		system("color 2F");
		break;
	}
}

string Choice_Name(enChoice Choice)
{
	string arrChoice[3] = { "Stone", "Paper", "Scissors" };

	return (arrChoice[Choice - 1]);
}

void Print_Round_Result(stRoundInfo RoundInfo)
{
	cout << "\n\n-----------------------Round[" << RoundInfo.Round_Number << "]---------------------------\n\n";
	cout << "Player Choice     :   " << Choice_Name(RoundInfo.Player_Choice) << endl;
	cout << "Computer Choice   :   " << Choice_Name(RoundInfo.Computer_Choice) << endl;
	cout << "Round Winner      :   " << Winner_Name(RoundInfo.Round_Winner) << endl;
	cout << "\n-----------------------------------------------------------\n";

	Screen_Color(RoundInfo.Round_Winner);
}

enWinner Final_Winner(short Player_Score, short Computer_Score)
{
	if (Player_Score > Computer_Score)
	{
		return (enWinner::Player);
	}
	else if (Player_Score < Computer_Score)
	{
		return (enWinner::Computer);
	}
	else
	{
		return (enWinner::Draw);
	}
}

stGameResult Fill_Game_Result(short NumberOfRoundPlayed, short PlayerScore, short ComputerScore, short DrawTimes)
{
	stGameResult GameResult;

	GameResult.Number_Of_Rounds_Played = NumberOfRoundPlayed;
	GameResult.Player_Score = PlayerScore;
	GameResult.Computer_Score = ComputerScore;
	GameResult.Draw_Number = DrawTimes;
	GameResult.Game_Winner = Final_Winner(PlayerScore, ComputerScore);

	return (GameResult);
}

short Read_Round_Number()
{
	short Round;

	do
	{
		cout << "How Many Round Do You Want To Play ? \n";
		cin >> Round;
	} while (Round < 1 || Round > 10);

	return (Round);
}

stGameResult Play_Game(short HowManyRound)
{
	stRoundInfo RoundInfo;
	short Player_score = 0, Computer_Score = 0, Draw_Number = 0;

	for (short GameRound = 1; GameRound <= HowManyRound; GameRound++)
	{
		cout << "Round [" << GameRound << "] begins : \n";
		RoundInfo.Round_Number = GameRound;
		RoundInfo.Player_Choice = Read_Player_Choice();
		RoundInfo.Computer_Choice = Get_Computer_Choice();
		RoundInfo.Round_Winner = Winner_Of_The_Round(RoundInfo);
		RoundInfo.Round_Winner_Name = Winner_Name(RoundInfo.Round_Winner);

		if (RoundInfo.Round_Winner == enWinner::Player)
		{
			Player_score++;
		}
		else if (RoundInfo.Round_Winner == enWinner::Computer)
		{
			Computer_Score++;
		}
		else
		{
			Draw_Number++;
		}

		Print_Round_Result(RoundInfo);
	}

	return (Fill_Game_Result(HowManyRound, Player_score, Computer_Score, Draw_Number));
}

string Tabs(short HowManyTab)
{
	string t = "";

	for (int i = 1; i <= HowManyTab; i++)
	{
		t += "\t";
		cout << t;
	}

	return (t);
}

void Print_Result(stGameResult GameResults)
{
	cout << "\n\n";
	cout << Tabs(2) << "------------------[F I N A L   R E S U L T]---------------\n";
	cout << Tabs(2) << "Game Rounds: " << GameResults.Number_Of_Rounds_Played << endl;
	cout << Tabs(2) << "Player Score: " << GameResults.Player_Score << endl;
	cout << Tabs(2) << "Computer Score: " << GameResults.Computer_Score << endl;
	cout << Tabs(2) << "Draw Times: " << GameResults.Draw_Number << endl;
	cout << Tabs(2) << "Final Winner: " << Winner_Name(GameResults.Game_Winner) << "\n";
	cout << Tabs(2) << "-------------------------------------------------------------\n";

	Screen_Color(GameResults.Game_Winner);
}

void Print_Game_Over()
{
	cout << "\n\n";
	cout << Tabs(2) << "-------------------------------------------------------------\n";
	cout << Tabs(2) << "                       +++G A M E   O V E R+++                     \n";
	cout << Tabs(2) << "-------------------------------------------------------------\n\n";
}

void Reset_Screen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain = 'Y';

	do
	{
		Reset_Screen();
		stGameResult GameResult = Play_Game(Read_Round_Number());
		Print_Game_Over();
		Print_Result(GameResult);

		cout << endl << Tabs(2) << "Do you want to play again? Y/N? \n";
		cin >> PlayAgain;
	} while (PlayAgain == 'Y' || PlayAgain == 'y');
}

int main(void)
{
	srand((unsigned)time(NULL));

	StartGame();

	return (0);
}
