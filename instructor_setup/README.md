# Astro 331 instructor setup

## required software

You will need this software to run Astro 331. Most software can be installed from the command line with Windows’ built-in `winget` command. Those marked with an asterisk require a separate download and installation. 

- XCTU* (https://hub.digi.com/support/products/xctu/)
  configure the radios used for the comm lab
- fritzing* (https://fritzing.org/download/) to create breadboard diagrams

- inkscape (`winget install inkscape.inkscape`) edit svg graphics and convert pdfs to svgs. 
- Markdown software
  - my favorite is typora* (https://typora.io/), but it’s not free
  - typedown (`winget install typedown`) is free and good
- git (`winget install git.git`) version control and distribution of course material to lab/student computers
  - interfaces with github.com (https://github.com/usafa-astro-331/Astro-331X-2023)
- Tortoisegit (`winget install Tortoisegit`) graphical interface for git—integrates with Windows’ File Explorer

## documentation

Documentation is written in markdown. Markdown is a simple markup language that still displays nicely in a text editor if necessary. 



Instructions for each lab are found in that folder’s `README.md`. Github automatically display’s the contents of that file when you view the folder online. 



Images can be added to the markdown file using relative paths, and then they will display locally and online at github. 



## XBee radio setup

The communication lesson (and maybe additional lessons in the future!) uses XBee radios which use the 802.15.4 protocol and operate in the 2.4 GHz ISM band. Each group has two radios, and each radio is attached to an XBee explorer adapter, which provides breadboard-spaced pins and a USB connection. 

One XBee is mounted to FlatSAT, and the other connects to a PC via a USB cable. The PC sees the XBee as a USB serial port, and connects via any serial terminal. Currently, the lab instructions call for PuTTY Portable.

Each pair of radios needs to be configured to communicate with its partner. The group-specific changes (PAN ID/channel number) are made by students following the lab instructions. However, each pair of radios needs the same firmware and base configuration before the lab. 

- install XCTU from digi: https://hub.digi.com/support/products/xctu/
- connect 1 (or many) XBees to your computer via USB
- **Discover** radio modules (big icon with a magnifying glass)
  - select all, next, next, etc. 
- select an XBee from the list on the left
- **Update** the firmware
  - function set: Digi Xbee3 802.15.4
  - 200D (current as of 2023 summer)
- **Default**: restore default firmware settings
- **Write** radio settings



### settings

Astro 331 uses transparent mode (AP0). To both ends this looks like any other serial connection, and characters are passed as they are typed (including backspace, which is transmitted as the backspace character).

All settings on both radios should be identical except the following. 

|      | A (ground) | B (FlatSAT) |
| ---- | ---------- | ----------- |
| DH   | 0          | 0           |
| DL   | 1          | 0           |
| MY   | 0          | 1           |

Communication requires that both radios use the same *channel* and *network PAN ID*.  

#### channel

Both ends should be on the same channel. The default channel of 0x0C (12 in decimal) is acceptable. Theoretically different groups will interfere with each other on this channel and reduce available bandwidth, but

1. throughput is so low that the chance of interference is basically zero
2. there’s so much other interference on 2.4 GHz (wifi, microwaves) that it doesn’t matter. 

#### PAN ID (network ID)

Each group will choose a PAN ID from 0x0 to 0xFFFF. Each group’s PAN ID must be unique. 

For simplicity, the lab instructions direct the students to select a decimal number from 0 to 9999. 

### ground station

Students directly configure the PAN ID, DH, DL, and MY using the following commands. 

`+++` requires 1-second of dead time on either side to enter configuration mode. It is not followed by the enter key, but all other commands are. 

`ATWR` writes commands to non-volatile memory

`ATCN` immediately exits command mode and resumes operation as a wireless serial link. 

![AT_commands](../lab_03_communication/sources/AT_commands.png)

### FlatSAT

The provided Arduino sketch contains radio configuration commands. Students are instructed to change the PAN ID to match their ground station. 

When uploaded, this code re-programs the radio to the correct PAN ID every time Arduino is restarted. 



## fritzing (breadboard diagrams)

Fritzing is open-source adjacent. You can download the source and compile it yourself, but they do list a price to purchase the software. 

However, as of 2023, it is also easy to download for free. If you create a (free) account and login, you can go to the download page and download it directly. 

<img src="../sources/fritzing/331X_bb.svg" alt="breadboard"  />

To create diagrams to put in your instructions:

- export as pdf
- convert to svg
- add svg (using relative path) to markdown file
