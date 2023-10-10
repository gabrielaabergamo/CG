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

        image.strokeColor("red");
        image.fillColor("black");
        image.strokeWidth(2);

        image.draw(DrawableRectangle(500, 400, 270, 270));

        image.strokeColor("white");
        image.fillColor("black");
        image.strokeWidth(2);
        image.draw(DrawableRectangle(600, 400, 470, 470));

        image.write("rectangle.png");
    }
    catch (exception &error_)
    {
        cout << "Caught exception: " << error_.what() << endl;
        return 1;
    }

    return 0;
}