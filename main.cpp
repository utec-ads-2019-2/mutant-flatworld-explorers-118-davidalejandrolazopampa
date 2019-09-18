//
// Created by David Lazo on 18/09/2019.
//
#include <iostream>
#include <vector>
#include <string>

using namespace std;
//Segun mande el documento
char pink[] = {'N', 'E', 'S', 'W'};
int xx[] = {0, 1, 0, -1};
int yy[] = {1, 0, -1, 0};

int main()
{
    //Inicio fin
    int xSize, ySize,x, y;
    char inicio;
    string orders;
    cin >> xSize >> ySize;

    vector<vector<bool> > scent(ySize + 1, vector<bool> (xSize + 1, false));

    while (cin >> x >> y >> inicio >> orders)
    {
        int array;

        for (int i = 0; i < 4; ++i)
            if (inicio == pink[i])
                array = i;

        bool punto = false;

        for (int i = 0; i < orders.size(); ++i)
        {

            if (orders[i] == 'R')
                array = (array + 1) % 4;

            else if (orders[i] == 'L')
                array = (array + 3) % 4;

            else
            {
                //posicion
                if ((x + xx[array] == -1) || (x + xx[array] == xSize + 1 ) || (y + yy[array] == -1) || (y + yy[array] == ySize + 1))
                {
                    if (!scent[y][x])
                    {
                        scent[y][x] = punto = true;
                        break;
                    }
                }

                else
                {
                    x += xx[array];
                    y += yy[array];
                }
            }
        }

        cout << x << ' ' << y << ' ' << pink[array] << (punto ?" LOST": "") << '\n';
    }


}