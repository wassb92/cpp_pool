#include <iostream>
#include "Errors.hpp"
#include "WaterReclaimer.hpp"

WaterReclaimer::WaterReclaimer()
    : _water(0)
    , _started(false)
{
}

void WaterReclaimer::start()
{
    !_water ? throw MissionCriticalError("Not enough water to achieve the mission.", "WaterReclaimer") : _started = true;
}

void WaterReclaimer::useWater(int water)
{
    !_water ? throw UserError("Cannot use water if the reclaimer hasn't started.", "WaterReclaimer") : water < 0 ? throw UserError("Water use should be positif.", "WaterReclaimer")
        : _water <= 10                                                                                           ? throw LifeCriticalError("Cannot use water, not enough in the reclaimer.", "WaterReclaimer")
                                                                                                                 : _water -= water;
}

void WaterReclaimer::generateWater()
{
    _water + 10 > 90 + (1 * 10) ? throw MissionCriticalError("Cannot generate water, reclaimer already full.", "WaterReclaimer") : _water += 10;
}