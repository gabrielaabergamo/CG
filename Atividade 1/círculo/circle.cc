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

    Image image(Geometry(200, 200), Color("white"));

    image.fillColor("black");
    image.draw(DrawableCircle(100, 100, 50, 100));

    image.fillColor("red");
    image.draw(DrawableCircle(200, 100, 180, 80));

    image.fillColor("red");
    image.draw(DrawableCircle(0, 100, 20, 80));

    image.write("circle.png");
  }
  catch (exception &error_)
  {
    cout << "Caught exception: " << error_.what() << endl;
    return 1;
  }

  return 0;
}