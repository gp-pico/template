# SDK installation

## About

The SDK will be stored with the following structure:

```
/opt/rpi-pico
└── <VERSION vX.Y.Z>
    ├── pico-examples
    ├── pico-extras
    ├── pico-playground
    ├── pico-sdk
    └── picotool (only on Linux)
```

## SDK v2.0.0

The following instructions will install the Pico SDK v2.0.0 on _Mac_ or _Linux_.

Refer to the [getting started](https://datasheets.raspberrypi.com/pico/getting-started-with-pico.pdf)
documentations to install dependencies (cmake, ...) or adjust for _Windows_.

### Requirements

The following requirements must be fulfilled prior to installing the `pico-sdk`
and `picotool`:

- Mac:
    - Run `brew install cmake ninja`
    - Download and install [Arm GNU Toolchain](https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads)
- Linux (Ubuntu/Debian):
    - Run `sudo apt install build-essential cmake git g++ 
      gcc-arm-none-eabi libnewlib-arm-none-eabi libstdc++-arm-none-eabi-newlib 
      libusb-1.0-0-dev`
- Linux (Arch): _Not yet available_

### Installation

First create a folder on `/opt`:

```shell
sudo mkdir /opt/rpi-pico
sudo chown $USER:staff /opt/rpi-pico # Adjust group to you machine
mdkir /opt/rpi-pico/v2.0.0
```

Now clone the `pico-sdk`:

```shell
cd /opt/rpi-pico/v2.0.0
git clone --recursive https://github.com/raspberrypi/pico-sdk.git -b 2.0.0            && \  
git clone --recursive https://github.com/raspberrypi/pico-extras.git -b sdk-2.0.0     && \  
git clone --recursive https://github.com/raspberrypi/pico-examples.git -b sdk-2.0.0   && \  
git clone --recursive https://github.com/raspberrypi/pico-playground.git -b sdk-2.0.0 && \  
git clone --recursive https://github.com/raspberrypi/picotool.git -b 2.0.0
```

Clone, build and install the `picotool` on Linux:

```shell
cd /opt/rpi-pico/v2.0.0/picotool                     && \  
mkdir build &&                                       && \
PICO_SDK_PATH=/opt/rpi-pico/v2.0.0/pico-sdk cmake .. && \
make -j 8 && make install
```

On Mac, simply run `brew install picotool`.

### Docker image

A docker image is available
at [ghcr.io/gp-devenv/gp-pico-devenv](https://github.com/gp-devenv/gp-pico-devenv/pkgs/container/gp-pico-devenv).
