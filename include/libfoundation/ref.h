#pragma once

#include <stdbool.h>

struct LFRef;

struct LFRef *LFRefNew();
struct LFRef *LFRefRetain(struct LFRef *ref);
struct LFRef *LFRefRelease(struct LFRef *ref);
