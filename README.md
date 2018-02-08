# arduino-hid-kerbal-controller

Arduino Uno can work as a HID device (Keyboard) with the appropiate firmware. This work is inspired by [mitchtech's project](http://mitchtech.net/arduino-usb-hid-keyboard/) 

Arduino Uno cannot emulate a HID device from default (leonardo and micro can) but we can reflash it with a special firmware.

To flash any firmware to the device we need to put it on DFU mode. For this, we need to instant short-circuit the closest 2 pins from the 6-group pins near the usb port. Once it is done the advertised serial port has to disappear from the computer.
The tool we will use to flash the Arduino is called dfu-programmer and can be obtained via apt (Linux) or brew (Macosx).
It is important to say that the sketch has to be already uploaded to the Arduino before flashing the keyboard firmware.

#### Erase and re-flash keyboard firmware

Once in DFU mode, we will flash the device with the keyboard firmware:
```
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash --debug 1 Arduino-keyboard-0.3.hex
sudo dfu-programmer atmega16u2 reset
```
After that we must disconnect the device and reconnect again, and it will be detected as a HID device.

#### Erase and re-flash current firmware (test, also reset for loading new code)

The thing is that when it's acting as a HID it isn't advertised as a Serial device anymore, so no more sketches cannot be uploaded to it. TO be able to upload new code to the Arduino we need to reflash it with the original firmware. We need to put it in DFU mode and execute the next commands:

```
sudo dfu-programmer atmega16u2 erase
sudo dfu-programmer atmega16u2 flash --debug 1 Arduino-usbserial-uno.hex
sudo dfu-programmer atmega16u2 reset
```
And unplug/plug the device again.

As for the wiring, the project is very simple. It's just a push butthon attached to a pin.

![alt text](https://github.com/stealthizer/raw/master/images/Kerbal.png "Arduino Kerbal Controller")