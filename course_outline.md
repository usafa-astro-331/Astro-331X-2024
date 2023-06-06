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

record incident light with luxmeter

you just measured open-circuit voltage and short-circuit current

measurements lab

(write a report)

# day 2—electrical

most spacecraft need an electrical system

exceptions: project westford, echo 1/2, gemini upper stage target

list: all the things need electricity, and your payload does too

what are possible ways to generate electricity? 

- mechanical
  - wind/air pressure
  - tidal
  - hydro
  - gravity
  - spring
- nuclear (thermal)
  - reactor
  - RTG
  - (can use heat from other sources too)
- chemical
  - oxidation/reduction reactions
- EM
  - photovoltaic effect
    - related to photoelectric effect described by Einstein

most of these could work in space

However, we usually design spacecraft to last for months (small) to years (large), so we need a power source that lasts that long too

solar or radioactive

Earth-orbiting: solar

IV curve

max power

draw predicted IV curve from yesterday’s measurements

what is max power?



falconsat power budget?

eclipse diagram/math

flatsat power budget

# day 3—cameras



# day 4—radios

radios

# day 5—attitude

attitude control








