#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
//==========================================================Unreal SPS======================================================================
using namespace std;
//==========================================================================================================================================
/*
 * Singletone
 */
class Game
{
	private:
		Game(){}
		static Game* instance;
		Game& operator =(Game&);
	public:
		static Game* Get () {
			if (!instance)
			instance = new Game ();
			return instance;
		}
		string allDoc, name;
		unsigned short figure, botFigure, newGamerForResults, newGamerForExit, draw, victory, defeat;
		bool difficulity, sex, startGame, winRate;
		void EnterName();
		void StartGame();
		void Choise();
		void ExitInMenu();
		void Statistic() const;
		void Exit();
		void OutputMove();
		int BotHard();
		int BotNormaly();
		int OldDraw();
		int OldVictory();
		int OldDefeat();
};
Game* Game::instance(0);
/*
 * Загрузка старой статистики ничейных партий
 */ 
int Game::OldDraw() 
{
	ifstream input("players.txt");
	while (input)
		getline(input, allDoc, '\0');	
	string numberDraw;
	int positionBeginDraw = allDoc.find(name) + name.size() + 1, positionEndDraw, thisNumber = 0;
	positionEndDraw = allDoc.find(' ', positionBeginDraw);
	numberDraw = allDoc.substr(positionBeginDraw, positionEndDraw - positionBeginDraw);
	thisNumber = atoi(numberDraw.c_str());
	cout << thisNumber;
	input.close();
	return thisNumber;
}
/*
 * Загрузка старой статистики выигрышных партий
 */
int Game::OldVictory() 
{
	ifstream input("players.txt");
	while (input)
		getline(input, allDoc, '\0');	
	string numberVictory;
	int positionBeginVictory = allDoc.find(name) + name.size() + 1, positionEndVictory, thisNumber = 0;
	positionBeginVictory = allDoc.find(' ', positionBeginVictory)+1;
	positionEndVictory = allDoc.find(' ', positionBeginVictory);
	numberVictory = allDoc.substr(positionBeginVictory, positionEndVictory - positionBeginVictory);
	thisNumber = atoi(numberVictory.c_str());
	cout << thisNumber;
	input.close();
	return thisNumber;
}
/*
 * Загрузка старой статистики проиграных партий
 */
int Game::OldDefeat() 
{
	ifstream input("players.txt");
	while (input)
		getline(input, allDoc, '\0');	
	string numberDefeat;
	int positionBeginDefeat = allDoc.find(name) + name.size() + 1, positionEndDefeat, thisNumber = 0;
	positionBeginDefeat = allDoc.find(' ', positionBeginDefeat)+1;
	positionBeginDefeat = allDoc.find(' ', positionBeginDefeat)+1;
	positionEndDefeat = allDoc.find(' ', positionBeginDefeat);
	numberDefeat = allDoc.substr(positionBeginDefeat, positionEndDefeat - positionBeginDefeat);
	thisNumber = atoi(numberDefeat.c_str());
	cout << thisNumber;
	input.close();
	return thisNumber;
}
/*
 * Регистрация
 */ 
void Game::EnterName()
{
	cout << "\nEnter the your name and choose sex\n";
	cin >> name >> sex;
	if (name.find(" ")+1) exit(0);
	ifstream input("players.txt");
	while (input)
		getline(input, allDoc, '\0');	
	if (!(allDoc.find(name)+1))
	{
		newGamerForResults = 1;
		newGamerForExit = 1;
		ofstream output("players.txt", ios::app);
		output << name << " ";
		output.close();
		draw = 0;
		victory = 0;
		defeat = 0;
		cout << "NE NASHEL NO DOBAVIL PROVERYAI";	
	}
	else 
	{
		newGamerForResults = 0;
		newGamerForExit = 0;
		cout << allDoc.find(name);
		cout << "CHISLO";
		draw = OldDraw();
		victory = OldVictory();
		defeat = OldDefeat();
	}
	input.close();
	startGame = true;
	winRate = false;
	figure = 0;
	botFigure = 0;
}
/*
 * Выбор сложности
 */ 
