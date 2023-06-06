# day 1

## space/spacecraft overview

course admin

personal overview (me, assistants, students)

spacecraft engineering is hard

video of rocket launch

freefall

not that high—but very fast

can’t get it back

can’t plug it into a wall

whole host of things you need for even the most basic spacecraft

(any spacecraft: gps, starlink, missile warning)

- need data/comm—radio
- point antenna in correct direction—attitude control
- need something to hold everything together—structure
- power it—electrical
  Bell labs invented solar cells—useless: always more expensive than a generator or running longer power lines, until…spacecraft
  also need to power spacecraft when it enters Earth’s shadow—batteries
  usually solar cells and rechargeable batteries
- computer
  theoretically possible to build an analog spacecraft (and some old spacecraft were analog), but…nobody does it
- your payload



That’s what we’ll cover in this course

| day | topic |
| ---- | ------------------------------------------------------------ |
| Mon  | Spacecraft overview   <br />intro to Arduino   <br />measurements lab |
| Tue  | Electrical system                                            |
| Wed  | Cameras                                                      |
| Thu  | Radio communication                                          |
| Fri  | Attitude control                                             |

## intro to arduino

microcontroller family

microcontroller—no operating system

will exactly follow code

arduino—c-based (/c++)

basic program flow 

hello world lab

## measurements

resolution—will discuss more on day 3, but for now:

how many discrete levels: quantization/discretization

black and white photo—digital version

grayscale photo—digital version

quantization chart and math

sensor has a certain range

match the sensor to the measurement

tomorrow will be electrical lab—use current and voltage sensors to measure solar array output

Today we’ll do a measurements lab, and we’ll pick the current sensor for tomorrow’s lab

series and parallel

solar panels

4 cells, 1 array, (1 panel)

really bad one—basically the cheapest one we could find on amazon

multimeters

voltmeter, ohmmeter, etc.

safety

voltmeter—”infinite” resistance

ohmmeter—“zero” resistance—don’t connect an ohmmeter (or multimeter in current mode) to a voltage source—melt/catch fire/blow fuse

today we’re going to measure solar cell output with a multimeter to pick correct ranges

includes connecting array output to a ohmmeter—don’t  do this unless you’re certain of what will happen—I know that the solar cells are current limited and will not supply more current than the ohmmeter can handle

|          | current | voltage |
| -------- | ------- | ------- |
| series   |         |         |
| parallel |         |         |

complete pre-lab

you just measured open-circuit voltage and short-circuit current

measurements lab

# day 2—electrical



# day 3—cameras



# day 4—radios

radios

# day 5—attitude

attitude control









# Welcome to Astro 331

## 2023 Spring

Welcome to Astro 331: Space Systems Engineering. This practical hands-on course will explore spacecraft systems in more depth than you saw in Astro 310: Intro to Astro. If you are an Astro major, many topics from this course will be useful as you go on to work on FalconSAT in Capstone. 

This course uses Arduino-based labs to develop your engineering skills. Arduino is a ubiquitous open source electronic prototyping ecosystem built around a series of microcontrollers. 

In this class we will use Arduinos to build a satellite analog called FlatSAT to explore spacecraft design lessons. FlatSAT is a mini version of the FalconSAT Avionics Test Bed (ATB). 

## Lab overview

Each lab group of 2-3 students will build a FlatSAT using solderless breadboards. Arduino microcontrollers will run FlatSAT. You will communicate with FlatSAT using the Arduino IDE on the lab computers.  

Each lab will explore a new concept, and will add new components to FlatSAT.

1. electrical power

2. camera payload

3. communications

4. attitude system

5. integration and test

A prelab report will be due at the beginning of class for each lab day, as noted in the syllabus. 

In addition to these numbered labs, we will have a few introductory lab exercises. Some of these exercises will only take part of our class time. 

### Lab conduct

In general you will follow the explicit directions for each lab. Please notify your instructor if any instructions are difficult to follow or accomplish. 

During all labs you should take photographs of your completed FlatSAT, your team in action, and test setup as necessary. You should use some of these photographs in your final lab report--definitely include a photograph of your completed FlatSAT after all labs are completed. 

## Computer environment

We will use the Arduino integrated development environment (IDE) to communicate with FlatSAT. We will also use several otehr tools to organize code and other course materials. 

- git: software distribution and version control
  
  - tortoisegit: windows explorer integration for git

- typedown: markdown viewer/editor (for lab instructions)

- arduino-cli: manage arduino libraries

## Getting started

Before the first lab, open the `computer environment` folder and follow the instructions in `README.md`. 

Instructions and code for each lab are located in the lab's numbered folder. 