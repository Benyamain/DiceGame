/* Benyamain Yacoob
Intro to Programming I
10-21-21
Project #1 */

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <random>

using namespace std;

int main()
{
    // Declaration of variables
    const double START_CRED = 500;
    double wage, credNew;
    int dice1, dice2;
    srand (time(NULL)); // To set a different seed of random #'s
    char ans;
   
    // Display Message; OUTPUT
    cout << "Welcome! We are going to play Double Roll.\n";
    cout << "You have a starting credit of $500\nHow much of it do you want to wager?: $";
    cin >> wage;    // INPUT
    
    // PROCESS
    if (wage > START_CRED)  // User is limited to wage a maximum of $500.00
        cout << "ERROR: You cannot wage more than your starting credit.\n";
    else if (wage < 0)  // Starts with a positive balance
        cout << "ERROR: You cannot have a negative wage.\n";
    else if (wage == 0)
        cout << "ERROR: You cannot wage nothing.\n";
    else
    {
        // Modulus remainder formula for max dice value
        dice1 = rand() % 6 + 1;
        dice2 = rand() % 6 + 1;
        
        cout << "Dice #1: " << dice1 << "\t" << "Dice #2: " << dice2 << endl;
        
        if (dice1 == dice2) // Fair dices landing on the same face value
        {
            credNew = START_CRED + wage;   // Formula for wage sum
                
            cout << "Your new balance is $" << credNew << endl;    
        }
        else
        {
            credNew = START_CRED - wage;   // Formula for wage difference
            
            cout << "Your new balance is $" << credNew << endl;
        }
        
        cout << "Do you want to continue (Y/N)?: ";
        cin >> ans;
        
        ans = toupper(ans); // Data type prioritizes the letter to uppercase

	    // LOOP
	    while (ans != 'Y' && ans != 'N')    // User receives error message if not y/n or Y/N
	    {
	        cout << "ERROR: Invalid input.\n";
		    cout << "Please type (Y/N): ";
		    cin >> ans;
		    
		    ans = toupper(ans);
	    }
	    
	    // LOOP
        while (ans == 'Y' && credNew > 0)   // Continues the game if user says yes
        {
            cout << "How much of $" << credNew << " do you want to wager?: $";
            cin >> wage;
            
            // PROCESS
            if (wage > credNew)  // User is limited to wage up to their current balance
                cout << "ERROR: You cannot wage more than your current credit.\n";
            else if (wage < 0)  // Starts with a positive balance
                cout << "ERROR: You cannot have a negative wage.\n";
            else if (wage == 0)
                cout << "ERROR: You cannot wage nothing.\n";
            else
            {
                // Modulus remainder formula for max dice value
                dice1 = rand() % 6 + 1;
                dice2 = rand() % 6 + 1;
        
                cout << "Dice #1: " << dice1 << "\t" << "Dice #2: " << dice2 << endl;
        
                if (dice1 == dice2) // Fair dices landing on the same face value
                {
                    credNew = credNew + wage;   // Formula for wage sum
                
                    cout << "Your new balance is $" << credNew << endl;    
                }
                else
                {
                    credNew = credNew - wage;   // Formula for wage difference
                    
                    cout << "Your new balance is $" << credNew << endl;
                }
                
                cout << "Do you want to continue (Y/N)?: ";
                cin >> ans;
                
                ans = toupper(ans); // Data type prioritizes the letter to uppercase

	            // LOOP
	            while (ans != 'Y' && ans != 'N')    // User receives error message if not y/n or Y/N
	            {
	                cout << "ERROR: Invalid input.\n";
		            cout << "Please type (Y/N): ";
		            cin >> ans;
		            
		            ans = toupper(ans);
	            }
            }
        }
    }
    
    if (credNew == 0)   // User has no more credit to wage; OUTPUT
        cout << "You have no more credit. Thanks for playing!\n";
    else
        cout << "Thanks for playing!\n";
    
    return 0;
}