void Game::StartGame()
{
	cout << "\nSelect difficulity level";
	cin >> difficulity;
}
/*
 * Сценарий игры
 */
void Game::Choise()
{
	cout << "\nChoose your weapon!";
	cin >> figure;
	if (!(startGame))
	{
		if (difficulity) botFigure = BotHard();
		else botFigure = BotNormaly();
	}
	if ((startGame) && (sex))
	{
		startGame = false;
		botFigure = 3;
	}
	if ((startGame) && (!(sex)))
	{
		startGame = false;
		botFigure = BotNormaly();
	}
	if (rand() % 3 == 0)
	{
		botFigure = BotNormaly();
	}
	if((figure == 1) && (botFigure == 1))
    {
        cout << "\nDraw! \n\n AI : Stone\t\tYou : Stone" << endl; 
        draw++;
        winRate = true;
    }
    if((figure == 2) && (botFigure == 2))
    {
        cout << "\nDraw! \n\n AI : Scissors\t\tYou : Scissors" << endl;
        draw++;
        winRate = true;
    }
    if((figure == 3) && (botFigure == 3))
    {
        cout << "\nDraw! \n\n AI : Paper\t\tYou : Paper" << endl;
        draw++;
        winRate = true;
    }
    if((figure == 1) && (botFigure == 2))
    {
        cout << "\nYou won! \n\n AI : Scissors\t\tYou : Stone" << endl;
        victory++;
        winRate = false;
    }
    if((figure == 1) && (botFigure == 3))
    {
        cout << "\nYou lose! \n\n AI : Paper\t\tYou : Stone" << endl;
        defeat++;
        winRate = true;
    }
    if((figure == 2) && (botFigure == 1))
    {
        cout << "\nYou lose! \n\n AI : Stone\t\tYou : Scissors" << endl;
        defeat++;
        winRate = true;
    }
    if((figure == 2) && (botFigure == 3))
    {
        cout << "\nYou won! \n\n AI : Paper\t\tYou : Scissors" << endl;
        victory++;
        winRate = false;
    }
    if((figure == 3) && (botFigure == 1))
    {
        cout << "\nYou won! \n\n AI : Stone\t\tYou : Paper"<< endl;
        victory++;
        winRate = false;
    }
    if((figure == 3) && (botFigure == 2))
    {
        cout << "\nYou lose! \n\n AI : Scissors\t\tYou : Paper" << endl;
        defeat++;
        winRate = true;
    }
	OutputMove();
}
/*
 * Запоминание хода противника
 */ 
void Game::OutputMove()
{
	if (newGamerForResults)
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');
		int positionOutput = allDoc.find(name) + name.size() + 1;
		if (newGamerForResults == 2)
		{
			positionOutput = allDoc.find(' ', positionOutput);
		}
		stringstream out;
		if (winRate == false)
			if (newGamerForResults == 1) out << figure << "0" << " ";
			else out << figure << "0";
		else
			if (newGamerForResults == 1) out << figure << " ";
			else out << figure;
		string strFigure = out.str();
		allDoc.insert(positionOutput, strFigure);		
		ofstream output("players.txt");
		output << allDoc;
		output.close();
		input.close();
		newGamerForResults = 2;
	}
	else
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');
		int positionOutput = allDoc.find(name) + name.size() + 1;
		positionOutput = allDoc.find(' ', positionOutput)+1;
		positionOutput = allDoc.find(' ', positionOutput)+1;
		positionOutput = allDoc.find(' ', positionOutput)+1;
		positionOutput = allDoc.find(' ', positionOutput);
		stringstream out;
		if (!winRate)
			out << figure << "0";
		else
			out << figure;
		string strFigure = out.str();
		allDoc.insert(positionOutput, strFigure);		
		ofstream output("players.txt");
		output << allDoc;
		output.close();
		input.close();
	}
}

int Game::BotNormaly()
{
	return abs(rand() % 3+1);
}
/*
 * Логика ИИ
 */ 
