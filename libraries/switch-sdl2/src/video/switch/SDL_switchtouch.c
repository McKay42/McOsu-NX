/*
  Simple DirectMedia Layer
  Copyright (C) 1997-2017 Sam Lantinga <slouken@libsdl.org>

  This software is provided 'as-is', without any express or implied
  warranty.  In no event will the authors be held liable for any damages
  arising from the use of this software.

  Permission is granted to anyone to use this software for any purpose,
  including commercial applications, and to alter it and redistribute it
  freely, subject to the following restrictions:

  1. The origin of this software must not be misrepresented; you must not
     claim that you wrote the original software. If you use this software
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered source versions must be plainly marked as such, and must not be
     misrepresented as being the original software.
  3. This notice may not be removed or altered from any source distribution.
*/
#include "../../SDL_internal.h"

#if SDL_VIDEO_DRIVER_SWITCH

#include <switch.h>

#include "SDL_events.h"
#include "SDL_hints.h"
#include "../../events/SDL_touch_c.h"
#include "../../video/SDL_sysvideo.h"

static HidTouchScreenState touchStateOld;
static SDL_TouchID switch_touch_id = 1;

void SWITCH_InitTouch(void)
{
    hidInitializeTouchScreen();
    SDL_AddTouch(switch_touch_id, SDL_TOUCH_DEVICE_DIRECT, "Switch");
    SDL_SetHintWithPriority(SDL_HINT_TOUCH_MOUSE_EVENTS, "0", SDL_HINT_DEFAULT);
    SDL_memset(&touchStateOld, 0, sizeof(touchStateOld));
}

void SWITCH_QuitTouch(void)
{

}

void SWITCH_PollTouch(void)
{
    const float rel_w = 1280.0f, rel_h = 720.0f;
    SDL_Window *window = SDL_GetFocusWindow();
    HidTouchScreenState state;
    SDL_bool found;
    s32 i, j;

    if (!window) {
        return;
    }

    if (!hidGetTouchScreenStates(&state, 1)) {
        return; /* no new sample; keep previous state untouched */
    }

    if (state.count < 0) {
        state.count = 0;
    } else if (state.count > (s32)SDL_arraysize(state.touches)) {
        state.count = (s32)SDL_arraysize(state.touches);
    }

    /* Down + motion: iterate the new state, always keyed by finger_id */
    for (i = 0; i < state.count; i++) {
        const SDL_FingerID finger = (SDL_FingerID)state.touches[i].finger_id;
        const float x = (float)state.touches[i].x / rel_w;
        const float y = (float)state.touches[i].y / rel_h;

        found = SDL_FALSE;
        for (j = 0; j < touchStateOld.count; j++) {
            if (touchStateOld.touches[j].finger_id == state.touches[i].finger_id) {
                found = SDL_TRUE;
                break;
            }
        }

        if (!found) {
            SDL_SendTouch(switch_touch_id, finger, window, SDL_TRUE, x, y, 1.0f);
        } else if (state.touches[i].x != touchStateOld.touches[j].x ||
                   state.touches[i].y != touchStateOld.touches[j].y) {
            SDL_SendTouchMotion(switch_touch_id, finger, window, x, y, 1.0f);
        }
    }

    /* Up: iterate the old state, again keyed by finger_id */
    for (i = 0; i < touchStateOld.count; i++) {
        found = SDL_FALSE;
        for (j = 0; j < state.count; j++) {
            if (state.touches[j].finger_id == touchStateOld.touches[i].finger_id) {
                found = SDL_TRUE;
                break;
            }
        }

        if (!found) {
            SDL_SendTouch(switch_touch_id,
                          (SDL_FingerID)touchStateOld.touches[i].finger_id,
                          window, SDL_FALSE,
                          (float)touchStateOld.touches[i].x / rel_w,
                          (float)touchStateOld.touches[i].y / rel_h, 1.0f);
        }
    }

    SDL_memcpy(&touchStateOld, &state, sizeof(touchStateOld));
}

#endif /* SDL_VIDEO_DRIVER_SWITCH */

/* vi: set ts=4 sw=4 expandtab: */

