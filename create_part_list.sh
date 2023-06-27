#!/bin/sh
# combine lab part lists into a consolidated part list
cat lab_equipment/lab_equipment.csv > parts.csv
tail -n +2 lab_00_metrology/parts00.csv >> parts.csv
tail -n +2 lab_01_electrical_power/parts01.csv >> parts.csv
tail -n +2 lab_02_camera_payload/parts02.csv >> parts.csv
tail -n +2 lab_03_communication/parts03.csv >> parts.csv
tail -n +2 lab_04_attitude/parts04.csv >> parts.csv 