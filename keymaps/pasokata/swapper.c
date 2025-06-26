#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record)
{
    if (keycode == trigger)
    {
        if (record->event.pressed)
        {
            if (!*active)
            {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        }
        else
        {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    }
    else if (*active)
    {
        unregister_code(cmdish);
        *active = false;
    }
}

void update_swapper2(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish1,
    uint16_t tabish2,
    uint16_t trigger1,
    uint16_t trigger2,
    uint16_t keycode,
    keyrecord_t *record)
{
    if (keycode == trigger1 || keycode == trigger2)
    {
        if (record->event.pressed)
        {
            if (!*active)
            {
                *active = true;
                register_code16(cmdish);
            }
            register_code16(keycode==trigger1? tabish1:tabish2);
        }
        else
        {
            unregister_code16(keycode == trigger1 ? tabish1 : tabish2);
            // Don't unregister cmdish until some other key is hit or released.
        }
    }
    else if (*active)
    {
        unregister_code16(cmdish);
        *active = false;
    }
}