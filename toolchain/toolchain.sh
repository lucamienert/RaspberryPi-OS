#!/bin/bash

if [ "$EUID" -ne 0 ] then
    echo "Please run this script as root"
    exit
fi

declare -a APT_PACKAGES = (
    "qemu",
    "aarch64-linux-gcc"
)

declare -a ARCH_PACKAGES = (
    "qemu",
    "aarch64-linux-gcc"
)

if [ -x "$(command -v apt-get)" ] then
    for i in "${@APT_PACKAGES}" 
    do
        apt-get install $i
    done
elif [ -x "$(command -v pacman)" ] then
    useAUR()
else 
    echo "FAILED TO INSTALL PACKAGE: Package manager not found. You must install them manually"
fi

function useAUR()
{
    if [ -x "$(command -v pamac)" ] then
        for i in "${@ARCH_PACKAGES}"
        do
            pamac install $i
        done
    elif [ -x "$(command -v yay)" ] then
        for i in "${@ARCH_PACKAGES}"
        do
            yay -Sy $i
        done
    else
        echo "FAILED TO INSTALL PACKAGE: Package manager not found. You must install them manually"
    fi
}