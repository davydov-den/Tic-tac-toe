#include "game.h"
#include "moved.h"
using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

class AI
{
public: Moved* GetBestMove(Game^ game,int type)
        {
			int* tmp = game->GetListEmptyPlace();
			
			Moved* max = new Moved();
			if(tmp[9]==0)
			{
				max->lose = true;
			return max;
			}

			bool MaxNull = true;
			for(int i=0;i<tmp[9];i++)
            {
                Moved* move = GetMoveFitness(game, tmp[i],type);
                if (MaxNull || move->Fitness > max->Fitness)
				{
                    max = move;
					MaxNull = false;
				}
            }
            return max;
        }

public: Moved* GetMoveFitness(Game^ game, int p,int type)
        {
            Moved *res = new Moved();
			int x,y;
			x = p/3;
			y= p - x*3;
			Point p1 = Point(x,y);
			res->X = x;
			res->Y = y;
            //имитируем ход
            Game^ g = gcnew Game(3);
			g->Copy(game);
			g->action(p1,type,true);

            //если выиграли - возвращаем 1
            if (g->WhoWin() >-1)
                res->Fitness = 1.0f;
            else
            {
                //выбираем лучший вариант для хода противника
                Moved* best = GetBestMove(g,Math::Abs(1-type));
				if(!best->lose)
                    res->Fitness = -best->Fitness; //возвращаем худшую для нас оценку	
				res->Fitness/=2;
            }
            return res;
        }    
};

