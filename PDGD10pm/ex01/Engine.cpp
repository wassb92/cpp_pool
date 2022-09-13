#include <cmath>
#include "Errors.hpp"
#include "Engine.hpp"

#define POW_2(x) (x * x)
#define ABS(x) (x < 0 ? -x : x)

Engine::Engine(float power, float x, float y)
    : _power(power)
    , _x(x)
    , _y(y)
{
}

Engine::~Engine()
{
}

void Engine::goTorward(float x, float y)
{
    const float dist = distanceTo(x, y);
    std::string x_as_string = std::to_string((int)x);
    std::string y_as_string = std::to_string((int)y);
    std::string error_msg = "Cannot reach destination (" + x_as_string + ", " + y_as_string + ").";

    if (dist > _power)
        throw UserError(error_msg, "Engine");
    _x = x;
    _y = y;
}
float Engine::distanceTo(float x, float y) const
{
    return std::sqrt(POW_2(ABS(x - _x)) + POW_2(ABS(y - _y)));
}

float Engine::getX() const
{
    return _x;
}

float Engine::getY() const
{
    return _y;
}
