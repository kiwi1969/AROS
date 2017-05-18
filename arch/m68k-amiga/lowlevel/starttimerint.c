/*
    Copyright � 2017, The AROS Development Team. All rights reserved.
    $Id$
*/

#include <aros/libcall.h>

#include <proto/cia.h>

#include <exec/types.h>
#include <libraries/lowlevel.h>
#include <hardware/cia.h>
#include <resources/cia.h>

#include "lowlevel_intern.h"
#include "cia_intern.h"
#include "cia_timer.h"

AROS_LH3(VOID, StartTimerInt,
      AROS_LHA(APTR , intHandle, A1),
      AROS_LHA(ULONG, timeInterval, D0),
      AROS_LHA(BOOL , continuous, D1),
      struct LowLevelBase *, LowLevelBase, 16, LowLevel)
{
  AROS_LIBFUNC_INIT

    if (intHandle && timeInterval > 0)
    {
        
    }
    return;

  AROS_LIBFUNC_EXIT
}
