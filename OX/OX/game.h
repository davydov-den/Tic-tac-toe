#pragma once
#include "stdafx.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;
public ref class Game
{
private: bool **col;
private:int n;
private:	int **stat;
public:		Game(int _n)
			{
				n=_n;
				stat = new int*[n];
				for(int i=0;i<n;i++)
				{
					stat[i] = new int[n];
					for(int j=0;j<n;j++)
						stat[i][j] = -1;
				}
				col  = new bool*[n];
				for(int i=0;i<n;i++)
					col[i] = new bool[n];
			};
public:	void Copy(Game^ oldStat)
		{
			int **old = oldStat->GetStat();
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					stat[i][j] = old[i][j];

			bool **oldCol = oldStat->GetCol();
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					col[i][j] = oldCol[i][j];
		}
public: int** GetStat()
		 {
			 return stat;
		 }
private: bool** GetCol()
		 {
			 return col;
		 }
public: bool action(Point x,int mode,bool IIStep)
		{
			if(isEmptyPlace(x))
			{
				stat[x.X][x.Y] = mode;
				col[x.X][x.Y] = IIStep;
				return true;
			}
			return false;
		}
private: bool isEmptyPlace(Point x)
		 {
			 if(x.X>-1 && x.X<n && x.Y>-1 && x.Y<n)
				 if(stat[x.X][x.Y]==-1)
					 return true;
				 else
					 return false;
			 else
				 return false;
		 }
public: bool isFinish()
		{
			if(full() || crossWin() || ZeroWin())
				return true;
			return false;
		}
private: bool full()
		 {
			 for(int i=0;i<n;i++)
				 for(int j=0;j<n;j++)
					 if(stat[i][j]==-1)
						 return false;
			 return true;
		 }
private: bool crossWin() //крестики выиграли
		 {
			 bool success;
			 for(int i=0;i<n;i++) //проверка по строкам
			 {
				 success = true;
				 for(int j=0;j<n && success;j++)
					 if(stat[i][j]!=0)
						 success = false;
				 if(success)
					 return true;
			 }

			 for(int i=0;i<n;i++) //проверка по столбцам
			 {
				 success = true;
				 for(int j=0;j<n && success;j++)
					 if(stat[j][i]!=0)
						 success = false;
				 if(success)
					 return true;
			 }

			 success = true;
			 for(int i=0;i<n;i++) //проверка по столбцам
				 if(stat[i][i]!=0)
					 success = false;
			 if(success)
				 return true;

			 success = true;
			 for(int i=0;i<n;i++) //проверка по столбцам
				 if(stat[n-i-1][i]!=0)
					 success = false;
			 if(success)
				 return true;

			 return false;

		 }
private: bool ZeroWin() //нолики выиграли
		 {
			 bool success;
			 for(int i=0;i<n;i++) //проверка по строкам
			 {
				 success = true;
				 for(int j=0;j<n && success;j++)
					 if(stat[i][j]!=1)
						 success = false;
				 if(success)
					 return true;
			 }

			 for(int i=0;i<n;i++) //проверка по столбцам
			 {
				 success = true;
				 for(int j=0;j<n && success;j++)
					 if(stat[j][i]!=1)
						 success = false;
				 if(success)
					 return true;
			 }

			 success = true;
			 for(int i=0;i<n;i++) //проверка по столбцам
				 if(stat[i][i]!=1)
					 success = false;
			 if(success)
				 return true;

			 success = true;
			 for(int i=0;i<n;i++) //проверка по столбцам
				 if(stat[n-i-1][i]!=1)
					 success = false;
			 if(success)
				 return true;

			 return false;
		 }
public: int WhoWin()
		{
			if(crossWin())
				return 0;
			else
				if(ZeroWin())
					return 1;
				else
					return -1;
		}
public: Graphics^ Draw(Graphics^ g)
		{
			for(int i=0;i<2;i++)
			{
				g->DrawLine(gcnew Pen(Color::Black,3.0f),0,120*(i+1),360,120*(i+1));
				g->DrawLine(gcnew Pen(Color::Black,3.0f),120*(i+1),0,120*(i+1),360);
			}
			for(int i=0;i<3;i++)
				for(int j=0;j<3;j++)
					if(stat[i][j]==0) //крестик
					{
						if(col[i][j])
						{
						g->DrawLine(gcnew Pen(Color::Blue,3.0f),i*120+20,j*120+20,i*120+100,j*120+100);
						g->DrawLine(gcnew Pen(Color::Blue,3.0f),i*120+20,j*120+100,i*120+100,j*120+20);
						}
						else
						{
						g->DrawLine(gcnew Pen(Color::Red,3.0f),i*120+20,j*120+20,i*120+100,j*120+100);
						g->DrawLine(gcnew Pen(Color::Red,3.0f),i*120+20,j*120+100,i*120+100,j*120+20);
						}

					}
					else
						if(stat[i][j]==1) //нолик
							if(col[i][j])
							g->DrawEllipse(gcnew Pen(Color::Blue,3.0f),i*120+20,j*120+20,80,80);
							else
								g->DrawEllipse(gcnew Pen(Color::Red,3.0f),i*120+20,j*120+20,80,80);
			return g;
		}
public: int* GetListEmptyPlace()
		{
			int *EmptyPlace;
			EmptyPlace =new int[n*n+1];
			int k=0;
			for(int i=0;i<n;i++)
				for(int j=0;j<n;j++)
					if(stat[i][j]==-1)
					{
						EmptyPlace[k] = i*n+j;
						k++;
					}
					EmptyPlace[n*n] = k;
					return EmptyPlace;
		}
public: int isOneStepToWin(int type)//0 - для крестиков 1 - для ноликов
		{
			int k;
			bool foal;
			for(int i=0;i<n;i++) //проверка по строкам
			{
				foal  = false;
				k = 0;
				for(int j=0;j<n&& !foal;j++)
				{
					if(stat[i][j]==type)
						k++;
					if(stat[i][j] == Math::Abs(1-type))
						foal = true;
				}
				if(k==n-1 && !foal)
				{
					for(int j=0;j<n;j++)
						if(stat[i][j] ==-1)
							return i*n+j;
				}
			}

			for(int i=0;i<n;i++) //проверка по столбцам
			{
				foal  = false;
				k = 0;
				for(int j=0;j<n && !foal;j++)
				{
					if(stat[j][i]==type)
						k++;
					if(stat[j][i] == Math::Abs(1-type))
						foal = true;
				}
				if(k==n-1 && !foal)
				{
					for(int j=0;j<n;j++)
						if(stat[j][i] ==-1)
							return j*n+i;
				}	
			}
			k = 0;
			foal = false;
			for(int i=0;i<n && !foal;i++) //проверка по диагонали
			{
				if(stat[i][i]==type)
					k++;
				if(stat[i][i] == Math::Abs(1-type))
					foal = true;
			}
			if(k==n-1 && !foal)
			{
				for(int i=0;i<n;i++)
					if(stat[i][i] ==-1)
						return i*n+i;
			}		

			k = 0;
			foal = false;
			for(int i=0;i<n;i++) //проверка по обратной диагонали
			{
				if(stat[i][n-i-1]==type)
					k++;
				if(stat[i][n-i-1] == Math::Abs(1-type))
					foal = true;
			}

			if(k==n-1 && !foal)
			{
				for(int i=0;i<n;i++)
					if(stat[i][n-i-1] ==-1)
						return i*n+n-i-1;
			}		

			return -1;
		}
};