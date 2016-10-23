#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

struct LFRef;

struct LFRef *LFRefNew();
uint8_t LFRefRetainCount(struct LFRef *ref);
struct LFRef *LFRefRetain(struct LFRef *ref);
struct LFRef *LFRefRelease(struct LFRef *ref);

#define LFREF_RETAIN_RELEASE_IMPL(type, refname, retain, release) \
    type *retain(type *obj) {                                     \
      LFRefRetain(obj->refname);                                  \
      return obj;                                                 \
    }                                                             \
                                                                  \
    type *release(type *obj) {                                    \
      obj->refname = LFRefRelease(obj->refname);                  \
      if (obj->refname == NULL) {                                 \
        free(obj);                                                \
        return NULL;                                              \
      } else {                                                    \
        return obj;                                               \
      }                                                           \
    }
