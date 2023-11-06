// baseado em https://stackoverflow.com/questions/16641209/reading-and-storing-values-from-obj-files-using-c

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

class objectReader
{
public:
    void readObj()
    {
        std::string linha, v, coordX[8], coordY[8], coordZ[8];
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
                iss >> v >> coordX[i] >> coordY[i] >> coordZ[i];
                std::cout << coordX[i] << " " << coordY[i] << " " << coordZ[i] << std::endl;
                i++;
            }
            else
            {
                return;
            }
        }
    }
};
