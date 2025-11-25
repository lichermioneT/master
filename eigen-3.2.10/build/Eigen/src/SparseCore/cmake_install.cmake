# Install script for directory: /home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xDevelx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/SparseCore" TYPE FILE FILES
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/AmbiVector.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/CompressedStorage.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/ConservativeSparseSparseProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/MappedSparseMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseBlock.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseColEtree.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseCwiseBinaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseCwiseUnaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseDenseProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseDiagonalProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseDot.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseFuzzy.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseMatrixBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparsePermutation.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseRedux.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseSelfAdjointView.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseSparseProductWithPruning.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseTranspose.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseTriangularView.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseUtil.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseVector.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/SparseView.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/SparseCore/TriangularSolver.h"
    )
endif()

