// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#include "Framework/DynamicBalancerMethodData.hh"
#include "Framework/SubSystemStatus.hh"

//////////////////////////////////////////////////////////////////////////////

using namespace std;
using namespace COOLFluiD::Common;

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Framework {

//////////////////////////////////////////////////////////////////////////////

void DynamicBalancerMethodData::defineConfigOptions(Config::OptionList& options)
{
}

//////////////////////////////////////////////////////////////////////////////

DynamicBalancerMethodData::DynamicBalancerMethodData(Common::SafePtr<Method> owner)
 : MethodData(owner)
{
  addConfigOptionsTo(this);
}

//////////////////////////////////////////////////////////////////////////////

DynamicBalancerMethodData::~DynamicBalancerMethodData()
{
}

//////////////////////////////////////////////////////////////////////////////

void DynamicBalancerMethodData::configure ( Config::ConfigArgs& args )
{
}

//////////////////////////////////////////////////////////////////////////////

void DynamicBalancerMethodData::setup()
{
  MethodData::setup();
}

//////////////////////////////////////////////////////////////////////////////

void DynamicBalancerMethodData::unsetup()
{
  MethodData::unsetup();
}

//////////////////////////////////////////////////////////////////////////////

    } // namespace Framework

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////