#include <iostream>
#include <vector>    // Para crear vectores
#include <algorithm> // Para usar find
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {

        vector<char> fila;
        vector<char> columna;
        vector<char> bloque;

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] != '.')
                {

                    /*
                        find busca el valor board[i][j] dentro del vector fila, desde el inicio (fila.begin())
                        hasta el final (fila.end()). Si NO encuentra el valor, devuelve fila.end(),
                        que representa el final del vector, es decir, si encuentra repetidos, devuelve algo diferente
                        a fila.end()
                    */
                    // Verificamos si el valor ya está en la fila
                    if (find(fila.begin(), fila.end(), board[i][j]) != fila.end())
                    {
                        return false;
                    }
                    fila.push_back(board[i][j]); // Vamos guardando los valores de la fila en el vector para luego saber si está repetido
                }

                if (board[j][i] != '.') // Intercambiando los índices i y j, recorremos las columnas en vez de las filas
                {
                    // Verificamos si el valor ya está en la columna
                    if (find(columna.begin(), columna.end(), board[j][i]) != columna.end())
                    {
                        return false;
                    }
                    columna.push_back(board[j][i]);
                }

                // Verificación de bloques 3x3
                int indice_fila = 3 * (i / 3) + j / 3;
                /*
                    - i / 3 obtiene la ubicación del bloque 3x3 en la dirección vertical (0, 1, o 2).
                    - j / 3 obtiene la ubicación del bloque 3x3 en la dirección horizontal (0, 1, o 2).
                    - Multiplicando i / 3 por 3 y sumando j / 3, se obtiene el índice de la fila global (del bloque 9x9).
                */

                int indice_columna = 3 * (i % 3) + j % 3;
                /*
                    - i % 3 obtiene la ubicación vertical DENTRO del bloque 3x3 (0, 1, o 2).
                    - j % 3 obtiene la ubicación horizontal DENTRO del bloque 3x3 (0, 1, o 2).
                    - Multiplicando i % 3 por 3 y sumando j % 3, se obtiene el índice de la columna global (del bloque 9x9).
                */

                /*
                 ACLARACIÓN: "/" indica en qué bloque 3x3 estamos, mientras que
                 "%" indica en qué posición dentro del bloque 3x3 estamos. La parte entera indica la posición
                 del bloque, mientras el residuo indica la posición DENTRO del bloque
                */

                if (board[indice_fila][indice_columna] != '.')
                {
                    if (find(bloque.begin(), bloque.end(), board[indice_fila][indice_columna]) != bloque.end())
                    {
                        return false;
                    }
                    bloque.push_back(board[indice_fila][indice_columna]);
                }
            }
            // Al final borramos el contenido de los vectores para chequear la siguiente fila, columna y bloque 3x3
            fila.clear();
            columna.clear();
            bloque.clear();
        }

        return true; // Si pasa las pruebas para encontrar valores repetidos, retornamos true
    }
};