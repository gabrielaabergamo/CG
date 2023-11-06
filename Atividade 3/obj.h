// baseado em https://stackoverflow.com/questions/16641209/reading-and-storing-values-from-obj-files-using-c
// https://stackoverflow.com/questions/40390571/read-in-points-from-obj-file-c

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class objectReader
{
public:
    void readObj()
    {
        std::string linha, v, coordX, coordY, coordZ;
        int i = 0;

        // leitura do arquivo .obj
        std::ifstream obj_file("cat_obj/cat.obj");

        while (!obj_file.eof())
        {
            // vamos checar se o primeiro caracter é 'v'. se for, faremos a leitura
            getline(obj_file, linha);

            if (linha[0] == 'v')
            {
                std::istringstream iss(linha);
                iss >> v >> coordX >> coordY >> coordZ;
                std::cout << coordX << " " << coordY << " " << coordZ << std::endl;
                i++;
            }
            else
            {
                return;
            }
        }
    }
};
