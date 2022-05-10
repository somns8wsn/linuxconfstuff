#!/bin/bash
myrepo="git@github.com:somns8wsn/"

for i in ../source/wsn_std_pkgs.list
	do apt-get install -yy $i
done

for list in owndwmbuild ownstbuild owndmenubuild ownslstatusbuild
	do git clone $myrepo$list".git"
done

sh -c "$(curl -fsSL https://starship.rs/install.sh)"

printf "$USER      ALL=(ALL:ALL) ALL" >> /etc/sudoers

sudo systemctl enable --now cups
sudo usermod -aG lpadmin $USER


# pull packages, chose menu for decide which list to install
# setup printer
# setup qemu
# softlink .config to /root/directory
# contrib and non-free to sources.list
# 
#
#
#
