#include <iostream>
#include <ctime>
#include <random>
int main()
{	
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<int> dist(0, 100);
		int randomNumber = dist(gen);
		int Guess=0;
		std::cout << "Guess a number between 1 and 100!\n";
		std::cin >> Guess;
		while (Guess != randomNumber) {
			if (randomNumber - Guess >= 0) {
				std::cout << "Your Guess is too low! Guess again!\n";
			}else if (randomNumber - Guess <= 0) {
				std::cout << "Your Guess is too high! Guess again!\n";
			}
			if (abs(randomNumber - Guess) <=10) {
				std::cout << "You are so close!\n";
			}else if (abs(randomNumber - Guess) <= 50&& abs(randomNumber - Guess)>30) {
				std::cout << "You are getting closer!\n";
			}else if (abs(randomNumber - Guess) > 10&& abs(randomNumber-Guess)<=30) {
				std::cout << "You are getting even more closer!\n";
			}
			std::cin >> Guess;
		 }
		std::cout << "Congratulations!!!! You guessed the Number!!"<<" The Number was: "<<randomNumber<<"\n";
}

