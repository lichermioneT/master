# Install script for directory: /home/lic/orb/eigen-3.2.10/Eigen/src/Core

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
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/Eigen/src/Core" TYPE FILE FILES
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Array.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/ArrayBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/ArrayWrapper.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Assign.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Assign_MKL.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/BandMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Block.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/BooleanRedux.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CommaInitializer.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CoreIterators.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CwiseBinaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CwiseNullaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CwiseUnaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/CwiseUnaryView.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/DenseBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/DenseCoeffsBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/DenseStorage.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Diagonal.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/DiagonalMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/DiagonalProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Dot.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/EigenBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Flagged.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/ForceAlignedAccess.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Functors.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Fuzzy.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/GeneralProduct.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/GenericPacketMath.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/GlobalFunctions.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/IO.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Map.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/MapBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/MathFunctions.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Matrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/MatrixBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/NestByValue.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/NoAlias.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/NumTraits.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/PermutationMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/PlainObjectBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/ProductBase.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Random.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Redux.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Ref.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Replicate.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/ReturnByValue.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Reverse.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Select.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/SelfAdjointView.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/SelfCwiseBinaryOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/SolveTriangular.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/StableNorm.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Stride.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Swap.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Transpose.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Transpositions.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/TriangularMatrix.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/VectorBlock.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/VectorwiseOp.h"
    "/home/lic/orb/eigen-3.2.10/Eigen/src/Core/Visitor.h"
    )
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/lic/orb/eigen-3.2.10/build/Eigen/src/Core/products/cmake_install.cmake")
  include("/home/lic/orb/eigen-3.2.10/build/Eigen/src/Core/util/cmake_install.cmake")
  include("/home/lic/orb/eigen-3.2.10/build/Eigen/src/Core/arch/cmake_install.cmake")

endif()

