#include <gtest/gtest.h>

extern "C" {
#include <libfoundation/ref.h>
}

TEST(LFRefTest, initial_retain_count) {
  struct LFRef *ref = LFRefNew();
  ASSERT_EQ(1, LFRefRetainCount(ref));
}

TEST(LFRefTest, retain) {
  struct LFRef *ref = LFRefNew();
  ref = LFRefRetain(ref);
  ASSERT_EQ(2, LFRefRetainCount(ref));
}

TEST(LFRefTest, release) {
  struct LFRef *ref = LFRefNew();
  ref = LFRefRelease(ref);
  ASSERT_EQ(NULL, ref);
}
