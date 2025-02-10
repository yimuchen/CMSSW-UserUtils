#ifndef USERUTILS_STLUTILS_STRINGUTILS
#define USERUTILS_STLUTILS_STRINGUTILS

#include <boost/format.hpp>
#include <string>

namespace usr {

/** Returning the OS environment variable as a string */
extern std::string os_env(const std::string &);

/** Python style string manipulation */
extern std::string to_upper(const std::string &);
extern std::string to_lower(const std::string &);
extern bool starts_with(const std::string &, const std::string &);
extern bool ends_with(const std::string &, const std::string &);
extern std::string StripSubstring(const std::string &, const std::string &);
extern std::string StripCharacters(const std::string &, const std::string &);
extern std::string StripToNaming(const std::string &);

/** Variadic functions to achive a C-style printf formatting to generate display
 * strings*/
inline std::string fstr(boost::format &fmt) { return boost::str(fmt); }

template <typename TYPE, typename... ARGS>
inline std::string fstr(boost::format &fmt, TYPE &&T, ARGS &&...args) {
  return fstr(fmt % std::forward<TYPE>(T), std::forward<ARGS>(args)...);
}

template <typename... ARGS>
inline std::string fstr(const std::string &fmt, ARGS &&...args) {
  boost::format f(fmt);
  return fstr(f, std::forward<ARGS>(args)...);
}

} // namespace usr

#endif
