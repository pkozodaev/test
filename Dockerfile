FROM alpine:3.14

RUN apk update \
  && apk upgrade \
  && apk add --no-cache \
    clang \
    clang-dev \
    alpine-sdk \
    cmake \
    musl-dev \
    lld \
    compiler-rt \
    compiler-rt-static \
    lldb \
    vim \ 
    git \
    make \
  && apk del alpine-sdk \
    gcc
