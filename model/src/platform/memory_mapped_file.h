/*
 * Copyright © 2024 Tim Herreijgers
 * Licensed using the MIT license
 */

#pragma once

#ifdef WIN32
#include "windows/memory_mapped_file.h"
#elif defined(__APPLE__) || defined(__unix__)
#include "unix/memory_mapped_file.h"
#endif
