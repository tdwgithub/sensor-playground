/*! \file
**
** MODULE: tdw_timer.cpp
**
** DESCRIPTION: Arduino library for asynchronous timers.
**
** Copyright 2021-2022 by Forty|W, Inc.  All rights reserved.
**
** REVISION HISTORY:
**
*/

#include <Arduino.h>
#include <stdint.h>
#include "tdw_timer.h"

/*! \fn
**
** FUNCTION: No-parameter constructor.
**
** DESCRIPTION: Assumes the user will supply timeout
**              to the "finished()" method.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AsyncTimer::AsyncTimer()
{
    is_running = false;
    timeoutMS = 0;
    capture = 0;
}

/*! \fn
**
** FUNCTION: No-parameter destructor.
**
** DESCRIPTION:
** 
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AsyncTimer::~AsyncTimer()
{
    is_running = false;
    timeoutMS = 0;
    capture = 0;
}

/*! \fn
**
** FUNCTION: Timeout-parameter provided constructor.
**
** DESCRIPTION:
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
AsyncTimer::AsyncTimer(uint32_t _timeoutMS)
{
    capture = millis();
    is_running = true;
    this->timeoutMS = _timeoutMS;
}

/*! \fn
**
** FUNCTION: start
**
** DESCRIPTION: No arguments.  Implies that the "finished()" method will be
**              called with the timeout.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AsyncTimer::start()
{
    capture = millis();
    is_running = true;
    timeoutMS = 0;
}

/*! \fn
**
** FUNCTION: start
**
** DESCRIPTION: A timeout value must be provided.  Implies the "finished()" method
**              will be called without any argument.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AsyncTimer::start(uint32_t _timeoutMS)
{
    this->timeoutMS = _timeoutMS;
    this->capture = millis();
    this->is_running = true;
}

/*! \fn
**
** FUNCTION: finished
**
** DESCRIPTION: Assumes that "start()" was called with a timeout value.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
bool AsyncTimer::finished()
{
    if (this->is_running)
    {
        if (this->timeoutMS > 0)
        {
            return this->_finished(this->timeoutMS);
        }
    }

    return (true);
}

/*! \fn
**
** FUNCTION: finished
**
** DESCRIPTION: Checks to see if the timer has expired, using the argument.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
bool AsyncTimer::finished(uint32_t _timeoutMS)
{
    if (_timeoutMS > 0)
    {
        if (this->is_running)
        {
            return (this->_finished(_timeoutMS));
        }
    }

    return (false);
}

/*! \fn
**
** FUNCTION: running
**
** DESCRIPTION: Returns whether or not the timer is running.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
bool AsyncTimer::running()
{
    return (this->is_running);
}

/*! \fn
**
** FUNCTION: cancel
**
** DESCRIPTION: Sets the object to be NOT running.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
void AsyncTimer::cancel()
{
    this->is_running = false;
    this->capture = 0;
    this->timeoutMS = 0;
}

// INTERNAL

/*! \fn
**
** FUNCTION: _finished
**
** DESCRIPTION: Internal method that checks the timeout value versus the
**              captured ticks.  If expired, the "is_running" flag is
**              reset and TRUE is returned.
**
** PARAMETERS:
**
** RETURNS:
**
** COMMENTS:
**
*/
bool AsyncTimer::_finished(uint32_t _timeoutMS)
{
    if (_timeoutMS > 0)
    {
        uint32_t            current = millis();

        if ( (current-this->capture) >= _timeoutMS )
        {
            this->is_running = false;
            return (true);
        }
    }

    return (false);
}
