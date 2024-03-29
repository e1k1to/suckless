sudo pacman -S --needed xorg xorg-xinit libx11 libxft libxinerama xclip scrot pipewire-pulse pamixer pavucontrol mpv bc dunst yt-dlp feh xorg-setxkbmap libxrandr pacman-contrib noto-fonts noto-fonts-cjk noto-fonts-emoji ttf-liberation ttf-anonymous-pro webkit2gtk gcr gst-plugins-good gst-libav

#!/bin/bash
cd st           && make && sudo make install && cd ..
cd slock        && make && sudo make install && cd ..
cd dwm          && make && sudo make install && cd ..
cd dmenu        && make && sudo make install && cd ..
cd slstatus     && make && sudo make install && cd ..
cd surf         && make && sudo make install && cd ..
mkdir ~/.config/
cp -r configFiles/* ~/.config/
sudo cp bins/binFolder/* /bin/.
mkdir ~/Pictures/
cp adfiles/tuxx.png ~/Pictures/tuxx.png
