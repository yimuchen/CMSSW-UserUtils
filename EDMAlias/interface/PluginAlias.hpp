#ifndef USERUTILS_EDMALIAS_PLUGINALIAS_HPP
#define USERUTILS_EDMALIAS_PLUGINALIAS_HPP

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"
#include "FWCore/Framework/interface/one/EDFilter.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "TFile.h"
#include "TObject.h"

#include <string>

namespace usr {

/**
 * Helper plugin to reduce the verbosity of one-off analysis plugins.
 * Notice that derivatives of this method should probably not be used to scale
 * up to a full analysis framework
 */
template <typename EDMPLUGIN> class PluginAlias : public EDMPLUGIN {
private:
  /** Saving a copy of the configuration to be used by derivative classes */
  const edm::ParameterSet &_config;

public:
  PluginAlias(const edm::ParameterSet &config) : _config(config) {}
  virtual ~PluginAlias() {}

protected:
  /** Helper function for token spawning in constructor */
  template <typename TYPE>
  inline edm::EDGetToken make_token(const std::string &configtag) {
    return edm::EDConsumerBase::consumes<TYPE>(
        _config.getParameter<edm::InputTag>(configtag));
  }

  template <typename TYPE>
  inline edm::EDGetToken make_run_token(const std::string &configtag) {
    return edm::EDConsumerBase::consumes<TYPE, edm::InRun>(
        _config.getParameter<edm::InputTag>(configtag));
  }

  /** Helper function for creating handle in analysis code */
  template <typename TYPE>
  inline edm::Handle<TYPE> make_handle(const edm::Event &event,
                                       const edm::EDGetToken tok) {
    edm::Handle<TYPE> handle;
    event.getByToken(tok, handle);
    assert(handle.isValid());
    return handle;
  }
};

//** Concrete override of common EDProcessor types
typedef PluginAlias<edm::one::EDAnalyzer<edm::one::SharedResources>> EDAnalyzer;
typedef PluginAlias<edm::one::EDFilter<edm::one::SharedResources>> EDFilter;

} // namespace usr

#endif /* end of include guard: USERUTILS_EDMUTILS_PLUGINALIAS_HPP */
