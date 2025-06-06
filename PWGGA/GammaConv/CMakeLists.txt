# **************************************************************************
# * Copyright(c) 1998-2014, ALICE Experiment at CERN, All rights reserved. *
# *                                                                        *
# * Author: The ALICE Off-line Project.                                    *
# * Contributors are mentioned in the code where appropriate.              *
# *                                                                        *
# * Permission to use, copy, modify and distribute this software and its   *
# * documentation strictly for non-commercial purposes is hereby granted   *
# * without fee, provided that the above copyright notice appears in all   *
# * copies and that both the copyright notice and this permission notice   *
# * appear in the supporting documentation. The authors make no claims     *
# * about the suitability of this software for any purpose. It is          *
# * provided "as is" without express or implied warranty.                  *
# **************************************************************************

# Module
set(MODULE PWGGAGammaConv)
add_definitions(-D_MODULE_="${MODULE}")

# Module include folder
include_directories(${AliPhysics_SOURCE_DIR}/PWGGA/GammaConv)

# Additional include folders in alphabetical order except ROOT
include_directories(${ROOT_INCLUDE_DIRS}
                    ${AliPhysics_SOURCE_DIR}/ML
       		    ${AliPhysics_SOURCE_DIR}/OADB
                    ${AliPhysics_SOURCE_DIR}/PWGCF/FLOW/Tasks # what target here
                    ${AliPhysics_SOURCE_DIR}/PWG/EMCAL/EMCALbase
                    ${AliPhysics_SOURCE_DIR}/PWG/EMCAL/EMCALtasks
                    ${AliPhysics_SOURCE_DIR}/PWG/EMCAL/EMCALtrigger
                    ${AliPhysics_SOURCE_DIR}/PWG/CaloTrackCorrBase
                    ${AliPhysics_SOURCE_DIR}/PWG/Cocktail
                    ${AliPhysics_SOURCE_DIR}/PWG/FLOW
                    ${AliPhysics_SOURCE_DIR}/PWG/JETFW
                    ${AliPhysics_SOURCE_DIR}/PWG/Tools
                    ${AliPhysics_SOURCE_DIR}/PWG/TRD
                    ${AliPhysics_SOURCE_DIR}/PWGJE/EMCALJetTasks
                    ${AliPhysics_SOURCE_DIR}/TENDER/Tender
                    ${AliPhysics_SOURCE_DIR}/TENDER/TenderSupplies
                    ${AliPhysics_SOURCE_DIR}/PWGGA/PHOSTasks/PHOS_PbPb
                    ${AliPhysics_SOURCE_DIR}/PWGGA/PWGGAUtils
                    ${AliPhysics_SOURCE_DIR}/PWGGA/GammaConvBase
                    ${AliPhysics_SOURCE_DIR}/PWGGA/Common
                   )

# Sources in alphabetical order
set(SRCS
    #helper classes
    AliCutHandlerPCM.cxx
    AliIdentifiedPrimaryCuts.cxx
    AliIdentifiedPrimarySelector.cxx
    AliGammaConversionAODBGHandler.cxx
    AliAnalysisTaskJetOutlierRemoval.cxx
    # user tasks
    AliAnalysisTaskPi0v2.cxx
    AliAnalysisTaskConvJet.cxx
    AliConversionAodSkimTask.cxx
    AliAnalysisTaskGammaIsoTree.cxx
    AliAnalysisTaskGammaCaloMix.cxx
    AliAnalysisTaskGammaConvFlow.cxx
    # QA tasks
    AliAnalysisTaskConversionQA.cxx
    AliAnalysisTaskConversionTree.cxx
    AliAnalysisTaskClusterQA.cxx
    AliAnalysisTaskMaterial.cxx
    AliAnalysisTaskMaterialHistos.cxx
    AliAnalysisTaskResolution.cxx
    AliAnalysisTaskConvCaloTree.cxx
    AliAnalysisTaskQA.cxx
    AliAnalysisTaskGammaTriggerQA.cxx
    AliAnalysisTaskConvCaloCalibration.cxx
    AliAnalysisTaskTrackQA.cxx
    AliAnalysisTRDEfficiency.cxx
    AliAnalysisTaskElectronStudies.cxx
    # MC and cocktail tasks
    AliAnalysisTaskGammaCocktailMC.cxx
    AliAnalysisTaskHadronicCocktailMC.cxx
    AliAnalysisTaskOmegaMCStudies.cxx
    # main pion, eta and photon tasks
    AliAnalysisTaskGammaConvV1.cxx
    AliAnalysisTaskGammaConvDalitzV1.cxx
    AliAnalysisTaskGammaCaloMerged.cxx
    AliAnalysisTaskGammaCaloMergedML.cxx
    AliAnalysisTaskGammaConvCalo.cxx
    AliAnalysisTaskGammaCalo.cxx
    AliAnalysisTaskGammaCaloDalitzV1.cxx
    AliAnalysisTaskGammaConvCaloIso.cxx
    AliAnalysisTaskGammaCaloIso.cxx
    # heavier resonances
    AliAnalysisTaskOmegaToPiZeroGamma.cxx
    AliAnalysisTaskHeavyNeutralMesonToGG.cxx
    AliAnalysisTaskK0toPi0Pi0.cxx
    AliAnalysisTaskGammaConvDtrue.cxx
    AliAnalysisTaskSigmaPlToProtonPiZero.cxx
    AliAnalysisTaskSigmaPlToProtonPiZeroAOD.cxx
    AliAnalysisTaskEtaToPiPlPiMiGamma.cxx
    AliAnalysisTaskNeutralMesonToPiPlPiMiNeutralMeson.cxx 
    # meson jet correlation
    AliAnalysisTaskMesonJetCorrelation.cxx  
    AliAnalysisTaskCorrelationTree.cxx   
#     AliAnalysisTaskGCPartToPWG4Part.cxx
#     AliAnaConvCorrBase.cxx
#     AliAnaConvCorrPhoton.cxx
#     AliAnaConvCorrPion.cxx
#     AliAnaConvIsolation.cxx
    #ML class
    AliGammaMLResponse.cxx
    AliGammaMLResponseGammatoEPlusEMinus.cxx
    AliPrimaryPionCuts.cxx
    AliPrimaryPionSelector.cxx
#     AliConversionCutHandler.cxx
#     AliAnalysisTaskNeutralMesonToPiPlPiMiPiZero.cxx
#     AliAnalysisTaskdPhi.cxx
    #Flow
    AliAnalysisTaskPi0v2Calo.cxx
   )

