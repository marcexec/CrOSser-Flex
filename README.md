# CrOSser-Flex
This complements https://github.com/marcexec/CrOSser by using the same techniques to automate a ChromeOS Flex installation onto e.g. an old laptop.

You will need to prepare a USB stick to boot ChromeOS Flex, see https://support.google.com/chromeosflex/answer/11552529.

## Updates
2023-10-25 V1.0.0 commit

## How it works
The Ardunio sketch basically just emulates timed key presses of a USB keyboard. The process is intended to start post booting from USB (might need to be enabled in BIOS).
The code should be easy to follow and adjust delays dependent on the hardware to be converted. This only makes sense if you are doing a batch of similar or identical devices.

Requires https://github.com/digistump/DigisparkArduinoIntegration/blob/master/libraries/DigisparkKeyboard/DigiKeyboard.h

## Getting Started
I have a full writeup, including the Arduino IDE setup on ChromeOS on the CitrixIE blog: https://citrixie.wordpress.com/2023/03/02/using-5-open-source-hardware-for-chromeos-enterprise-enrollment-and-chromeos-flex-installation/
