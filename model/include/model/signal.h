/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#pragma push_macro("slots")
#pragma push_macro("signals")

#ifdef slots
#undef slots
#endif

#ifdef signals
#undef signals
#endif

#include "libfastsignals/signal.h"

namespace Signals = is::signals;

#pragma pop_macro("slots")
#pragma pop_macro("signals")