int Game::BotHard()
{
	if ((figure == 1) && (botFigure == figure))
	{
		return 2;
	}
	if ((figure == 2) && (botFigure == figure))
	{
		return 3;
	}
	if ((figure == 3) && (botFigure == figure))
	{
		return 1;
	}
	if (winRate) //Бот выиграл
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');	
		string strMoves;
		int positionBeginMoves = allDoc.find(name) + name.size() + 1, positionEndMoves;
		positionBeginMoves = allDoc.find(' ', positionBeginMoves) + 1;
		positionBeginMoves = allDoc.find(' ', positionBeginMoves) + 1;
		positionBeginMoves = allDoc.find(' ', positionBeginMoves) + 1;
		positionEndMoves = allDoc.find(' ', positionBeginMoves);
		strMoves = allDoc.substr(positionBeginMoves, positionEndMoves - positionBeginMoves);
		int *moves = new int[strMoves.size()];
		int sizeOfMass = strMoves.size();
		for(int i = 0; i < sizeOfMass; ++i)
		{
			moves[i] = strMoves[i] - 48;
		}
		input.close();
		return moves[sizeOfMass-1];
	}
	else //Бот проиграл
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');	
		string strMoves;
		int positionBeginMoves = allDoc.find(name) + name.size() + 1, positionEndMoves;
		positionEndMoves = allDoc.find(' ', positionBeginMoves);
		strMoves = allDoc.substr(positionBeginMoves, positionEndMoves - positionBeginMoves);
		int *moves = new int[strMoves.size()];
		int sizeOfMass = strMoves.size();
		for(int i = 0; i < sizeOfMass; ++i)
		{
			moves[i] = strMoves[i] - 48;
		}
		input.close();
		for(int i = sizeOfMass-1; i >= 0; --i)
		{
			if ((moves[i-1] == 1) && (moves[i] == 0))
			{
				return 3;
			}
			if ((moves[i-1] == 2) && (moves[i] == 0))
			{
				return 1;
			}
			if ((moves[i-1] == 3) && (moves[i] == 0))
			{
				return 2;
			}
		}
	}
	return 0;
}

void Game::Statistic() const
{
	cout << "\nYour statistic:\nDraws = " << draw << "\nVictories = " << victory << "\nDefeats = " << defeat;
}

void Game::ExitInMenu()
{
	
}

void Game::Exit()
{
	if (newGamerForExit)
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');
		int positionOutput = allDoc.find(name) + name.size() + 1;
		stringstream outDraw, outVictory, outDefeat;
		outDefeat << defeat << " ";
		outVictory << victory << " ";
		outDraw << draw << " ";
		string strDraw = outDraw.str();
		string strVictory = outVictory.str();
		string strDefeat = outDefeat.str();
		allDoc.insert(positionOutput, strDefeat);
		allDoc.insert(positionOutput, strVictory);
		allDoc.insert(positionOutput, strDraw);		
		ofstream output("players.txt");
		output << allDoc;
		output.close();
		input.close();
	}
	else
	{
		ifstream input("players.txt");
		while (input)
			getline(input, allDoc, '\0');
		int positionOutputBegin = allDoc.find(name) + name.size() + 1, positionOutputEnd;
		positionOutputEnd = allDoc.find(' ', positionOutputBegin) + 1;
		positionOutputEnd = allDoc.find(' ', positionOutputEnd) + 1;
		positionOutputEnd = allDoc.find(' ', positionOutputEnd) + 1;
		allDoc.erase(positionOutputBegin, positionOutputEnd - positionOutputBegin);
		stringstream outDraw, outVictory, outDefeat;
		outDefeat << defeat << " ";
		outVictory << victory << " ";
		outDraw << draw << " ";
		string strDraw = outDraw.str();
		string strVictory = outVictory.str();
		string strDefeat = outDefeat.str();
		allDoc.insert(positionOutputBegin, strDefeat);
		allDoc.insert(positionOutputBegin, strVictory);
		allDoc.insert(positionOutputBegin, strDraw);		
		ofstream output("players.txt");
		output << allDoc;
		output.close();
		input.close();
	}
	exit(1);
}

int main()
{
	Game *game;
	game->StartGame();
	game->EnterName();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Choise();
	game->Exit();
	return 0;
}
