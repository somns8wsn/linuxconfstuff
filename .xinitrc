xrdb ~/.Xresources &
xset s off &
xset -dpms &
picom --vsync --backend glx &
nitrogen --restore &
bash ~/.mouse_settings.sh &
kitty &
slstatus &
exec dwm
