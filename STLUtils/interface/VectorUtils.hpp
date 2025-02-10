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
inline void clear(std::vector<OBJTYPE> &vec, const OBJTYPE &target) {
  vec.erase(std::remove(vec.begin(), vec.end(), target), vec.end());
}

/**
 * Removing elements in a vector if matched by a given function
 */
template <typename OBJTYPE>
inline void clear_if(std::vector<OBJTYPE> &vec,
                     bool (*remote_func)(const OBJTYPE &)) {
  vec.erase(std::remove_if(vec.begin(), vec.end(), remote_func), vec.end());
}

/**
 * Return a vector with the same order as the original vector with duplicates
 * removed.
 */
template <typename OBJTYPE>
inline std::vector<OBJTYPE>
remove_duplicate(const std::vector<OBJTYPE> &orig_vec) {
  std::set<OBJTYPE> unique_set;
  std::vector<OBJTYPE> ans;
  for (const auto &item : orig_vec) {
    if (unique_set.insert(item).second) {
      ans.push_back(item);
    }
  }
  return ans;
}

/**
 * Check if the vector contains a particular entry value
 */
template <typename OBJTYPE>
inline bool check_contains(const std::vector<OBJTYPE> &vec, const OBJTYPE &x) {
  return std::find(vec.begin(), vec.end(), x) != vec.end();
}

/**
 * Getting the maximum/minimum value of an array
 */
template <typename OBJTYPE> OBJTYPE max(const std::vector<OBJTYPE> &vec) {
  return *std::max_element(vec.begin(), vec.end());
}

template <typename OBJTYPE> OBJTYPE min(const std::vector<OBJTYPE> &vec) {
  return *std::min_element(vec.begin(), vec.end());
}

} // namespace usr

#endif
