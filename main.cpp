//#include "SDL.h"
#include "Engine.h"




int main()
{
    PingPong::Engine engine("PingPong", 640, 480);
    if (!engine.init()) return -1;
    engine.run();
    return 0;
}

