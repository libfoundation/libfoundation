#pragma once

#include <stdbool.h>

struct LFRef;

struct LFRef *LFRefNew();
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
