sudo pacman -S --needed libx11 libxft libxinerama xclip scrot pipewire-pulse pamixer pavucontrol mpv bc dunst yt-dlp

#!/bin/bash
cd st && make && sudo make install && cd ..
cd dwm && make && sudo make install && cd ..
cd dmenu && make && sudo make install && cd ..
cd dwmblocks && make && sudo make install && cd ..
cd configFiles && ./install.sh && cd ..
cp bins/binFolder/* /usr/bin/.

