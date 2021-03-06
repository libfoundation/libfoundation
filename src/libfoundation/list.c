#include <libfoundation/list.h>

struct LFList {
  struct LFRef *ref;
};

LFREF_RETAIN_RELEASE_IMPL(struct LFList, ref, LFListRetain, LFListRelease);

struct LFList *LFListNew() {
  struct LFList *list = malloc(sizeof(struct LFList));
  list->ref = LFRefNew();
  return list;
}
