#pragma once

struct LFRef;

struct LFRef *LFRefNew();
void LFRefRetain(struct LFRef *ref);
void LFRefRelease(struct LFRef *ref);
