FROM mcr.microsoft.com/devcontainers/cpp:1-ubuntu-22.04
ADD code.deb /tmp/code.deb
RUN apt update && \
        apt-get install --no-install-recommends -y ./tmp/code.deb
