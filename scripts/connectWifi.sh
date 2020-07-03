#!/bin/bash
wpa_supplicant -B -i wlo1 -c /home/utkarsh/scripts/wifi/maliks.conf -D nl80211
dhcpcd
