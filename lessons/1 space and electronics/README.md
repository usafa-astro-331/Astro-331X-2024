# space, electronics, microcontrollers

## introduction

### admin

- bathrooms, evacuation
- lab location
- phone numbers
- personal introduction
- student names, etc. 
- badges?
- lunch

### Astro 331X context

- intended to be the fun parts of Astro 331: Spacecraft Systems Engineering
- FlatSAT breadboard spacecraft analog
- Astro 331:
  - mostly Astro major sophomores (Aero vs Astro)
  - semester-long
  - comes after core Astro
  - …which comes after Calc 1/2, physics 1/2, mech
  - used to use EyasSat
  - 2 years into a 5-year refresh—moving to breadboard labs
- other classes teach orbits, rockets
- capstone we build a real spacecraft

### course schedule

1. space, electronics, microcontrollers
2. electricity
3. cameras
4. communication
5. attitude



- learn
- predict
- complete lab
- analyze/document

### today

- admin
- space
- digital electronics/quantization
- measure solar array output limits 
- metrology lab
- electricity
- (microcontrollers)

## space

- what is space? where is space?
- space is hard/what makes space hard?—xkcd handout (play *I’m Gonna Be*)
- when should we choose to accomplish something with a spacecraft?
  - never!/only when it’s the only possible way
- what is the baseline requirement for a useful spacecraft?
  - radio
  - energy generation
  - energy storage
  - structure, including launch
  - orbit control (thrusters, de-orbit)
  - (digital computer/electronics)
  - payload
- exceptions?
  - no requirements post-deployment
    - ECHO 1/ECHO 2
    - Project Westford
  - analog electronics?
    - Sputnik
- themes
  - commoditization
    - launch
    - electronics

## digital electronics/quantization

- spacecraft use digital computers
- we need to turn analog measurements into digital signals

### analog to digital conversion (ADC)

- Analog signals must be converted into digital signals on-board the S/C
- sample rates must be ≥ 2 times max frequency contained in signal (Nyquist criteria) 

$$
f_s \geq 2.2 f_m
$$

- Use an analog-to-digital converter. In the metrology lab we used Arduino’s built-in ADC to measure voltage from our voltage divider. 

Equations:
$$
f_s≥2.2f_m
$$

$$
Discrete\ \#=A_{min}+(A_{max}-A_{min} ) \left(\frac{Digital\ \#}{2^n} + \frac{1}{2^{n+1}} \right)
$$

$$
Quantization\ Step=\frac{A_{max}-A_{min}}{2^n}
$$

$$
Error_{max}=\frac{A_Max-A_Min}{2^{n+1}}
$$

A is any analog signal

- voltage
- current
- pressure
- audio wave (CD audio is 44.1 kHz)
- brightness

![biker](./sources/biker_quantization.png)

1 bit: 2 levels (B/W)

2 bit: 4 levels

3 bit: 8 levels



line: $$y=mx+b$$

- in analog world we can define a point on the line to arbitrary precision
- in digital world we have to decide how many bits to use to represent a point
  - 1 bit: on/off
  - 2 bits: 4 possible values
  - …
  - n bits: $2^n$ possible values
- (nearly) always wrong—but (usually) close enough
  - this is engineering!
- limits:
  - bandwidth
  - storage
  - sensor resolution—match sensor range to expected measurement range
  - Physics of signal—avoid storing more data than the analog signal contains. Example: recording hi-res audio of an 8-track player. 

**Example**

![](./sources/quantization_graph.png)



|              |                |  **Option #1**  |                |    Option #2    |                |
| :----------: | :------------: | :-------------: | :------------: | :-------------: | -------------- |
| Analog Range | Digital  Value | Discrete  Value | Maximum  Error | Discrete  Value | Maximum  Error |
|    0-4 V     |       00       |      0  V       |      4  V      |      2  V       | 2  V           |
|    4-8 V     |       01       |     5.3  V      |     2.7  V     |      6  V       | 2  V           |
|    8-12 V    |       10       |     10.7  V     |     2.7 V      |      10  V      | 2  V           |
|   12-16 V    |       11       |      16  V      |      4  V      |      14  V      | 2  V           |



- will measure electrical current in today’s metrology lab 
  - what sensor should we pick? 
  - what current ranges should we measure?
  - in the *next* lab we will measure power output from our solar arrays—want to measure that much current
- first lab: pick the right current sensor for the second lab

### digital to analog conversion (DAC)

- implied
- usually care about recreating the analog data



## microcontrollers

In this course we will use the Arduino MKR Zero microcontroller. 

> A microcontroller unit (MCU) contains a CPU, memory, and input/output  peripherals on a single integrated circuit (IC) chip and works as a  standalone small computer. This allows for a reduction in power  consumption, more compact designs, and cost savings. Additionally,  microcontrollers can provide functional safety and security for embedded systems.

-[Infineon](https://www.infineon.com/cms/en/product/microcontroller/)

The computers you usually think of (including phones), use microprocessors, which are more complex than microcontrollers. Microcontrollers usually do not run an operating system and instead directly run their code. Most operating systems are not real-time operating systems, which means there is no guarantee of when code will run. It is easy to create deterministic timing with a microcontroller. 



| Microprocessor                                 | Microcontroller                                          |
| ---------------------------------------------- | -------------------------------------------------------- |
| Computer system (incl phones)                  | embedded system (washing machine, MP3 player, etc.)      |
| memory and I/O components connected externally | processor along with internal memory and I/O components. |
| \$10–\$10k                                     | \$0.10–\$100         
|                                                | ridiculously low power                                   |
| IC -> OS -> code                               | IC -> code<br />(no OS)                                  |

Most microcontrollers contain single-string processors, which mean they can only perform one task at a time. They are much faster than humans though, so by switching between tasks rapidly, they can give the appearance of multitasking. Even desktops/laptops/phones do this. As I write this, I currently have 12 programs open on my laptop, which has a 4-core Intel processor with hyperthreading. However, Windows reports that I have 769 processes running. 



FalconSAT runs a full Linux-based flight computer, but 331X’s FlatSAT is simple enough to run on a microcontroller. 

FlatSAT runs on an Arduino MKR Zero microcontroller. 
(Actually, it’s a development board built around the SAMD21 Cortex®-M0+ microcontroller.)

