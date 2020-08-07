
#include<iostream>
#include<windows.h>
#include <ctime>
#include<fstream>
#include"game.h"
using namespace std;
void SetWindowSize(int width, int height)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	bool bAbs = true;
	SMALL_RECT r;
	r.Left = 0;
	r.Top = 0;
	r.Right = width;
	r.Bottom = height;
	SetConsoleWindowInfo(h, bAbs, &r);
	COORD NewSBSize;
	NewSBSize.X = width+1;
	NewSBSize.Y = height+1;
	int Status= SetConsoleScreenBufferSize(h, NewSBSize);
}
//this overloaded function prints a string str in specified color at pos(x,y) void
void PrintXY(int x, int y,char a, int color)
{
COORD c;
c.X = x+2;
c.Y = y+2;
HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_SCREEN_BUFFER_INFO info;
GetConsoleScreenBufferInfo(h, &info);
short ret = info.wAttributes;
SetConsoleCursorPosition(h, c);
SetConsoleTextAttribute(h, color);
cout <<a<<" ";
cout.flush();
SetConsoleTextAttribute(h, ret);
}	

//Draw buttons on the screen starting from given co-ordinates 
void DrawButtons(int x,int y, int color,int &score) {
	PrintXY(x, y,'>', color);
	cout<<"press 11 to new game"<<endl;
	PrintXY(x, y+2,'>', color);
	cout<<"press 12 to save game"<<endl;
	PrintXY(x, y+4,'>', color);
	cout<<"score=";
	cout<<score;
}
void PrintX1Y1(int x, int y,char str[][10],int &row1,int&col1,int &row2,int &col2)
{
				COORD c;
				c.X = x;
				c.Y = y;
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				cout<<endl;
				cout << "enter the cordinates of box you want to shift"<<endl;
				cout<<"Or press 12 to save game"<<endl;
				cin>>row1;
				if(row1==12)
				{	
				ofstream fout("CandyCrush.txt");
				for(int i=0;i<10;i++)
				{
					for(int j=0;j<10;j++){
						fout<<str[i][j]<<" ";
					}
					cout<<endl;
				}
				fout.close();
				}
				else{
				cin>>col1;
				cout << "\n\n\nenter the cordinates of box where you want to shift this box"<<endl;
				cin>>row2;
				cin>>col2;
				}
				cout.flush();
}
void newBoard(char str[][10])
{
	int x=0,y=0,k,m,row,col;
	int n=0,d=0;
			for(int i=0;i<10;i++)
			{
					for(int j=0;j<10;j++)
					{
						PrintXY(n,d,str[i][j],1000);	
						n=n+3;
					}
					d=d+2;
					n=0;
			}
}
void shift2(char str[][10] ,int &k,int &m)
{
	while(k-1>=0)
	{
		str[k][m]=str[k-1][m];
		str[k][m-1]=str[k-1][m-1];
		str[k][m-2]=str[k-1][m-2];
		k--;
	}
	system("CLS");
	newBoard(str);
}
void shift3(char str[][10],int &h,int &l)
{
	 while(h-1>=0)
	{
		str[h][l]=str[h-3][l];
		str[h-1][l]=str[h-4][l];
		str[h-2][l]=str[h-5][l];
		h--;
	}
	system("CLS");
	newBoard(str);
}
void check(char str[][10])
{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(str[i][j]==str[i][j+1] && str[i][j+1]==str[i][j+2])
				{
						str[i][j+1]='*';
						str[i][j+2]='@';
							
				}
		    	else if(str[i][j]==str[i+1][j] && str[i+1][j]==str[i+2][j])
				{
						str[i+1][j]='%';
						str[i+2][j]='#';
						
			    }
			}
		}
}
void check2(char str[][10])
{
		for(int i=0;i<10;i++)
		{
			for(int j=0;j<10;j++)
			{
				if(str[i][j]==str[i][j+1] && str[i][j+1]==str[i][j+2])
				{
					str[i][j]='&';
							str[i][j+1]='@';
						str[i][j+2]='*';
							
				}
		    	else if(str[i][j]==str[i+1][j] && str[i+1][j]==str[i+2][j])
				{
					str[i][j]='@';
						str[i+1][j]='%';
						str[i+2][j]='#';
						
			    }
			}
		}
}
void Board(char str[][10])
{
			int x=0,y=0,k=0,m=0,h=0,l=0,row,col,score;
			SetWindowSize(400,200);
			DrawButtons(33,0,3000,score);
			srand(time(NULL));
				int n=0,d=0;
			for(int i=0;i<10;i++)
			{
					for(int j=0;j<10;j++)
					{
						m= (rand() %8)+1;
						if(m==1)
						{
							str[i][j]='@';
							PrintXY(n,d,str[i][j],1000);
						}
						if(m==2)
						{
								str[i][j]='#';
							PrintXY(n,d,str[i][j],1000);
						}
						if(m==3)
				    	{
								str[i][j]='%';
							PrintXY(n,d,str[i][j],1000);
						}
						if(m==4)
						{
								str[i][j]='&';
							PrintXY(n,d,str[i][j],1000);
						}
						if(m==5)
						{
								str[i][j]='*';
							PrintXY(n,d,str[i][j],1000);
						}
							if(m==6)
						{
								str[i][j]='?';
							PrintXY(n,d,str[i][j],1000);
						}
							if(m==7)
						{
								str[i][j]='$';
							PrintXY(n,d,str[i][j],1000);
						}
							if(m==8)
						{
								str[i][j]='!';
							PrintXY(n,d,str[i][j],1000);
						}	
						n=n+3;
					}
						d=d+2;
						n=0;
			}
			check(str);
			check2(str);
			
}
void shift (char str[][10],int &score)
{
		DrawButtons(33,0,3000,score);
		int row1,col1,row2,col2;
			PrintX1Y1(0,22,str,row1,col1,row2,col2);
			int temp=0;
		if(row2==row1-1 && col2==col1 || row2==row1+1 && col2==col1)
		{ 
				temp=str[row2][col2];
				str[row2][col2]=str[row1][col1];
				str[row1][col1]=temp;
     	}
     	else if(col2==col1-1 && row2==row1 || col2==col1+1 && row2==row1)
     	{
     		temp=str[row2][col2];
				str[row2][col2]=str[row1][col1];
				str[row1][col1]=temp;
		 }
				system("CLS");
				newBoard(str);	
}

