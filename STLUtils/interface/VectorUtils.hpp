#ifndef USERUTILS_STLUTILS_VECTORUTILS
#define USERUTILS_STLUTILS_VECTORUTILS

/** This is a common utility functions for std::vector, but we default then to
 * operate on the entire range of the vectors
 */

#include <algorithm>
#include <set>
#include <vector>

namespace usr {

/**
 * Remove elements in an array if it matches a concrete value
 */
template <typename OBJTYPE>
void clear(std::vector<OBJTYPE> &vec, const OBJTYPE &x) {
  vec.erase(std::remove(vec.begin(), vec.end(), x), vec.end());
}

/**
 * Removing elements in a vector if matched by a given function
 */
template <typename OBJTYPE>
void clear_if(std::vector<OBJTYPE> &vec, bool (*func)(const OBJTYPE &)) {
  vec.erase(std::remove_if(vec.begin(), vec.end(), func), vec.end());
}

/**
 * Return a vector with the same order as the original vector with duplicates
 * removed.
 */
template <typename OBJTYPE>
std::vector<OBJTYPE> remove_duplicate(const std::vector<OBJTYPE> &dupvec) {
  std::set<OBJTYPE> unique_set;
  std::vector<OBJTYPE> ans;
  for (const auto &item : dupvec) {
    if (unique_set.insert(item).second) {
      ans.push_back(item);
    }
  }
  return ans;
}

} // namespace usr

#endif
