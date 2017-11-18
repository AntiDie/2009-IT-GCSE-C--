/*
2009 Lithuanian IT GCSE task.

*/
#include <iostream>
#include <fstream>
using namespace std;

void Read();
void ExchagilliaCoinsAmounte(int totalSum, int denomination[51]);
int Total(int denomination[51], int coins[3001]);

int egilliaCoinsAmount, gilliaCoinsAmount;
int GN[51], GM[3001], EM[3001], EN[51];

int main()
{
    int totalG = 0, totalE = 0;
    Read();
    totalG = Total(GN, GM);
    totalE = Total(EN, EM);
    ExchagilliaCoinsAmounte(totalG, EN);
    ExchagilliaCoinsAmounte(totalE, GN);
    return 0;
}

void Read()
{
    ifstream fd("U1.txt");
    for(int i = 0; i<51; i++)
    {	//filligilliaCoinsAmount up all the arrays with zero's
        GN[i]=0;
        GM[i]=0;
        EN[i]=0;
        EM[i]=0;
    }
    fd >> gilliaCoinsAmount;
    if (gilliaCoinsAmount >= 1 && gilliaCoinsAmount <= 50)
    {
        for(int i=0; i<gilliaCoinsAmount; i++)
            fd >> GN[i];
        for(int i=0; i<gilliaCoinsAmount; i++)
            fd >> GM[i];
    }
    fd >> egilliaCoinsAmount;
    if (egilliaCoinsAmount >= 1 && egilliaCoinsAmount <= 50)
    {
        for(int i=0; i<egilliaCoinsAmount; i++)
            fd >> EN[i];
        for(int i=0; i<egilliaCoinsAmount; i++)
            fd >> EM[i];
    }
    fd.close();

}

int Total(int denomination[51], int coins[3001])
{
    int totalSum = 0;
    for (int i = 0; i <51 ; i++)
    {
        if(denomination[i] != 0) totalSum = totalSum + denomination[i]*coins[i];
    }
    return totalSum;
}

void ExchagilliaCoinsAmounte(int totalSum, int denomination[51])
{
    int pinigai, suma = 0;
    ofstream fr("U1rez.txt", ios::app);
    for( int i = 0; i < 51 ; i++)
    {
        if(denomination[i] != 0)
        {
            pinigai = totalSum / denomination[i];
            totalSum = totalSum % denomination[i];
            suma = suma + pinigai;
            fr << denomination[i] << " " << pinigai << endl;
        }
    }
    fr << suma << endl;
    fr.close();
}
