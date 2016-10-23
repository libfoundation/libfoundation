#pragma once

struct LFList;

struct LFList *LFListNew();
struct LFList *LFListRetain(struct LFList *list);
struct LFList *LFListRelease(struct LFList *list);
