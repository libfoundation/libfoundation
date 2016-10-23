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

void LFListRetain(struct LFList *list) {
  LFRefRetain(list->ref);
}

void LFListRelease(struct LFList *list) {
  LFRefRelease(list->ref);
}
