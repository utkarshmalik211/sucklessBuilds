#!/bin/bash

poweroff_command="sudo /sbin/halt"
reboot_command="sudo /sbin/reboot"
logout_command="pkill X"
hibernate_command="sudo s2disk"
suspend_command="sudo s2ram"

options=$'poweroff\nreboot\nlogout\nhibernate\nsuspend' 

# ... because the essential options (-dmenu and -p) are added here
eval \$"$(echo "$options" | dmenu )_command"
