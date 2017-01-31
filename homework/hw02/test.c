#include <stdio.h>
#include <stdlib.h>

int getVal(char card_name[])
{
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

int changeCount(int val)
{
	if ((val > 2) && (val<7)){
		count++;
	} else if (val == 10) {
		count--;
	}
	return count;
}

int main()
{
	int count = 0;
	char card_name[3];
	while (card_name[0] != 'X'){
		puts("Enter the card name: ");
		scanf("%2s", card_name);

	int val = getVal(card_name);

	count = changeCount(val);

	printf("Current count is %i\n", count);
	}
	return 0;
}
