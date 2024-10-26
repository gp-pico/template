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

#include "test_git.h"

#include <cstddef>
#include <cmocka.h>
#include "gp_pico.h"

static void gp_test_commit_hash_str(void **state)
{
    (void)state;
}

static void gp_test_commit_tag_str(void **state)
{
    (void)state;
}

int test_git()
{
    constexpr struct CMUnitTest tests[] = {
        cmocka_unit_test(gp_test_commit_hash_str),
        cmocka_unit_test(gp_test_commit_tag_str),
    };
    return cmocka_run_group_tests(tests, nullptr, nullptr);
}
