#pragma once

struct LFList;

struct LFList *LFListNew();
void LFListRetain(struct LFList *list);
void LFListRelease(struct LFList *list);
