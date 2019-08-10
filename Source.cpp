#include <iostream>
#include <string>
#include <locale>
using namespace std;
int iter = 0;

struct Players
{
	string name_player;
};

bool check_step(char array[3][3],int c,const char* ku)
{
	if (c >= 1 && c <= 3)
	{
		if (array[1][c] != ' ')
		{
			cout << "Значение " << c << " нельзя!" << endl;

			return false;
		}
		else
		{
			array[1][c] = *ku;
			return true;
		}
	}

	if (c >= 4 && c <= 6)
	{
		if (array[1][c] != ' ')
		{
			cout << "Значение " << c << " нельзя!" << endl;
			return false;
		}
		else
		{
			c = c - 3;
			array[2][c] = *ku;
		}
	}

	if (c >= 6 && c <= 9)
	{
		if (array[1][c] != ' ')
		{
			cout << "Значение " << c << " нельзя!" << endl;
			return false;
		}
		else
		{
			c = c - 6;
			array[3][c] = *ku;
		}
	}
}

void player_go(char array[3][3], string name_player, char pa)
{
	cout << "Ходит игрок:" << name_player << endl;
	int c;

	while (true)
	{
		cout << "Клетка: ";
		cin >> c;
		if (c <= 9 && c >= 1)
		{
			if (check_step(array, c, &pa))
			{
				break;
			}
		}
		else
		{
			cout << "Значение " << c << "не входит в диапазон!" << endl;
			continue;
		}

	}


}

void printArray(const char array[3][3])
{
	system("cls");
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cout << "|" << array[i][j] << "|";
		}
		cout << endl;
	}
}

bool check_win(const char arr[3][3])
{
	for (int i = 1; i <= 3; i++)
	{
		if(((arr[i][1]!=' ')&&arr[i][1]==arr[i][2])&&(arr[i][1]==arr[i][3]))
		{
			return true;
		}
		else if(((arr[1][i]!=' ')&&arr[1][i]==arr[2][i])&&(arr[1][i]==arr[3][i]))
			{
				return true;
			}
		else if((arr[1][1]!=' ')&&arr[1][1]==arr[2][2]&&(arr[1][1]==arr[3][3])||(arr[3][1]==arr[2][2]and(arr[3][1]==arr[1][3])))
			{
				return true;
			}
	}
	return false;
}

bool check_draw(const char arr[3][3])
{
	if(!check_win(arr))
	{
		return true;
	}
}
void game(char matrix[3][3],string player_one,string player_two)
{
	int i = 1;
	char a_1 = 'X';
	char a_2 = 'O';
	char* pa_1 = &a_1;
	char* pa_2 = &a_2;
	bool apart = false;
	do
	{

		printArray(matrix);
		if (iter % 2 == 0)
		{
			player_go(matrix, player_one, *pa_1);
			printArray(matrix);
			if (i >= 5)
			{
				apart = check_win(matrix);
				if (i == 9 && check_draw(matrix))
				{
					cout << "Ничья" << endl;
					break;

				}
				if (apart)
				{
					cout << "Победил " << player_one << endl;
				}
			}
		}
		else
		{
			player_go(matrix, player_two, *pa_2);
			printArray(matrix);
			if (i >= 5)
			{
				if (i == 9 && check_draw(matrix))
				{
					cout << "Ничья" << endl;
					break;
				}
				apart = check_win(matrix);
				if (apart)
				{
					cout << "Победил " << player_two << endl;
				}
			}
		}
		iter++;
		i++;
	} while (!apart);

}
void new_game(char matrix[3][3])
{
	for (int i = 1; i <= 3; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			matrix[i][j] = ' ';
		}
	}
}
int main()
{
	setlocale(LC_ALL, "ru");

	iter = rand() % 10;
	Players one, two;
	char matrix[3][3];
	cout << "Имя первого игрока: ";
	cin >> one.name_player;
	cout << "Имя второго игрока: ";
	cin >> two.name_player;

	new_game(matrix);
	game(matrix, one.name_player, two.name_player);
	


	cout << "Еще раз? 'y'\'n'"<<endl;
	char c;
	cin >> c;
	while (c=='y')
	{
		new_game(matrix);
		game(matrix, one.name_player, two.name_player);
		cout << "Еще раз? 'y'\'n'" << endl;
		char c;
		cin >> c;
	}
	
		return 0;
	
	
}