LIST ( APPEND FluxReconstructionSA_files
FluxReconstructionSA.hh
SA2DSourceTerm.hh
SA2DSourceTerm.cxx
)

LIST ( APPEND FluxReconstructionSA_cflibs FluxReconstructionMethod FluxReconstructionNavierStokes NavierStokes SA )
LIST ( APPEND FluxReconstructionSA_requires_mods FluxReconstructionMethod FluxReconstructionNavierStokes NavierStokes SA )

LIST ( APPEND FluxReconstructionKOmega_files
FluxReconstructionKOmega.hh
KOmega2DSourceTerm.hh
KOmega2DSourceTerm.cxx
KLogOmega2DSourceTerm.hh
KLogOmega2DSourceTerm.cxx
)

LIST ( APPEND FluxReconstructionKOmega_cflibs FluxReconstructionMethod FluxReconstructionNavierStokes NavierStokes KOmega )
LIST ( APPEND FluxReconstructionKOmega_requires_mods FluxReconstructionMethod FluxReconstructionNavierStokes NavierStokes KOmega )

LIST ( APPEND FluxReconstructionGReKO_files
FluxReconstructionGReKO.hh
NavierStokesGReKO2DSourceTerm_Lang.hh
NavierStokesGReKO2DSourceTerm_Lang.cxx
)

LIST ( APPEND FluxReconstructionGReKO_cflibs NavierStokes GReKO FluxReconstructionMethod FluxReconstructionNavierStokes FluxReconstructionKOmega )
LIST ( APPEND FluxReconstructionGReKO_requires_mods NavierStokes GReKO FluxReconstructionMethod FluxReconstructionNavierStokes FluxReconstructionKOmega )

CF_ADD_PLUGIN_LIBRARY ( FluxReconstructionSA )
CF_ADD_PLUGIN_LIBRARY ( FluxReconstructionKOmega )
CF_ADD_PLUGIN_LIBRARY ( FluxReconstructionGReKO )
CF_WARN_ORPHAN_FILES()
