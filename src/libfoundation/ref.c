#include <libfoundation/ref.h>
#include <stdlib.h>
#include <inttypes.h>

// TODO make thread safe with mutex around refcount
struct LFRef {
  uint8_t refcount;
};

struct LFRef *LFRefNew() {
  struct LFRef *ref = malloc(sizeof(struct LFRef));
  ref->refcount = 1;
  return ref;
}

struct LFRef *LFRefRetain(struct LFRef *ref) {
  ref->refcount++;
  return ref;
}

struct LFRef *LFRefRelease(struct LFRef *ref) {
  ref->refcount--;
  if (ref->refcount == 0) {
    free(ref);
    return NULL;
  } else {
    return ref;
  }
}
