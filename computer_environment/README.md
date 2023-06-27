# Getting started

You will need to install several programs. This folder contains programs and batch scripts to setup the correct computing environment. These tools are setup for Windows. Equivalent tools exist for Mac or Linux, but you'll have to install your own. 



## Install git

If you are just getting started, copy `install_git.bat` to your local machine from https://github.com/usafa-astro-331/Astro-331X-2023/tree/main/computer_environment

Verify file contents using a text editor. You should do this before running any script. This script runs two commands using Windows' built-in command `winget` to install `git` and `tortoisegit`.  Complete setup of both programs. 

- **git**: version control software

- **TortoiseGit**: windows integration for git



## Clone the course repository

Copy the path to the course repository: https://github.com/usafa-astro-331/Astro-331X-2023

Go to My Documents. Do not create a new course folder yet. 

Right click -> Git clone

Paste the course URL and click OK. 



## Update the course

This step is not necessary if you just cloned the course repository. 

**This step should be performed before every lab to ensure you're using updated material.** 

- Right click the course folder (or any location within the course folder). 
- Git Sync -> Pull



## Install editors

Go to the `computer_environment` folder. 

- Verify the contents of `install_editors.bat`. Run it to install editors

  - **typedown**: a markdown editor/viewer that you will use to view lab instructions
  
  
    - **notepad++**: a useful text editor
    - **Arduino IDE**
  
- Verify and run `update_arduino.bat` which updates the Arduino IDE/environment using the `arduino-cli` tool

  - updates Arduino environment

  - installs drivers for newer SAMD-based Arduino boards such as Arduino MKR Zero




# Before each lab

- Pull latest changes from course repository
  - Right click the course folder (or any location within the course folder). 
  - Git Sync -> Pull
- Update Arduino environment using `install_libraries.bat` found in that lab's folder

