FROM ubuntu:18.04
SHELL ["/bin/bash", "-c"]

# Set timezone
ARG DEBIAN_FRONTEND=noninteractive
ENV TZ=Europe/Rome

# Update system
RUN apt-get update && apt-get upgrade -y

# Install dependencies
RUN apt-get install vim git build-essential cmake autoconf automake curl autotools-dev python3-pip \
    libmpc-dev libmpfr-dev libgmp-dev gawk bison flex texinfo gperf libtool patchutils bc zlib1g-dev libftdi-dev \
    libftdi1 doxygen libsdl2-dev libusb-1.0-0-dev scons gtkwave libsndfile1-dev rsync pkg-config libsdl2-ttf-dev -y

# 1. Install Pulp-RISCV toolchain
ENV PATH="/opt/riscv/bin:${PATH}"
RUN git clone --recursive https://github.com/pulp-platform/pulp-riscv-gnu-toolchain.git && \
    cd pulp-riscv-gnu-toolchain && \
    ./configure --prefix=/opt/riscv --with-arch=rv32imc --with-cmodel=medlow --enable-multilib && \
    make && cd .. && rm -r pulp-riscv-gnu-toolchain

# 2. Install Pulp SDK
RUN pip3 install argcomplete pyelftools
ENV PULP_RISCV_GCC_TOOLCHAIN="/opt/riscv"
RUN mkdir -p /pulp/sdk && cd /pulp/sdk && \
    git clone https://github.com/pulp-platform/pulp-sdk.git . && \
    source configs/pulp-open.sh && \
    make build

# Set working directory
RUN mkdir /pulp/workspace
WORKDIR /pulp/workspace

CMD source /pulp/sdk/configs/pulp-open.sh && exec /bin/bash
