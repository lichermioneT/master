# CMake generated Testfile for 
# Source directory: /home/lic/orb/opencv-3.4.16/modules/viz
# Build directory: /home/lic/orb/opencv-3.4.16/build/modules/viz
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(opencv_test_viz "/home/lic/orb/opencv-3.4.16/build/bin/opencv_test_viz" "--gtest_output=xml:opencv_test_viz.xml")
set_tests_properties(opencv_test_viz PROPERTIES  LABELS "Main;opencv_viz;Accuracy" WORKING_DIRECTORY "/home/lic/orb/opencv-3.4.16/build/test-reports/accuracy" _BACKTRACE_TRIPLES "/home/lic/orb/opencv-3.4.16/cmake/OpenCVUtils.cmake;1686;add_test;/home/lic/orb/opencv-3.4.16/cmake/OpenCVModule.cmake;1292;ocv_add_test_from_target;/home/lic/orb/opencv-3.4.16/cmake/OpenCVModule.cmake;1074;ocv_add_accuracy_tests;/home/lic/orb/opencv-3.4.16/modules/viz/CMakeLists.txt;29;ocv_define_module;/home/lic/orb/opencv-3.4.16/modules/viz/CMakeLists.txt;0;")
