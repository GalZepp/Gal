#!/bin/bash

# Helps flag for the script
if [ "$1" == '-h' ] || [ "$1" == '--help' ]; then
	printf "This is a script for calculating ROIs.\nIf you do not enter any values, the ROI will be calculated according to a set of default values.\nYou can enter values in the following format: \ncomputeRoi.sh Date(yymmdd) Avtivity Volume.\nFor example: computeRoi.sh 200516 94 10678\nThe date in the example is 16-May-2020\n"
	exit
fi 

# Send to help
send_help="For more information on how to use the script, use -h or --help flags.\n"

# The if statement checks the amount of arguments entered
if [ $# -eq 0 ]; then 
	# Default values of source
	activity=94
	volume=10867
	manufacture_date=$(date +%s -d 200516)
	printf "No values entered. \nUsing default values for computing ROI.\n\nManufacturing date is 16/05/2020\n"

elif [ $# -gt 0 ] && [ -z "$3" ]; then 
	# If not enough values entered for calculation 
	printf "Some values are missing for calculation of ROI.\n\n"
	printf "$send_help"
	exit

elif [ $# -gt 3 ]; then 
	# In case too many values are entered
	printf "Too many values have been entered.\n\n"
	printf "$send_help"
	exit
else
	# When all values are entered
	activity=$2
	volume=$3
	# Source manufacturing date in seconds from arguments
	manufacture_date=$(date +%s -d $1)
fi


# Today's date in seconds
current_date=$(date +%s -d $(date "+%y%m%d"))

# Number of days between today and the source's manufacturing day
day_diff=$(( $(( current_date - manufacture_date )) / 86400 )) 

# The computed ROI 
computed_roi=$(echo "( e(-$day_diff / 390.7 ) * 1000 * $activity ) / $volume" | bc -l)

echo "Number of days between today and the source's manufacturing date = $day_diff days"
echo "The activity used = $activity MBq"
echo "The volume used = $volume ml"
printf "\nThe computed ROI is $computed_roi MBq\n"