void PlayGame(char str[][10],int &k,int &m ,int &h,int &l,int &score)
{
	
					for(int i=0;i<10;i++)
					{
						for(int j=0;j<10;j++)
						{
					    	shift (str,score);
							
							if(str[i][j]==str[i][j+1] && str[i][j+1]==str[i][j+2])
							{
								k=0,m=0;
								k=i;
								m=j+2;
								score++;
								str[i][j]=' ';
								str[i][j+1]=' ';
								str[i][j+2]=' ';
							  	shift2(str,k,m);
								system("CLS");
							   	newBoard(str);
							}
								if(str[i][j]==str[i][j-1] && str[i][j]==str[i][j+1])
							{
								k=0,m=0;
								k=i;
								m=j+2;
								score++;
								str[i][j]=' ';
								str[i][j+1]=' ';
								str[i][j+2]=' ';
							  	shift2(str,k,m);
								system("CLS");
							   	newBoard(str);
							}
									if(str[i][j]==str[i][j-1] && str[i][j]==str[i][j-2])
							{
								k=0,m=0;
								k=i;
								m=j+2;
								score++;
								str[i][j]=' ';
								str[i][j+1]=' ';
								str[i][j+2]=' ';
							  	shift2(str,k,m);
								system("CLS");
							   	newBoard(str);
							}
							if(str[i][j]==str[i+1][j] && str[i+1][j]==str[i+2][j])
							{
								h=0,l=0;
								h=i+2;
								l=j;
								str[i][j]=' ';
								str[i+1][j]=' ';
							    str[i+2][j]=' ';
								score++;
								shift3(str,h,l);			
						     	system("CLS");
						    	newBoard(str);
						 	}
						 	if(str[i][j]==str[i+1][j] && str[i][j]==str[i-1][j])
							{
								h=0,l=0;
								h=i+2;
								l=j;
								str[i][j]=' ';
								str[i+1][j]=' ';
							    str[i+2][j]=' ';
								score++;
								shift3(str,h,l);			
						     	system("CLS");
						    	newBoard(str);
						 	}
						 	if(str[i][j]==str[i-1][j] && str[i][j]==str[i-2][j])
							{
								h=0,l=0;
								h=i+2;
								l=j;
								str[i][j]=' ';
								str[i+1][j]=' ';
							    str[i+2][j]=' ';
								score++;
								shift3(str,h,l);			
						     	system("CLS");
						    	newBoard(str);
						 	}
						 	
						 }
					}
				}
int main()
{
	int score=0;
	int x=0,y=0,k,m,h,l,row1,col1,row2,col2,choice;
	char str[10][10];
	cout<<"Enter 10 to load or 11 to new game"<<endl;
	cin>>choice;
	if(choice==10){
	ifstream fin("CandyCrush.txt");
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			fin>>str[i][j];
		}
	}
	newBoard(str);
	fin.close();
	}
	else
	Board(str);
   	PlayGame(str,k,m,h,l,score);
	
}
	
        
