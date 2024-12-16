# CMSSW End-user utility library

This is a small collection of packages that aims to provide a better, less
verbose experience when exploring data in CMSSW plugins and functions. This
package does not aim to be a fully fledged analysis framework, and you probably
should not base your analysis framework on this, but rather it helps with
writing smaller CMSSW projects that make the initial data exploration process
in EDM formats less painful, as well as my wrappers to make STL container
manipulation simpler.

Packages here are written to be header-only whenever possible, as these aims to
be generic libraries for C++ code interactions. However, we are still going to
respect the CMSSW file hierarchy and keep header files in the `interface`
directory.

## Installing

This package can be installed into your CMSSW environment by cloning the
directory into the `CMSSW_X_Y_Z/src` directory named as the `UserUtils`
directory. Remember to rerun the `scram b` command to compile.

```bash
cd CMSSW_X_Y_Z/src
git clone git@github.com:yimuchen/CMSSW-UserUtils.git UserUtils
scram b
```

## Notes

This repository supersedes the old
[UserUtils](https://github.com/yimuchen/UserUtils) repository, as that
repository attempts to do too much, and either better tools were developed:

- Complicated command-line parsing should be handled by python `argparse`
  instead of boost where ever this is possible
- Plotting should be done by cmsStyle library.

Or was found to not be as trivially generalized, such as with the case of
physics libraries.

