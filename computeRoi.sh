#!/bin/bash

activity=$2
volume=$3

# Today's date in seconds
current_date=$(date +%s -d $(date "+%y%m%d"))

# Source manufacturing date in seconds
manufacture_date=$(date +%s -d $1)

# Number of days between today and the source's manufacturing day
day_diff=$(( $(( current_date - manufacture_date )) / 86400 )) 

# The computed ROI 
computed_roi=$(echo "( e(390.7 / $day_diff) * 1000 * $activity ) / $volume" | bc -l)

echo "Number of days between today and the source's manufacturing day = $day_diff days"
echo "The activity used = $activity MBq"
echo "The volume used = $volume ml"
printf "\nThe computed ROI is $computed_roi MBq\n"

