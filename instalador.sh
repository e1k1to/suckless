sudo pacman -S --needed xorg xorg-xinit libx11 libxft libxinerama xclip scrot pipewire-pulse pamixer pavucontrol mpv bc dunst yt-dlp feh xorg-setxkbmap libxrandr

#!/bin/bash
cd st && make && sudo make install && cd ..
cd dwm && make && sudo make install && cd ..
cd dmenu && make && sudo make install && cd ..
cd dwmblocks && make && sudo make install && cd ..
cd configFiles && ./install.sh && cd ..
cp bins/binFolder/* /usr/bin/.
mkdir /home/eiki/Pictures/
cp .adicionais/tuxx.png /home/eiki/Pictures/tuxx.png
