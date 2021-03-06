#ifndef COOLFluiD_Physics_NavierStokes_Euler2DConsToRoeInPuvt_hh
#define COOLFluiD_Physics_NavierStokes_Euler2DConsToRoeInPuvt_hh

//////////////////////////////////////////////////////////////////////////////

#include "Framework/VarSetMatrixTransformer.hh"

//////////////////////////////////////////////////////////////////////////////

namespace COOLFluiD {

  namespace Physics {

    namespace NavierStokes {

      class EulerTerm;

//////////////////////////////////////////////////////////////////////////////

/**
 * This class represents a matrix transformer of variables from
 * conservative to Roe starting from primitive variables
 *
 * @author Andrea Lani
 *
 */
class Euler2DConsToRoeInPuvt : public Framework::VarSetMatrixTransformer {
public:

  /**
   * Default constructor without arguments
   */
  Euler2DConsToRoeInPuvt(Common::SafePtr<Framework::PhysicalModelImpl> model);

  /**
   * Default destructor
   */
  ~Euler2DConsToRoeInPuvt();

  /**
    * Set the transformation matrix from a given state
    */
  void setMatrix(const RealVector& state);

private:

  /**
   * Set the flag telling if the transformation is an identity one
   * @pre this method must be called during set up
   */
  bool getIsIdentityTransformation() const
  {
    return false;
  }

private: //data

  /// acquaintance of the PhysicalModel
  Common::SafePtr<EulerTerm> _model;

}; // end of class Euler2DConsToRoeInPuvt

//////////////////////////////////////////////////////////////////////////////

    } // namespace NavierStokes

  } // namespace Physics

} // namespace COOLFluiD

//////////////////////////////////////////////////////////////////////////////

#endif // COOLFluiD_Physics_NavierStokes_Euler2DConsToRoeInPuvt_hh
