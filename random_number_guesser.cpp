/********* NUMBER 
				GUESSING 
						GAME */
						
#include <cstdlib> 
#include <iostream> 
#include<ctime>
using namespace std; 

int main() 
{ 
	 	//creating random number (0 to 1000)
		srand((unsigned) time(NULL));
        int random = rand()%1000; 
	 	
		//guess variable	
		int guess;
	 
	 	//initializing found as 0(false)
		int found = 0; 

		//Getting input from user (guess value)
		cout<<"Enter the value of your guess (0 to 1000): ";
		cin>>guess;

		//loop guides and runs until user find the random number
		while(found!=1){
		
		//Checking the guessed value with random no. and break in case of a match
		if(random==guess){
			cout << "You got it :)" <<endl; 
			cout<<"The random number is "<<random;
			found=1;
			break;
		}

		//guessed value more than random value
		else if(guess>random)
		cout<< "still lesser";

		//guessed value lesser than random value
		else
		cout<< "still  more";

		//getting the guess value again from user in case of wrong guess value
		cout<<"\nguess again the random number: ";
		cin>>guess;
		}
		
	return 0; 
}
