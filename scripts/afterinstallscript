#!/bin/bash
myrepo="git@github.com:somns8wsn/"

for i in vim wget vifm s-tui stress ncdu sudo locate curl alsa-utils nasm gcc xorg htop tree moc mpv sxiv zathura exa picom nitrogen obs-studio firefox-esr lxappearance lynx w3m python3 python3-pip qt5ct keepass2 qbittorrent remmina pcmanfm virt-manager fdisk mumble filezilla inkscape fish wireguard openssh gimp vlc
do apt-get install -yy $i
done

for list in owndwmbuild ownstbuild owndmenubuild ownslstatusbuild
do git clone $myrepo$list".git"
done

cd /home/$USER/ownstbuild && make clean install && cd /home/$USER
cd /home/$USER/owndwmbuild && make clean install && cd /home/$USER
cd /home/$USER/owndmenubuild && make clean install && cd /home/$USER
cd /home/$USER/ownslstatusbuild && make clean install && cd /home/$USER

sh -c "$(curl -fsSL https://starship.rs/install.sh)"

printf "$USER      ALL=(ALL:ALL) ALL" >> /etc/sudoers

