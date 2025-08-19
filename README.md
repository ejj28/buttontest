# buttontest

![License](https://img.shields.io/badge/License-GPLv2-blue.svg)

buttontest is an RCM payload for testing the hardware buttons on the Nintendo Switch

buttontest is based on [JigTester](https://github.com/LucaCorigliano/JigTester) which is in turn based on the early [Atmosphère-NX PoC](https://github.com/ktemkin-archive/Atmosphere)


### Changes made in buttontest:
- Removed unused exosphere code from repo
- GPIO X-6 & X-7 detection in main.c

### Changes made in [JigTester](https://github.com/LucaCorigliano/JigTester):
- gpio.c / gpio.h / t210.h / types.h from Hekate IPL (https://github.com/nwert/hekate)
- GPIO Y-1 detection in main.c