#include<string>
#include<math.h>
#include<algorithm>
#include <vector> 
#include<conio.h>
#include<Windows.h>
#include<iostream>
using namespace std;

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
	int x = 70, y = 17;
	Pos() {}
	Pos(int x, int y)
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


int main()
{
	CONSOLE_CURSOR_INFO cursor;
	cursor.bVisible = false;
	cursor.dwSize = 1;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
	


bool turnX;


for (int i = 0; i < 4; i++)
{
	cout << "\n\t\t\t\t\t\t##      ##";
}

	cout << "\n\t\t\t\t          ";
	for (int r = 0; r < 22; r++)
	{
		cout << "#";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "\n\t\t\t\t\t\t##      ##";
	}
	cout << "\n\t\t\t\t          ";
	for (int r = 0; r < 22; r++)
	{
		cout << "#";
	}
	for (int i = 0; i < 4; i++)
	{
		cout << "\n\t\t\t\t\t\t##      ##";
	}
	Pos field [3][3];
	
	field[0][0] = { 43,2 };
	int y = 0; int x = 0;
	for (int i = 0; i < 3; i++,y+=5,x=0)
	{
		for (int r = 0; r < 3; r++, x+=8)
		{
			field[i][r].x = field[0][0].x + x;
			field[i][r].y = field[0][0].y + y;
		}
	}
	char ch;
	while (true)
	{
		Pos cur=field[1][1];
		while (ch != ' ')
		{
			cin >> ch;
			switch (ch)
			{
			case 'a':
			{
				if (cur.x != field[0][0].x)
				{
					cur.x = field[0][0].x;
				}
				break;
			}
			case 'w':
			{
				if (cur.y != field[0][0].y)
				{
					cur.y = field[0][0].y;
				}
				break;
			}
			case 's':
			{
				if (cur.y != field[2][0].y)
				{
					cur.y = field[2][0].y;
				}
				break;
			}
			case 'd':
			{
				if (cur.x != field[0][2].x)
				{
					cur.x = field[0][2].x;
				}
				break;
			}
			default:
				break;
			}
		}
	}
}















/*
class An
{
public:
	string name="Petya", stat="";
	An() {}

	virtual void say()
	{
		cout << "I'm An";
	}
	void Name()
	{
		cout << name;
	}
	virtual void type()
	{
		cout << "I'm An";
	}

};

class Dog:public An
{
public:

	Dog() {}

	virtual void say()
	{
		cout << "I'm Dog";
	}
	virtual void type()
	{
		cout << "I'm Dog";
	}
};

class Cat :public An
{
public:

	Cat() {}

	 void say()
	{
		cout << "I'm Cat";
	}
	virtual void type()
	{
		cout << "I'm Cat";
	}
};

class Hamster :public An
{
public:

	Hamster() {}

	virtual void say()
	{
		cout << "I'm Colobok";
	}
	virtual void type()
	{
		cout << "I'm Colobok";
	}
};



int main()
{
	Dog d;
	Cat c;
	Hamster h;
	An an;
	An* a[4] ={&d,&c,&h,&an};

	for (int i = 0; i < 4; i++)
	{
		a[i]->say();
		cout << endl;
		a[i]->type();
		cout << endl;
		a[i]->Name();
		cout << endl;

	}
}*/













/*


class list
{
public:
	int* v = new int[0];
	int l=0;
	list() {}
	void add(int x)
	{
		int* copy = v;
		l += 1;
		v = new int[l];
		for (int i = 0; i < l - 1; i++)
		{
			v[i] = copy[i];
		}
		v[l - 1] = x;
	}

	virtual	void del()
	{

	}
};

class queue :public list
{
public:
	queue() {}
	virtual	void del()
	{
		int* copy = v;
		l -= 1;
		v = new int[l];
		
		for (int i = 0; i<l; i++)
		{
			v[i] = copy[i + 1];
		}
	}
};

class stack :public list
{
public:
	

	virtual	void del()
	{
		int* copy = v;
		l -= 1;
		v = new int[l];
		for (int i = 0; i < l; i++)
		{
			v[i] = copy[i];
		}
	}
	stack() {}
};


int main()
{
	list* l[1];
	queue s;
	l[0] = &s;
	l[0]->add(1);
	l[0]->add(2);
	cout << l[0]->v[0] << " " << l[0]->v[1]<<" ";
	l[0]->del();
	cout << l[0]->v[0] << " " << l[0]->v[1];

}*/



