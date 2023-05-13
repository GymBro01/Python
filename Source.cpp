#include<iostream>
#include<string>
#include<math.h>
#include<algorithm>
#include <vector> 
#include<conio.h>
#include<Windows.h>
using namespace std;

#define APPLE(a) a.pos.x = rand() * rand() % 67 + 26;a.pos.y = rand() * rand() % 28 + 2;if (a.pos.x % 2 == 1){	a.pos.x += 1;}TO_POSITION(a.pos.y, a.pos.x);for(int i=0;i<s.l;i++){if(a.pos.x==s.body[i].x&& a.pos.y == s.body[i].y){ a.pos.x = rand() * rand() % 67 + 26;a.pos.y = rand() * rand() % 28 + 2;if (a.pos.x % 2 == 1){	a.pos.x += 1;}TO_POSITION(a.pos.y, a.pos.x);i=0;}}cout << a.apple; 
#define FIELD cout << WHITE "\t\t\t";for (int i = 0; i < 70;i++){cout << wall;} cout<< YELLOW <<"\tPOINTS: "<<WHITE; for (int i = 0; i < 30; i++){cout << "\n\t\t\t"<<wall;for (int i = 0; i < 68; i++){cout << ' ';}cout << wall;}cout << "\n\t\t\t";for (int i = 0; i < 70; i++){cout << wall;}
#define RED "\033[31;1m" 
#define GREEN "\033[32m" 
#define WHITE "\033[37m" 
#define YELLOW "\033[33m" 
#define BLUE "\033[34;1m" 
#define CYAN "\033[36;1m" 
#define DEFAULT_COLOR "\033[m" 
#define PINK "\033[35;1m" 
#define BACKGROUND_GREY "\033[48;5;235m" 
#define DEFAULT_BACKGROUND_COLOR "\033[40m" 

#define CLEAR_LINE() (cout<<"\033[2K") 
#define CLEAR_TO_END() (cout<<"\033[0J") 
#define TO_COLUMN(num) (cout<<"\033["+to_string(num)+"G") 
#define TO_POSITION(row, column) (cout<<"\033[" + to_string(row) + ";" + to_string(column) +"H") 
#define CLEAR_LINE_TO_END() (cout<<"\033[0K") 
#define UP_LINE() (cout << "\033[1A") 
#define UP_LINES(x) (cout << "\033[" + to_string(x) + "F") 
#define DOWN_LINES(x) (cout << "\033[" + to_string(x) + "E") 
#define CURSOR_FORWARD (cout << "\033[1C") 
#define CURSOR_BACK (cout << "\033[1D")

class Pos
{
public:
	int x=70, y=17;
	Pos() {}
	Pos(int x,int y)
	{
		this->x = x;
		this->y = y;
	}

	bool operator ==(Pos B)
	{
		if (this->x == B.x && this->y == B.y)
		{
			return true;
		}
		else
			return false;
	}
};
class Snake
{
public:
	int p=0;
	Pos* body = new Pos[3];
	char turn='d';
	int l=3;
	string snake = "O";
	string snakeH = "@";
	Snake(){}

	void add()
	{
		Pos* copy = body;
		body = new Pos[l + 1];
		for (int i = 0; i < l; i++)
		{
			body[i] = copy[i];
		}
	}
};

class Apple
{
public:
	Apple() {}
	Pos pos;
	string apple = RED "*" DEFAULT_COLOR;
};


int main()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);

	Apple a;
	Apple a1;
	Apple a2;
	char wall='#';
	FIELD;
	bool go=false;
	
	Snake s;
	char ch=' ';
	
	APPLE(a);
	APPLE(a1);
	APPLE(a2);

	while (true)
	{
		SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
		TO_POSITION(1, 104);
		cout<< CYAN << s.p<<DEFAULT_COLOR;
		TO_POSITION(s.body[1].y, s.body[1].x);
		cout << s.snake;
		TO_POSITION(s.body[0].y, s.body[0].x);
		cout << YELLOW <<s.snakeH<< DEFAULT_COLOR;
		Sleep(100);
		if (_kbhit())
		{		
			ch = char(_getch());		
			if (ch == 'a' || ch == 's' || ch == 'd' || ch == 'w')
			{
							
				if(abs(s.turn-ch)!=3&&abs(s.turn-ch)!=4)
				s.turn = ch;
			}
		}
		TO_POSITION(s.body[s.l - 1].y, s.body[s.l - 1].x);
		cout << ' ';
		for (int i = s.l-1; i > 0 ; i--)
		{
			s.body[i] = s.body[i - 1];
		}

		switch (s.turn)
		{
		case 'w': 
		{
			s.body[0].y--;
			break;
		}
		case 's':
		{
			s.body[0].y++;
			break;
		}
		case 'a':
		{
			s.body[0].x-=2;
			break;
		}
		case 'd':
		{
			s.body[0].x+=2;
			break;
		}
		default:
			break;
		}
      	if (s.body[0] == a.pos)
		{
			s.add();
			s.l += 1;
			s.p++;
			APPLE(a)
		}
		if (s.body[0] == a1.pos)
		{
			s.add();
			s.l += 1;
			s.p++;
			APPLE(a1)
		}
		if (s.body[0] == a2.pos)
		{
			s.add();
			s.l += 1;
			s.p++;
			APPLE(a2)
		}

		for (int i = 1; i < s.l; i++)
		{
			if (s.body[0] == s.body[i])
			{
				go = true;
				break;
			}
		}
		if(s.body[0].x==94|| s.body[0].x == 25)
		{
			go = true;
		
		}
		if (s.body[0].y == 1 || s.body[0].y == 32)
		{
			go = true;
			
		}

		if (go)
		{
			TO_POSITION(s.body[0].y, s.body[0].x);
			cout << RED << 'X';
			Sleep(300);
			for (int i = 1; i < s.l; i++)
			{
				TO_POSITION(s.body[i].y, s.body[i].x);
				cout << 'X';
				Sleep(300);
			}
			system("cls");
			cout << "\t\t\t\t #######       #####      ##       ##    #########\n\t\t\t\t##      #    ##     ##    ###     ###    ##\n\t\t\t\t##           ##     ##    ## ##### ##    ##\n\t\t\t\t##   ####    #########    ##  ###  ##    ########\n\t\t\t\t##     ##    ##     ##    ##       ##    ##\n\t\t\t\t #######     ##     ##    ##       ##    #########\n\n\n\t\t\t\t  #####     ##       ##    #########    #######\n\t\t\t\t##     ##    ##     ##     ##           ##    ##\n\t\t\t\t##     ##    ##     ##     ##           #######\n\t\t\t\t##     ##     ##   ##      ########     ####\n\t\t\t\t##     ##      ## ##       ##           ##  ##\n\t\t\t\t  #####         ###        #########    ##    ##";
			break;
		}

	}
	
	

}

