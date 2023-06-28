#!/bin/sh
# combine lab part lists into a consolidated part list
cat lab_equipment/lab_equipment.csv > components.csv
tail -n +2 lab_00_metrology/components.csv >> components.csv
tail -n +2 lab_01_electrical_power/components.csv >> components.csv
tail -n +2 lab_02_camera_payload/components.csv >> components.csv
tail -n +2 lab_03_communication/components.csv >> components.csv
tail -n +2 lab_04_attitude/components.csv >> components.csv 