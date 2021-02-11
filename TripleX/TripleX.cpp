#include <Iostream> 
#include <ctime>

void Printintroduction(int Difficulty)
{
	std::cout << "you are a secret agent breaking into a level " << Difficulty;
	std::cout << " secure server room. . . \nenter the correct codes to continue!\n\n" ;
}
bool PlayGame(int Difficulty)
{
	Printintroduction(Difficulty);

	


		// Declares 3 bumber code
		const int CodeA = rand() % Difficulty + Difficulty;
		const int CodeB = rand() % Difficulty + Difficulty;
		const int CodeC = rand() % Difficulty + Difficulty;

		const int CodeSum = CodeA + CodeB + CodeC;
		const int CodeProduct = CodeA * CodeB * CodeC;

		std::cout << std::endl;
		std::cout << "+ there are 3 numbers in the code";
		std::cout << "\n+ the codes add up to : " << CodeSum;
		std::cout << "\n+ the codes multiply to : " << CodeProduct << std::endl;

		int GuessA, GuessB, GuessC;
		std::cin >> GuessA;
		std::cin >> GuessB;
		std::cin >> GuessC;

		int GuessSum = GuessA + GuessB + GuessC;
		int GuessProduct = GuessA * GuessB * GuessC;

		if (GuessSum == CodeSum && GuessProduct == CodeProduct)
		{
			std::cout << "*** Well done, onto the next level! ***";
			return true;
		}
		else
		{
			std::cout << "*** You entered the wrong code! Try again! ***";
			return false;
		}



}
int main()
{
	srand(time(NULL)); // Creatine seed based on comp clock

	int LevelDifficulty = 1;
	const int MaxDifficulty = 5;

	while (LevelDifficulty <= MaxDifficulty) // loops game until completed
	{
		bool bLevelComplete = PlayGame(LevelDifficulty);
		
		std::cin.clear(); // Clears any errors
		std::cin.ignore(); // Discards the buffer

		if (bLevelComplete)
		{
			++LevelDifficulty;
		}
	}
	std::cout << "\n*** GREAT WORK! You got all the files! now scram! ***\n";
	return 0;
}