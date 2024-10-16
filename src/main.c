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

#include "global.h"
#include "led.h"

#include <stdio.h>
#include "pico/stdlib.h"
#include "pico/time.h"

int main()
{
    int ret = 0;    // Return code
    int count = 0;  // Running count from 0 to 8 restarting at 0

    // Initialize output
    ret = stdio_init_all();
    hard_assert(ret == true);

    // Initialize led
    ret = pico_led_init();
    hard_assert(ret == PICO_OK);

    // Begin
    printf("\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("Template - Kickstart your Pico project\n");
    printf("Copyright © 2024, Greg PFISTER. MIT License.\n");
#if defined(GP_MAJOR_VERSION) && defined(GP_MINOR_VERSION) && defined(GP_PATCH_VERSION) && defined(GP_BUILD_NUMBER)
    printf("Version: v%s.%s.%s+%s\n", GP_MAJOR_VERSION, GP_MINOR_VERSION, GP_PATCH_VERSION, GP_BUILD_NUMBER);
#endif
    printf("Build date: %s at %s\n", __DATE__, __TIME__);
#ifdef GP_GIT_COMMIT_TAG
    printf("Commit tag: %s\n", GP_GIT_COMMIT_TAG);
#endif
#ifdef GP_GIT_COMMIT_HASH
    printf("Commit hash: %s\n", GP_GIT_COMMIT_HASH);
#endif
    printf("--------------------------------------------------------------------------------\n");
    printf("\n");

    // Main loop
    // ReSharper disable once CppDFAEndlessLoop
    while (1) {
        // Some debug
        printf("%10i ms: Blink !\n", to_ms_since_boot(get_absolute_time()));

        // Light up for 100ms
        pico_set_led(true);
        sleep_ms(LED_BLINK_DURATION_MS - (count * 10));

        // Light down from 900ms, then 800ms
        pico_set_led(false);
        sleep_ms(LED_DELAY_MS - (count * 100));

        count = (count + 1) % 9;
    }

    // ReSharper disable once CppDFAUnreachableCode
    return ret;
}
