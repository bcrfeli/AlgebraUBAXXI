#include <iostream>

/*
* Se considera el sistema lineal
* S: {
* x-y+z+w = 2
* 3x+y+z+w = 6
* 5x-3y-3z+w = 0
* }
* 
* v1=(0,0,0,0)
* v2=(1,1,1,1)
* v3=(-2,2,-3,7)
* v4=(0,2,2,2)
* 
* Decidir cuales de los vectores son soluciones de S
*/

struct vec4 {
    int x;
    int y;
    int z;
    int w;
};

const int filas{ 3 };
const int columnas{ 4 };

int matriz[filas][columnas] = {
        {1,-1,1,1},
        {3,1,1,1},
        {5,-3,-3,1},
};

bool resultado(vec4 vector)
{
    int correctos = 0;

    for (int i = 0; i < filas; i++)
    {
        int res_fila = 0;
        for (int j = 0; j < columnas; j++)
        {
            switch (j)
            {
                case 0:
                    res_fila += vector.x * matriz[i][j];
                    break;
                case 1:
                    res_fila += vector.y * matriz[i][j];
                    break;
                case 2:
                    res_fila += vector.z * matriz[i][j];
                    break;
                case 3:
                    res_fila += vector.w * matriz[i][j];
                    break;
            }
           
        }
        //std::cout << res_fila << std::endl;
        switch (i)
        {
            case 0:
                correctos += (res_fila == 2) ? 1 : 0;
                break;
            case 1:
                correctos += (res_fila == 6) ? 1 : 0;
                break;
            case 2:
                correctos += (res_fila == 0) ? 1 : 0;
                break;
        }
    }

    if (correctos == filas)
        return true;
    else
        return false;
}

int main()
{
    vec4 v1 = {
        .x = 0,
        .y = 0,
        .z = 0,
        .w = 0
    };

    vec4 v2 = {
        .x = 1,
        .y = 1,
        .z = 1,
        .w = 1
    };

    vec4 v3 = {
        .x = -2,
        .y = 2,
        .z = -3,
        .w = 7
    };

    vec4 v4 = {
        .x = 0,
        .y = 2,
        .z = 2,
        .w = 2
    };

    if (resultado(v4))
        std::cout << "CORRECTO" << std::endl;

}