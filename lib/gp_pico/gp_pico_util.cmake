#
# gp-pico-template
# Copyright © 2024, Greg PFISTER. MIT License.
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the “Software”), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.
#

# Get current commit
execute_process(
        COMMAND git log -1 --format=%h
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GP_GIT_COMMIT_HASH
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
if (NOT ${GP_GIT_COMMIT_HASH} STREQUAL "")
    add_definitions("-DGP_GIT_COMMIT_HASH=\"${GP_GIT_COMMIT_HASH}\"")
    message("Found commit hash: ${GP_GIT_COMMIT_HASH}")
endif ()

# Get current tag
execute_process(
        COMMAND git tag --points-at HEAD
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        OUTPUT_VARIABLE GP_GIT_COMMIT_TAG
        OUTPUT_STRIP_TRAILING_WHITESPACE
)
if (NOT ${GP_GIT_COMMIT_TAG} STREQUAL "")
    add_definitions("-DGP_GIT_COMMIT_TAG=\"${GP_GIT_COMMIT_TAG}\"")
    message("Found commit tag: ${GP_GIT_COMMIT_TAG}")
endif ()

# Process version
if (EXISTS ${CMAKE_SOURCE_DIR}/gp_pico_version.json)
    file(READ ${CMAKE_SOURCE_DIR}/gp_pico_version.json GH_JSON_VERSION)
    string(JSON GP_MAJOR_VERSION GET ${GH_JSON_VERSION} "major")
    string(JSON GP_MINOR_VERSION GET ${GH_JSON_VERSION} "minor")
    string(JSON GP_PATCH_VERSION GET ${GH_JSON_VERSION} "patch")
    string(JSON GP_BUILD_NUMBER GET ${GH_JSON_VERSION} "buildNumber")
    if ((NOT ${GP_MAJOR_VERSION} STREQUAL "") AND (NOT ${GP_MINOR_VERSION} STREQUAL "") AND (NOT ${GP_PATCH_VERSION}
            STREQUAL "") AND (NOT ${GP_BUILD_NUMBER} STREQUAL ""))
        add_definitions("-DGP_MAJOR_VERSION=\"${GP_MAJOR_VERSION}\"")
        add_definitions("-DGP_MINOR_VERSION=\"${GP_MINOR_VERSION}\"")
        add_definitions("-DGP_PATCH_VERSION=\"${GP_PATCH_VERSION}\"")
        add_definitions("-DGP_BUILD_NUMBER=\"${GP_BUILD_NUMBER}\"")
        message("Found version: ${GP_MAJOR_VERSION}.${GP_MINOR_VERSION}.${GP_PATCH_VERSION}+${GP_BUILD_NUMBER}")
    endif ()
endif ()