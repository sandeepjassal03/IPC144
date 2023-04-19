/*
*****************************************************************************
						  Workshop - #7 (P1)
Full Name  : Sandeep Singh
Student ID#: 162054217
Email      : ssingh1224@myseneca.ca
Section    : NGG

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MIN_PATH_LENGTH 10
#define MAX_PATH_LENGTH 70
#define PATH_LENGTH_MULTIPLE 5

#define MIN_LIVES 1
#define MAX_LIVES 10

#define MIN_MOVES 3
#define MAX_MOVES 15

struct PlayerInfo
{
	int number_of_lives;
	char player_symbol;
	int count_of_found_treasures;
	char user_entered_positions[MAX_PATH_LENGTH];
};
struct GameInfo
{
	int number_of_moves;
	int path_length;
	int bomb_placements[MAX_PATH_LENGTH];
	int treasure_placements[MAX_PATH_LENGTH];
};

int main(void)
{
	int flag = 0, game_loop_flag = 0, symbol_flag = 1, value = 0, count = 0, ruler = 0, user_move = 0;
	struct PlayerInfo Player_1 = { 0 };
	struct GameInfo Config_1 = { 0 };

	printf("================================\n");
	printf("         Treasure Hunt!\n");
	printf("================================\n\n");

	printf("PLAYER Configuration\n");
	printf("--------------------\n");

	printf("Enter a single character to represent the player: ");
	scanf(" %c", &Player_1.player_symbol);
	while (flag == 0)
	{
		printf("Set the number of lives: ");
		scanf(" %d", &value);
		if (value >= MIN_LIVES && value <= MAX_LIVES)
		{
			Player_1.number_of_lives = value;
			flag = 1;
			printf("Player configuration set-up is complete\n\n");
		}
		else
		{
			printf("     Must be between %d and %d!\n", MIN_LIVES, MAX_LIVES);
		}
	}

	printf("GAME Configuration\n");
	printf("------------------\n");

	flag = 0;
	value = 0;
	while (flag == 0)
	{
		printf("Set the path length (a multiple of 5 between 10-70): ");
		scanf(" %d", &value);
		if (value >= MIN_PATH_LENGTH && value <= MAX_PATH_LENGTH)
		{
			if (value % 5 == 0)
			{
				Config_1.path_length = value;
				flag = 1;
			}
			else
			{
				printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
			}
		}
		else
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", PATH_LENGTH_MULTIPLE, MIN_PATH_LENGTH, MAX_PATH_LENGTH);
		}
	}

	flag = 0;
	value = 0;
	while (flag == 0)
	{
		printf("Set the limit for number of moves allowed: ");
		scanf(" %d", &value);
		if (value >= MIN_MOVES && value <= MAX_MOVES)
		{
			Config_1.number_of_moves = value;
			flag = 1;
		}
		else
		{
			printf("    Value must be between %d and %d\n", MIN_MOVES, MAX_MOVES);
		}
	}

	printf("\nBOMB Placement\n");
	printf("--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\n", PATH_LENGTH_MULTIPLE);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Config_1.path_length);

	for (count = 0; count < Config_1.path_length; count++)
	{

		printf("   Positions [%2d-%2d]: ", count + 1, count + 5);
		scanf(" %d %d %d %d %d", &Config_1.bomb_placements[count], &Config_1.bomb_placements[count + 1], &Config_1.bomb_placements[count + 2], &Config_1.bomb_placements[count + 3], &Config_1.bomb_placements[count + 4]);
		count += (PATH_LENGTH_MULTIPLE - 1);
	}
	printf("BOMB placement set\n");

	printf("\nTREASURE Placement\n");
	printf("------------------\n");
	printf("Enter the treasure placements in sets of %d where a value\n", PATH_LENGTH_MULTIPLE);
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", Config_1.path_length);

	for (count = 0; count < Config_1.path_length; count++)
	{

		printf("   Positions [%2d-%2d]: ", count + 1, count + 5);
		scanf(" %d %d %d %d %d", &Config_1.treasure_placements[count], &Config_1.treasure_placements[count + 1], &Config_1.treasure_placements[count + 2], &Config_1.treasure_placements[count + 3], &Config_1.treasure_placements[count + 4]);
		count += (PATH_LENGTH_MULTIPLE - 1);
	}
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------\n");
	printf("Player:\n");
	printf("   Symbol     : %c\n", Player_1.player_symbol);
	printf("   Lives      : %d\n", Player_1.number_of_lives);
	printf("   Treasure   : [ready for gameplay]\n");
	printf("   History    : [ready for gameplay]\n\n");
	printf("Game:\n");
	printf("   Path Length: %d\n", Config_1.path_length);
	printf("   Bombs      : ");
	for (count = 0; count < Config_1.path_length; count++)
	{
		printf("%d", Config_1.bomb_placements[count]);
	}
	printf("\n   Treasure   : ");
	for (count = 0; count < Config_1.path_length; count++)
	{
		printf("%d", Config_1.treasure_placements[count]);
	}
	printf("\n\n====================================\n");
	printf("~ Get ready to play TREASURE HUNT! ~\n");
	printf("====================================\n\n");
	for (count = 0; count < Config_1.path_length; count++)
	{
		Player_1.user_entered_positions[count] = '-';
	}

	flag = 0;
	while (game_loop_flag == 0)
	{
		if (symbol_flag == 0)
		{
			for (count = 0; count < user_move - 1; count++)
			{
				printf(" ");
			}
			printf("  %c\n", Player_1.player_symbol);
		}
		symbol_flag = 0;
		printf("  ");
		for (count = 0; count < Config_1.path_length; count++)
		{
			printf("%c", Player_1.user_entered_positions[count]);
		}
		printf("\n  ");
		for (count = 0; count < Config_1.path_length; count++)
		{
			if ((count + 1) % 10 == 0)
			{
				printf("%d", (count + 1) / 10);
			}
			else
			{
				printf("|");
			}
		}
		printf("\n  ");
		for (count = 0; count < Config_1.path_length; count++)
		{
			if (count == 0)
			{
				ruler = count;
			}

			if ((count + 1) % 10 == 0)
			{
				printf("%d", 0);
				ruler = 0;
			}
			else
			{
				printf("%d", ruler + 1);
				ruler++;
			}

		}
		printf("\n+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player_1.number_of_lives, Player_1.count_of_found_treasures, Config_1.number_of_moves);
		printf("+---------------------------------------------------+\n");
		while (flag == 0)
		{
			printf("Next Move [1-%d]: ", Config_1.path_length);
			scanf(" %d", &user_move);
			if (user_move <= 0 || user_move > 20)
			{
				printf("  Out of Range!!!\n");
			}
			else
			{
				flag = 1;
			}
		}

		if (Player_1.user_entered_positions[user_move - 1] != '-')
		{
			printf("\n===============> Dope! You've been here before!\n\n");
		}
		else
		{
			Config_1.number_of_moves -= 1;
			if (Config_1.bomb_placements[user_move - 1] == 0 && Config_1.treasure_placements[user_move - 1] == 0)
			{
				printf("\n===============> [.] ...Nothing found here... [.]\n\n");
				Player_1.user_entered_positions[user_move - 1] = '.';

			}
			else if (Config_1.bomb_placements[user_move - 1] == 1 && Config_1.treasure_placements[user_move - 1] == 0)
			{
				printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
				Player_1.user_entered_positions[user_move - 1] = '!';
				Player_1.number_of_lives -= 1;
			}
			else if (Config_1.bomb_placements[user_move - 1] == 0 && Config_1.treasure_placements[user_move - 1] == 1)
			{
				printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
				Player_1.user_entered_positions[user_move - 1] = '$';
				Player_1.count_of_found_treasures += 1;
			}
			else if (Config_1.bomb_placements[user_move - 1] == 1 && Config_1.treasure_placements[user_move - 1] == 1)
			{
				printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
				printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
				Player_1.user_entered_positions[user_move - 1] = '&';
				Player_1.number_of_lives -= 1;
				Player_1.count_of_found_treasures += 1;
			}
		}
		if (Player_1.number_of_lives == 0 || Config_1.number_of_moves == 0)
		{
			game_loop_flag = 1;
		}
		flag = 0;
	}
	printf("No more LIVES remaining!\n\n");
	for (count = 0; count < user_move - 1; count++)
	{
		printf(" ");
	}
	printf("  %c\n", Player_1.player_symbol);
	printf("  ");
	for (count = 0; count < Config_1.path_length; count++)
	{
		printf("%c", Player_1.user_entered_positions[count]);
	}
	printf("\n  ");
	for (count = 0; count < Config_1.path_length; count++)
	{
		if ((count + 1) % 10 == 0)
		{
			printf("%d", (count + 1) / 10);
		}
		else
		{
			printf("|");
		}
	}
	printf("\n  ");
	for (count = 0; count < Config_1.path_length; count++)
	{
		if (count == 0)
		{
			ruler = count;
		}

		if ((count + 1) % 10 == 0)
		{
			printf("%d", 0);
			ruler = 0;
		}
		else
		{
			printf("%d", ruler + 1);
			ruler++;
		}

	}
	printf("\n+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", Player_1.number_of_lives, Player_1.count_of_found_treasures, Config_1.number_of_moves);
	printf("+---------------------------------------------------+\n\n");
	printf("##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!\n");

	return 0;
}
