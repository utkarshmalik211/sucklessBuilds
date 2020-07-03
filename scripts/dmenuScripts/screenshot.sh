#!/bin/bash

Fullscreen_command="scrot '~/images/screenshots/%Y-%m-%d_\$wx\$h_scrot.png'"
SelectArea_command="scrot --select  '~/images/screenshots/%Y-%m-%d_\$wx\$h_scrot.png'"

options=$'Fullscreen\nSelectArea' 

# ... because the essential options (-dmenu and -p) are added here
eval \$"$(echo "$options" | dmenu -l 20 -p "Choose Screenshot Type")_command"
