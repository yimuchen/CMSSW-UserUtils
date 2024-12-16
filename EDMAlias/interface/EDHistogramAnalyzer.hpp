#ifndef USERUTILS_EDMALIAS_EDHISTOGRAMANALYZER
#define USERUTILS_EDMALIAS_EDHISTOGRAMANALYSER
#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "UserUtils/EDMAlias/interface/PluginAlias.hpp"

#include "TH1D.h"
#include "TH2D.h"
#include "TH3D.h"
#include "TProfile.h"

namespace usr {

class EDHistogramAnalyzer : public EDAnalyzer {
public:
  EDHistogramAnalyzer(const edm::ParameterSet &config) : PluginAlias(config) {
    usesResource("TFileService");
  };
  ~EDHistogramAnalyzer() {}

protected:
  edm::Service<TFileService> fs;
  std::map<std::string, TH1D *> _histmap;
  std::map<std::string, TH2D *> _hist2dmap;
  std::map<std::string, TH3D *> _hist3dmap;
  std::map<std::string, TProfile *> _profmap;

  template <typename... Args>
  inline TH1D &BookHist1D(const std::string &name, Args... args) {
    _histmap[name] = fs->make<TH1D>(name.c_str(), "", args...);
    return *(_histmap[name]);
  }

  template <typename... Args>
  inline TH2D &BookHist2D(const std::string &name, Args... args) {
    _hist2dmap[name] = fs->make<TH2D>(name.c_str(), "", args...);
    return *(_hist2dmap[name]);
  }

  template <typename... Args>
  inline TH3D &BookHist3D(const std::string &name, Args... args) {
    _hist3dmap[name] = fs->make<TH3D>(name.c_str(), "", args...);
    return *(_hist3dmap[name]);
  }

  template <typename... Args>
  inline TProfile &BookProfile1D(const std::string &name, Args... args) {
    _profmap[name] = fs->make<TProfile>(name.c_str(), "", args...);
    return *(_profmap[name]);
  }

  inline bool HasHist(const std::string &x) { return _histmap.count(x); }
  inline bool HasHist2D(const std::string &x) { return _hist2dmap.count(x); }
  inline bool HasHist3D(const std::string &x) { return _hist3dmap.count(x); }
  inline bool HasProfile(const std::string &x) { return _profmap.count(x); }

  inline TH1D &Hist(const std::string &x) { return *(_histmap[x]); }
  inline TH2D &Hist2D(const std::string &x) { return *(_hist2dmap[x]); }
  inline TH3D &Hist3D(const std::string &x) { return *(_hist3dmap[x]); }
  inline TProfile &Profile(const std::string &x) { return *(_profmap[x]); }
};

} // namespace usr

#endif
