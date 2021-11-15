#!/bin/bash

if [ -z "$1" ]
then 
	activity=94
	volume=10867
	manufacture_date=$(date +%s -d 200516)
	printf "No values entered. \nUsing default values for computing ROI.\nManufacturing date is 16/05/2020\n\n"
fi

#activity=$2
#volume=$3

# Today's date in seconds
current_date=$(date +%s -d $(date "+%y%m%d"))

# Source manufacturing date in seconds
#manufacture_date=$(date +%s -d $1)

# Number of days between today and the source's manufacturing day
day_diff=$(( $(( current_date - manufacture_date )) / 86400 )) 

# The computed ROI 
computed_roi=$(echo "( e(-$day_diff / 390.7 ) * 1000 * $activity ) / $volume" | bc -l)

echo "Number of days between today and the source's manufacturing date = $day_diff days"
echo "The activity used = $activity MBq"
echo "The volume used = $volume ml"
printf "\nThe computed ROI is $computed_roi MBq\n"

