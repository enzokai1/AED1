#include <iostream>
#include <string>

using namespace std;

int sudoku[9][9];

bool verificaLinha(int x)
{
    int numeros[10];

    for (int i = 0; i < 10; ++i)
    {
        numeros[i] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (numeros[sudoku[x][i]])
            return false;
        numeros[sudoku[x][i]] += 1;
    }

    return true;
}

bool verificaColuna(int x)
{
    int numeros[10];

    for (int i = 0; i < 10; ++i)
    {
        numeros[i] = 0;
    }

    for (int i = 0; i < 9; ++i)
    {
        if (numeros[sudoku[i][x]])
            return false;
        numeros[sudoku[i][x]] += 1;
    }

    return true;
}

bool verificaQuadrado(int x)
{
    int numeros[10];
    int linha = 3 * (x / 3), coluna = 3 * (x % 3);

    for (int i = 0; i < 10; ++i)
    {
        numeros[i] = 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            if (numeros[sudoku[linha + i][coluna + j]])
                return false;
            numeros[sudoku[linha + i][coluna + j]] += 1;
        }
    }

    return true;
}

int main()
{
    int n;
    string resposta;

    cin >> n;

    for (int k = 1; k <= n; ++k)
    {
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; ++j)
            {
                cin >> sudoku[i][j];
            }
        }

        cout << "Instancia " << k << endl;

        resposta = "SIM";
        for (int i = 0; i < 9; ++i)
        {
            if (!verificaLinha(i) || !verificaColuna(i) || !verificaQuadrado(i))
            {
                resposta = "NAO";
                break;
            }
        }

        cout << resposta << endl
             << endl;
    }

    return 0;
}
