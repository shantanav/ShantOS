FROM ubuntu:latest AS builder

WORKDIR /os

COPY . .

RUN apt update
RUN apt install -y \
    mtools \
    build-essential \
    nasm \
    xorriso \
    grub-pc-bin

CMD ["make", "only-ShantOS"]