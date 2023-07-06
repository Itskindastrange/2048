#include <iostream>
#include <iomanip>
#include<windows.h>
#include <conio.h>
using namespace std;
int check();
void display();
int up();
int down();
int left();
int right();
static int p = 0;
static int arr[4][4] = {};
void Color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Color(int color, int col)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color | col);
}
int check()
{
	int f = 0;
	{
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{

				if (arr[i][j] == 0 && arr[i + 1][j] != 0)
				{
					{
						f++;
					}
				}
				else if (arr[i][j] == arr[i + 1][j] && arr[i][j] != 0)
				{

					{
						f++;
					}
				}
			}

		}
	}
	{
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (arr[i][j] == 0 && arr[i][j + 1] != 0)
				{
					f++;
				}
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] != 0)
				{
					f++;
				}
			}
		}

	}
	{
		for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 0 && arr[i - 1][j] != 0)
				{
					f++;
				}
				else if (arr[i][j] == arr[i - 1][j] && arr[i][j] != 0)
				{
					f++;
				}
			}
		}

	}
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (arr[i][j] == 0 && arr[i][j - 1] != 0)
				{
					f++;
				}
				else if (arr[i][j] == arr[i][j - 1] && arr[i][j] != 0)
				{
					f++;
				}
			}
		}
	}
	return f;
}
void menu()
{
	bool k = false;
	int f = 1, g = 1, h = 1, i = 1, a = 1;
	int r;
	cout << "enter 1 to start playing" << endl;
	cin >> r;
	cout << endl;
	while (1) {
		system("cls");
		if (f != 0) {
			display();
		}
		else {
			cout << "Cannot Move in this Direction" << endl;
		}
		::p = ::p + 1;
		cout << endl;
		char t;
		cout << "Enter\n\'l\' to move left\n\'r\' to move right\n\'u\' to move up\n\'d\' to move down" << endl;
		t = _getch();

		while (t != 108 && t != 114 && t != 117 && t != 100)
		{
			if (t == 108 || t == 114 || t == 117 || t == 100)
				break;
			cout << "Enter Again\n\'l\' to move left\n\'r\' to move right\n\'u\' to move up\n\'d\' to move down" << endl;
			t = _getch();
		}
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 1024)
					k = true;
			}
		}
		if (k == true)
		{
			cout << "You Win!!!" << endl;
			break;
		}
		if (check() != 0) {
			if (t == 100)
			{
				f = down();
				a = down();
			}
			if (t == 117)
			{
				f = up();
				g = up();
			}
			if (t == 114)
			{
				f = right();
				h = right();
			}
			if (t == 108)
			{
				f = left();
				i = left();
			}
		}
		else
		{
			cout << "You lose" << endl;
			break;
		}
	}
}

int main() {
	menu();
}
int up() {
	int c = 0, f = 0;
	while (c < 3) {
		for (int j = 0; j < 4; j++)
		{
			for (int i = 0; i < 3; i++)
			{

				if (arr[i][j] == 0 && arr[i + 1][j] != 0)
				{
					{
						arr[i][j] = arr[i + 1][j];
						arr[i + 1][j] = 0;
						f++;
					}
				}
				else if (arr[i][j] == arr[i + 1][j] && arr[i][j] != 0)
				{

					{
						arr[i][j] = arr[i][j] + arr[i][j];
						arr[i + 1][j] = 0;
						f++;
					}
				}
			}

		}
		c++;
	}
	return f;
}
int left() {
	int c = 0, f = 0;
	while (c < 3) {
		for (int j = 0; j < 3; j++)
		{
			for (int i = 0; i < 4; i++)
			{
				if (arr[i][j] == 0 && arr[i][j + 1] != 0)
				{
					arr[i][j] = arr[i][j + 1];
					arr[i][j + 1] = 0;
					f++;
				}
				else if (arr[i][j] == arr[i][j + 1] && arr[i][j] != 0)
				{
					arr[i][j] = arr[i][j] + arr[i][j + 1];
					arr[i][j + 1] = 0;
					f++;
				}
			}
		}
		c++;
	}
	return f;
}
int down() {
	int c = 0, f = 0;
	while (c < 3) {
		for (int i = 3; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 0 && arr[i - 1][j] != 0)
				{
					arr[i][j] = arr[i - 1][j];
					arr[i - 1][j] = 0;
					f++;
				}
				else if (arr[i][j] == arr[i - 1][j] && arr[i][j] != 0)
				{
					arr[i][j] = arr[i][j] + arr[i - 1][j];
					arr[i - 1][j] = 0;
					f++;
				}
			}
		}
		c++;
	}
	return f;
}
int right() {
	int c = 0, f = 0;

	while (c < 3) {
		for (int i = 0; i < 4; i++)
		{
			for (int j = 3; j > 0; j--)
			{
				if (arr[i][j] == 0 && arr[i][j - 1] != 0)
				{
					arr[i][j] = arr[i][j - 1];
					arr[i][j - 1] = 0;
					f++;
				}
				else if (arr[i][j] == arr[i][j - 1] && arr[i][j] != 0)
				{
					arr[i][j] = arr[i][j] + arr[i][j - 1];
					arr[i][j - 1] = 0;
					f++;
				}
			}
		}
		c++;
	}
	return f;
}
void display() {
	srand(time(0));
	int x, y;
	x = rand() % 4;
	y = rand() % 4;
	while (arr[x][y] != 0)
	{
		x = rand() % 4;
		y = rand() % 4;
	}
	arr[x][y] = (rand() % 2) + 1;
	if (p == 0) {
		int n = rand() % 4;
		int m = rand() % 4;
		while (n == x && m == y)
		{
			n = rand() % 4;
			m = rand() % 4;
		}
		arr[n][m] = (rand() % 2) + 1;
	}
	cout << endl << endl << endl;
	cout << setw(72) << "-----------------------------" << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (j == 0)
			{
				if (arr[i][j] == 0)
				{
					cout << setw(44) << "|";
					cout << setw(6) << "";
				}
				else {
					if (arr[i][j] == 1)
					{
						cout << setw(44) << "|";
						Color(10);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 2)
					{
						cout << setw(44) << "|";
						Color(12);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 4)
					{
						cout << setw(44) << "|";
						Color(3);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 8)
					{
						cout << setw(44) << "|";
						Color(5);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 16)
					{
						cout << setw(44) << "|";
						Color(8);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 128)
					{
						cout << setw(44) << "|";
						Color(14);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else
					{
						cout << setw(44) << "|";
						cout << setw(6) << arr[i][j];
					}
				}
			}
			else {
				if (arr[i][j] == 0)
				{
					cout << "|";
					cout << setw(6) << "";
				}
				else
				{
					if (arr[i][j] == 1) {
						cout << "|";
						Color(10);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 2)
					{
						cout << "|";
						Color(12);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 4)
					{
						cout << "|";
						Color(3);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 8)
					{
						cout << "|";
						Color(5);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 16)
					{
						cout << "|";
						Color(8);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else if (arr[i][j] == 128)
					{
						cout << "|";
						Color(14);
						cout << setw(6) << arr[i][j];
						Color(7);
					}
					else
					{
						cout << "|";
						cout << setw(6) << arr[i][j];
					}
				}
			}
		}
		cout << "|" << endl << setw(72) << "-----------------------------" << endl;
	}
}