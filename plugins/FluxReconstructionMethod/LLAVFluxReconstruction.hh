// Copyright (C) 2012 von Karman Institute for Fluid Dynamics, Belgium
//
// This software is distributed under the terms of the
// GNU Lesser General Public License version 3 (LGPLv3).
// See doc/lgpl.txt and doc/gpl.txt for the license text.

#ifndef COOLFluiD_FluxReconstructionMethod_LLAVFluxReconstruction_hh
#define COOLFluiD_FluxReconstructionMethod_LLAVFluxReconstruction_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/BaseMethodStrategyProvider.hh"

#include "FluxReconstructionMethod/FluxReconstructionSolverData.hh"

#include "FluxReconstructionMethod/DiffRHSFluxReconstruction.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {
  namespace FluxReconstructionMethod {

//////////////////////////////////////////////////////////////////////////////

/// Command to add Localized Laplacian Artificial Viscosity near discontinuities
/// @author Ray Vandenhoeck
    
class LLAVFluxReconstruction : public DiffRHSFluxReconstruction {

public: // functions

  /// Constructor
  explicit LLAVFluxReconstruction(const std::string& name);

  /// Destructor
  virtual ~LLAVFluxReconstruction() {}

  /// Execute processing actions
  void execute();
  
  /**
   * Defines the Config Option's of this class
   * @param options a OptionList where to add the Option's
   */
  static void defineConfigOptions(Config::OptionList& options);
  
  /**
   * Configures the command.
   */
  virtual void configure ( Config::ConfigArgs& args );
  
  /**
   * Set up private data and data of the aggregated classes
   * in this command before processing phase
   */
  virtual void setup();

  /**
   * Unsetup private data
   */
  virtual void unsetup();
    
protected: //functions

  /// compute the interface flux
  void computeInterfaceFlxCorrection();
  
  /// compute the divergence of the discontinuous flux (-divFD+divhFD)
  void computeDivDiscontFlx(std::vector< RealVector >& residuals);
  
  /**
   * Set the data for the current face necessary to calculate FI
   */
  void setFaceData(CFuint faceID);
  
  /**
   * Set the data for the current cell necessary to calculate the residual update
   */
  void setCellData();
  
  /**
   * Compute the projected states on order P-1
   */
  void computeProjStates(std::vector< RealVector >& projStates);
  
  /**
   * Compute the artificial viscosity
   */
  void computeEpsilon();
  
  /**
   * Compute the reference artificial viscosity
   */
  void computeEpsilon0();
  
  /**
   * Compute the smoothness indicator
   */
  void computeSmoothness();
  
  /**
   * Store the computed artificial viscosity
   */
  void storeEpsilon();

protected: //data
  
  /// update variable set
  Common::SafePtr< Framework::ConvectiveVarSet > m_updateVarSet;
  
  /// order of the FR method
  CFuint m_order;
  
  /// transformation matrices to order P-1
  RealMatrix m_transformationMatrix;
  
  /// states projected on P-1
  std::vector< RealVector > m_statesPMinOne;
  
  /// artificial Viscosity
  CFreal m_epsilon;
  
  /// artificial Viscosity
  std::vector< CFreal > m_epsilonLR;
  
  /// reference artificial Viscosity
  CFreal m_epsilon0;
  
  /// reference smoothness
  CFreal m_s0;
  
  /// smoothness
  CFreal m_s;
  
  /// controlling parameter kappa
  CFreal m_kappa;
  
  /// average artificial viscosities in the nodes
  RealVector m_nodeEpsilons;
  
  /// average artificial viscosities in the elements
  RealVector m_cellEpsilons;
  
  /// vector containing pointers to the nodes in a cell
  std::vector< Framework::Node*  >* m_cellNodes;
  
  /// number of corner nodes for current element type
  CFuint m_nbrCornerNodes;
  
  private:

  /// Physical data temporary vector
  RealVector m_pData;
  
}; // class Solve

//////////////////////////////////////////////////////////////////////////////

  }  // namespace FluxReconstructionMethod
}  // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_FluxReconstructionMethod_LLAVFluxReconstruction_hh

