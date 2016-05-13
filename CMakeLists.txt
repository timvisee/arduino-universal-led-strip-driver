##############################################################################
# Copyright (c) UniversalLedStripDriver 2016. All rights reserved.           #
#                                                                            #
# @author Tim Visee                                                          #
# @website http://timvisee.com/                                              #
#                                                                            #
# Open Source != No Copyright                                                #
#                                                                            #
# Permission is hereby granted, free of charge, to any person obtaining a    #
# copy of this software and associated documentation files (the "Software"), #
# to deal in the Software without restriction, including without limitation  #
# the rights to use, copy, modify, merge, publish, distribute, sublicense,   #
# and/or sell copies of the Software, and to permit persons to whom the      #
# Software is furnished to do so, subject to the following conditions:       #
#                                                                            #
# The above copyright notice and this permission notice shall be included    #
# in all copies or substantial portions of the Software.                     #
#                                                                            #
# You should have received a copy of The MIT License (MIT) along with this   #
# program. If not, see <http://opensource.org/licenses/MIT/>.                #
##############################################################################

##############################################################################
# Customized CMake lists file based on CMake lists file packed with the IDEA #
# Arduino plugin.                                                            #
#                                                                            #
# This customized CMake lists file brings various useful improvements:       #
#  - Automatically import project files (when used)                          #
#  - Automatically import and link installed Arduino libraries (when used)   #
#  - Streamline build and upload process to Arduino                          #
#                                                                            #
# @author       Tim Visee                                                    #
# @website      http://timvisee.com/                                         #
# @version      0.2.1                                                        #
# @copyright    Copyright (c) Tim Visee. All rights reserved.                #
##############################################################################

cmake_minimum_required(VERSION 2.8.4)
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_SOURCE_DIR}/cmake/ArduinoToolchain.cmake)
# Project name
set(PROJECT_NAME ArduinoUniversalLedStripDriver)
project(${PROJECT_NAME})

# Arduino board type
set(${CMAKE_PROJECT_NAME}_BOARD uno)
# COM port to upload the sketch to
set(${CMAKE_PROJECT_NAME}_PORT COM21)

# File name of the main sketch file
set(${CMAKE_PROJECT_NAME}_SKETCH ArduinoUniversalLedStripDriver.ino)
generate_arduino_firmware(${CMAKE_PROJECT_NAME})
