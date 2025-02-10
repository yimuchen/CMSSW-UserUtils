#include "UserUtils/STLUtils/interface/StringUtils.hpp"

#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>

#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm_ext/erase.hpp>

namespace usr {

/**OS environment variable as C++ string */
std::string os_env(const std::string &x) { return std::getenv(x.c_str()); }

std::string to_upper(const std::string &x) {
  return boost::algorithm::to_upper_copy(x);
}

std::string to_lower(const std::string &x) {
  return boost::algorithm::to_lower_copy(x);
}

bool starts_with(const std::string &primary, const std::string &target) {
  if (target.size() > primary.size()) {
    return false;
  }
  return std::equal(target.begin(), target.end(), primary.begin());
}

bool ends_with(const std::string &primary, const std::string &target) {
  if (target.size() > primary.size()) {
    return false;
  }
  return std::equal(target.rbegin(), target.rend(), primary.rbegin());
}

} // namespace usr
