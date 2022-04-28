nitrogen --restore &
xrdb ~/.Xresources &
xset s off &
xset -dpms &
picom --vsync --backend glx --vsync-use-glfinis --glx-no-stencil --glx-no-rebind-pixmap --refresh-rate 60 --no-ewmh-fullscreen &
bash ~/scripts/.mouse_settings.sh &
kitty &
qtile start
