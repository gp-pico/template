//
// gp-pico-template
// Copyright © 2024, Greg PFISTER. MIT License.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gp_get_version(char **version)
{
#if defined(GP_MAJOR_VERSION) && defined(GP_MINOR_VERSION) && defined(GP_PATCH_VERSION) && defined(GP_BUILD_NUMBER)
    const char *major = GP_MAJOR_VERSION;
    const char *minor = GP_MINOR_VERSION;
    const char *patch = GP_PATCH_VERSION;
    const char *build_number = GP_BUILD_NUMBER;
    *version = malloc((strlen(major) + strlen(minor) + strlen(patch) + strlen(build_number) + 4) * sizeof(char));
    sprintf(*version, "%s.%s.%s+%s", GP_MAJOR_VERSION, GP_MINOR_VERSION, GP_PATCH_VERSION, GP_BUILD_NUMBER);
#else
    *version = NULL;
#endif
}