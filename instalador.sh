sudo pacman -S --needed xorg xorg-xinit libx11 libxft libxinerama xclip scrot pipewire-pulse pamixer pavucontrol mpv bc dunst yt-dlp feh xorg-setxkbmap libxrandr pacman-contrib noto-fonts nofo-fonts-cjk noto-fonts-emoji ttf-liberation ttf-anonymous-pro

#!/bin/bash
cd st && make && sudo make install && cd ..
cd dwm && make && sudo make install && cd ..
cd dmenu && make && sudo make install && cd ..
cd dwmblocks && make && sudo make install && cd ..
cd configFiles && ./install.sh && cd ..
sudo cp bins/binFolder/* /bin/.
mkdir /home/eiki/Pictures/
cp $(pwd)/adfiles/tuxx.png /home/eiki/Pictures/tuxx.png
