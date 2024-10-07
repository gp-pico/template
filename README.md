[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE.md)

# Template - Kickstart your Pico project

> Copyright © 2024, Greg PFISTER. MIT License.

## About

___

This is a template project that aim at been a kickstart for Pico projects.

It provides:

- A base project for Pico boards (RP2040 at the moment).
- Instructions to set `Clion`, `Visual Studio Code`, `neovim` and `emacs` IDE.
- Instructions to set the Pico SDK and the Toolchain.
- A dev container (to test build is similar conditions as in CI/CD)
- Actions for GitHub for build, unit test and release

### Roadmap of IDEA instructions

1. `Clion`
2. `Visual Studio Code`
3. `neovim`
4. `emacs`

### Roadmap of chip support

1. RP2040 single core
2. RP2040 dual core
3. RP2350 (arm, dual core)
4. RP2350 (risc, dual core)

## Getting started

___

### Clone and adjust the kickstarter repo

First clone this repo in your favorite development folder, remove git:

```shell
cd ~/Development                                  && \  
git clone https://github.com/gp-pico/template.git && \  
mv gp-pico-template my-project                    && \  
cd my-project                                     
rm -rf .git
```

Then, rename all instances of `gp-pico-template` to `my-project`, as well as all
instances of `gp_pico_template` to `my_executable`:

```shell
git grep -z -l 'gp-pico-template' | xargs -0 sed -i '' -e 's/gp-pico-template/my-project/g'    && \  
git grep -z -l 'gp_pico_template' | xargs -0 sed -i '' -e 's/gp_pico_template/my_executable/g'
```

You will need to get the SDK provided `pico_sdk_import.cmake` file:

```shell
cp /opt/rpi-pico/v2.0.0/pico-sdk/external/pico_sdk_import.cmake .
```

At that point, you may want to adjust `LICENSE.md`, `README.md`, ... before
initiating `git` and making the first commit.

```shell
git init
git add .
git commit -m "First commit"
```

### Build files from command line

First, create a build folder:

```shell
mkdir build && cd build
```

To build for the Pico (no Wi-Fi) board:

```shell
mkdir pico && cd pico                                            && \
export PICO_SDK_PATH=/opt/rpi-pico/v2.0.0/pico-sdk               && \
export PICO_EXTRAS_PATH=/opt/rpi-pico/v2.0.0/pico-extras         && \
export PICO_PLAYGROUND_PATH=/opt/rpi-pico/v2.0.0/pico-playground && \
cmake ../..                                                      && \
make -j 8
```

To build for the Pico Wi-Fi board:

```shell
mkdir pico_w && cd pico_w                                        && \
export PICO_SDK_PATH=/opt/rpi-pico/v2.0.0/pico-sdk               && \
export PICO_EXTRAS_PATH=/opt/rpi-pico/v2.0.0/pico-extras         && \
export PICO_PLAYGROUND_PATH=/opt/rpi-pico/v2.0.0/pico-playground && \
cmake -DPICO_BOARD=pico_w ../..                                  && \
make -j 8
```

To build for the Pico 2 (no Wi-Fi) board:

```shell
mkdir pico2 && cd pico2                                          && \
export PICO_SDK_PATH=/opt/rpi-pico/v2.0.0/pico-sdk               && \
export PICO_EXTRAS_PATH=/opt/rpi-pico/v2.0.0/pico-extras         && \
export PICO_PLAYGROUND_PATH=/opt/rpi-pico/v2.0.0/pico-playground && \
cmake -DPICO_BOARD=pico2 ../..                                   && \
make -j 8
```

## SDK installation

___

Detailed instrutions can be found here [docs/sdk/README.md](docs/sdk/README.md).

## IDE setup

___

Here are steps to set up various IDE in order to develop for this project.

### `Clion setup`

See [doc/clion/README.md](docs/clion/README.md).

### `Visual Studio Code setup`

See [doc/vscode/README.md](docs/vscode/README.md).

### `neovim` setup

See [doc/neovim/README.md](docs/neovim/README.md).

### `emacs` setup

See [doc/emacs/README.md](docs/emacs/README.md).

## CI/CD support

___

### Dev container

A dev container is provided, which can serve to test locally the CI/CD actions
by reproducing the different steps inside.

### GitHub actions

GitHub actions can be found in the `.github/workflows` folder. There are two
triggered actions:

- pull_request.yaml, which is triggered when a PR is submitted;
- release.yaml, which is triggered when a release is published.

These actions will use the following _sub-actions_:

- build.yaml: Builds and cache the build result for a given board;
- test.yaml: Runs unit tests (it requires the build cached by build.yaml);
- publish.yaml: Publish the build code zipped along with the release version
  (it requires the build cached by build.yaml).

## Contribution

___

Contributions are welcome. Please refer to the [code of conduct](./CODE_OF_CONDUCT.md).

## License

___

For more details, please read the [license](./LICENSE.md) terms.
