#include "utils.h"
#include "hwinit.h"
#include "lib/printk.h"
#include "display/video_fb.h"
#include "gpio.h"


int main(void) {
    u32 *lfb_base;

    nx_hwinit();
    display_init();
    // Set up Tegra home button GPIO
    gpio_config(GPIO_PORT_Y, GPIO_PIN_1, GPIO_MODE_GPIO);
  	gpio_output_enable(GPIO_PORT_Y, GPIO_PIN_1, GPIO_OUTPUT_DISABLE);
    // Set up volume button GPIO
    gpio_config(GPIO_PORT_X, GPIO_PIN_6, GPIO_MODE_GPIO);
    gpio_config(GPIO_PORT_X, GPIO_PIN_7, GPIO_MODE_GPIO);
    gpio_output_enable(GPIO_PORT_X, GPIO_PIN_6, GPIO_OUTPUT_DISABLE);
    gpio_output_enable(GPIO_PORT_X, GPIO_PIN_7, GPIO_OUTPUT_DISABLE);
    // Set up the display, and register it as a printk provider.
    lfb_base = display_init_framebuffer();
    video_init(lfb_base);

    // Say hello.
    printk("[buttontest]  \n");
    printk("github.com/ejj28/buttontest \n");
    printk("Based on JigTester, Atmosphere's fusee, and hekate \n");

    while(true) {
      if (!gpio_read(GPIO_PORT_Y, GPIO_PIN_1)) {
        printk("\rHome [#] | ");
      } else {
        printk("\rHome [ ] | ");
      }
      if (!gpio_read(GPIO_PORT_X, GPIO_PIN_6)) {
        printk("Vol+ [#] | ");
      } else {
        printk("Vol+ [ ] | ");
      }
      if (!gpio_read(GPIO_PORT_X, GPIO_PIN_7)) {
        printk("Vol- [#]");
      } else {
        printk("Vol- [ ]");
      }
    }

    /* Do nothing for now */
    return 0;
}
