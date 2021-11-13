#!/bin/bash

# Today's date in seconds
current_date=$(date +%s -d $(date "+%y%m%d"))

# Source manufacturing date in seconds
manufacture_date=$(date +%s -d $1)

day_diff=$(( $(( current_date - manufacture_date )) / 86400 )) 

echo $current_date
echo $manufacture_date
echo $day_diff
