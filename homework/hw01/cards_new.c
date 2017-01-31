#include <stdio.h>
#include <stdlib.h>

int getVal(char card_name[])
{
/*
Takes in a string array
Checks the value of the first index.
Returns that value
*/
	int val = 0;
	switch (card_name[0]) {
		case 'K':
		case 'Q':
		case 'J':
			val = 10;
			break;
		case 'A':
			val = 11;
			break;
		case 'X':
			break;
		default:
			val = atoi(card_name);
			if ((val<1) || (val>10)){
				puts("I don't understand that value!");
			break;
			}
	}
	return val;
}

int changeCount(int val, int count)
{
/*
Takes in the card value and current count
Updates count based on card value
Returns new count
*/
	if ((val > 2) && (val<7)){
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

int main()
{
/*
Initializes count and card_name array
Asks for user input
Sends user input to getVal function to get the card val
Sends card val and count to change count to get updated count
Prints count
Exits while loop when val = 'X'
*/
	int count = 0;
	char card_name[3];
	while (card_name[0] != 'X'){
		puts("Enter the card name: ");
		scanf("%2s", card_name);

	int val = getVal(card_name);

	count = changeCount(val, count);

	printf("Current count is %i\n", count);
	}
	return 0;
}
