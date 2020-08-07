#ifndef GAME_H
#define GAME_H
void SetWindowSize(int width, int height);
void PrintXY(int x, int y,char a, int color);
void DrawButtons(int x,int y, int color,int &score);
void PrintX1Y1(int x, int y,char str[][10],int &row1,int&col1,int &row2,int &col2);
void newBoard(char str[][10]);
void shift2(char str[][10] ,int &k,int &m);
void shift3(char str[][10],int &h,int &l);
void check(char str[][10]);
void check2(char str[][10]);
void Board(char str[][10]);
void shift (char str[][10],int &score);
void PlayGame(char str[][10],int &k,int &m ,int &h,int &l,int &score);
#endif
