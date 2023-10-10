#include <string>
#include <iostream>
#include <Magick++.h>

using namespace std;
using namespace Magick;

int main(int /*argc*/, char **argv)
{
    try
    {
        InitializeMagick(*argv);

        Image image(Geometry(1000, 500), Color("black"));

        image.fillColor("white");
        image.strokeWidth(5);
        image.draw(DrawableEllipse(390, 150, 40, 60, 0, 360));

        image.fillColor("black");
        image.draw(DrawableEllipse(420, 190, 30, 60, 0, 360));

        image.fillColor("white");
        image.strokeWidth(5);
        image.draw(DrawableEllipse(510, 150, 40, 60, 0, 360));

        image.fillColor("black");
        image.draw(DrawableEllipse(540, 190, 30, 60, 0, 360));

        image.fillColor("white");
        image.draw(DrawableEllipse(455, 340, 60, 40, 50, 180));

        image.strokeColor("white");
        image.strokeWidth(2);
        image.draw(DrawableLine(460, 260, 470, 300));
        image.draw(DrawableLine(460, 300, 470, 300));

        image.write("rosto.png");
    }
    catch (exception &error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }

    return 0;
}