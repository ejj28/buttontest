#include "utils.h"
#include "hwinit.h"
#include "lib/printk.h"
#include "display/video_fb.h"
#include "gpio.h"


int main(void) {
    u32 *lfb_base;

    nx_hwinit();
    display_init();
    gpio_config(GPIO_PORT_Y, GPIO_PIN_1, GPIO_MODE_GPIO);
  	gpio_output_enable(GPIO_PORT_Y, GPIO_PIN_1, GPIO_OUTPUT_DISABLE);
    // Set up the display, and register it as a printk provider.
    lfb_base = display_init_framebuffer();
    video_init(lfb_base);

    // Say hello.
    printk("Welcome to Jig Tester! \n");
    printk("Based on fusee.bin and hekate \n");

    while(true) {
      if (!gpio_read(GPIO_PORT_Y, GPIO_PIN_1)) {
        printk("\r[Y] Home button is pressed                       ");
      } else {
        printk("\r[N] Home button is not pressed                   ");
      }
    }

    /* Do nothing for now */
    return 0;
}
