/*! \file
**
** MODULE: tdw_timer.h
**
** DESCRIPTION: My simple async timer class.
**
** Copyright 2021-2022 by Forty|W, Inc.  All rights reserved.
**
** REVISION HISTORY:
**
*/

#ifndef __TDW_TIMER_H_INCLUDED
#define __TDW_TIMER_H_INCLUDED

#include "Arduino.h"
#include <stdint.h>
#include <math.h>

class AsyncTimer
{
    public:
        AsyncTimer(uint32_t _timeoutMS);
        AsyncTimer();
       ~AsyncTimer();
        void start();
        void start(uint32_t _timeoutMS);
        bool finished(uint32_t _timeoutMS);
        bool finished();
        bool running();
        void cancel();

    private:
        bool        is_running;
        uint32_t    timeoutMS;
        uint32_t    capture;

        bool _finished(uint32_t _timeoutMS);
};



#endif // __TDW_TIMER_H_INCLUDED
