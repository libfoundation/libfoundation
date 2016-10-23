#include <libfoundation/list.h>
#include <libfoundation/ref.h>
#include <stdlib.h>

struct LFList {
  struct LFRef *ref;
};

struct LFList *LFListNew() {
  struct LFList *list = malloc(sizeof(struct LFList));
  list->ref = LFRefNew();
  return list;
}

struct LFList *LFListRetain(struct LFList *list) {
  LFRefRetain(list->ref);
  return list;
}

struct LFList *LFListRelease(struct LFList *list) {
  list->ref = LFRefRelease(list->ref);
  if (list->ref == NULL) {
    free(list);
    return NULL;
  } else {
    return list;
  }
}