# MC task that needs fastjet
if(FASTJET_FOUND)
   set(SRCS ${SRCS}
    AliAnalysisTaskGammaPureMC.cxx
   )
endif(FASTJET_FOUND)

# Headers from sources
string(REPLACE ".cxx" ".h" HDRS "${SRCS}")
set(HDRS ${HDRS})

# fastjet
if(FASTJET_FOUND)
    include_directories(${AliPhysics_SOURCE_DIR}/JETAN/JETAN)
    include_directories(SYSTEM ${FASTJET_INCLUDE_DIR})
    link_directories(${FASTJET_LIBS_DIR})
    add_definitions(${FASTJET_DEFINITIONS})
endif(FASTJET_FOUND)

# Generate the dictionary
# It will create G_ARG1.cxx and G_ARG1.h / ARG1 = function first argument
get_directory_property(incdirs INCLUDE_DIRECTORIES)
generate_dictionary("${MODULE}" "${MODULE}LinkDef.h" "${HDRS}" "${incdirs}" "${FASTJET_ROOTDICT_OPTS}")

set(ROOT_DEPENDENCIES Core EG GenVector Geom Gpad Hist MathCore Matrix Net Physics RIO Tree TMVA)
set(ALIROOT_DEPENDENCIES ANALYSIS ANALYSISalice AOD EMCALbase EMCALUtils ESD STEERBase PWGTRD PWGflowTasks Tender TenderSupplies PWGEMCALbase PWGEMCALtasks PWGEMCALtrigger PWGCaloTrackCorrBase PWGGAUtils PWGJETFW )
set(ALIPHYSICS_DEPENDENCIES ML PWGCocktail PWGGAGammaConvBase PWGEMCALtasks PWGEMCALbase PWGEMCALtrigger)

# Generate the ROOT map
# Dependecies
set(LIBDEPS ${ALIROOT_DEPENDENCIES} ${ALIPHYSICS_DEPENDENCIES} ${ROOT_DEPENDENCIES})

if(FASTJET_FOUND)
    set(ALIROOT_DEPENDENCIES JETAN ${ALIROOT_DEPENDENCIES})
endif(FASTJET_FOUND)

generate_rootmap("${MODULE}" "${LIBDEPS}" "${CMAKE_CURRENT_SOURCE_DIR}/${MODULE}LinkDef.h")

# Generate a PARfile target for this library
add_target_parfile(${MODULE} "${SRCS}" "${HDRS}" "${MODULE}LinkDef.h" "${LIBDEPS}")

# Create an object to be reused in case of static libraries
# Otherwise the sources will be compiled twice
add_library(${MODULE}-object OBJECT ${SRCS} G__${MODULE}.cxx)
# Add a library to the project using the object
add_library_tested(${MODULE} SHARED $<TARGET_OBJECTS:${MODULE}-object>)
target_link_libraries(${MODULE} ${ALIPHYSICS_DEPENDENCIES} ${ALIROOT_DEPENDENCIES} ${ROOT_DEPENDENCIES} ${FASTJET_LIBS})

# Setting the correct headers for the object as gathered from the dependencies
target_include_directories(${MODULE}-object PUBLIC $<TARGET_PROPERTY:${MODULE},INCLUDE_DIRECTORIES>)
set_target_properties(${MODULE}-object PROPERTIES COMPILE_DEFINITIONS $<TARGET_PROPERTY:${MODULE},COMPILE_DEFINITIONS>)

# Public include folders that will be propagated to the dependecies
target_include_directories(${MODULE} PUBLIC ${incdirs})

set(MODULE_COMPILE_FLAGS)
set(MODULE_LINK_FLAGS)

if(DATE_FOUND)
    set(MODULE_COMPILE_FLAGS "${DATE_CFLAGS}")
    set(MODULE_LINK_FLAGS "${DATE_LDFLAGS} ${DATE_LIBS}")
endif(DATE_FOUND)

# Additional compilation and linking flags
set(MODULE_COMPILE_FLAGS " ${MODULE_COMPILE_FLAGS}")

# System dependent: Modify the way the library is build
if(${CMAKE_SYSTEM} MATCHES Darwin)
    set(MODULE_LINK_FLAGS "-undefined dynamic_lookup ${MODULE_LINK_FLAGS}")
endif(${CMAKE_SYSTEM} MATCHES Darwin)

# Setting compilation flags for the object
set_target_properties(${MODULE}-object PROPERTIES COMPILE_FLAGS "${MODULE_COMPILE_FLAGS}")
# Setting the linking flags for the library
set_target_properties(${MODULE} PROPERTIES LINK_FLAGS "${MODULE_LINK_FLAGS}")

# Installation
install(TARGETS ${MODULE}
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES ${HDRS} DESTINATION include)

# install macros
install(DIRECTORY macros DESTINATION PWGGA/GammaConv)
