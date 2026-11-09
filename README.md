# Raspberry Pi Binary Clock

A real-time binary clock developed using **C and Bash** that displays hours, minutes, and seconds on a Raspberry Pi Sense HAT's 8×8 LED matrix. The project combines binary number representation, hardware interfacing, and Linux shell scripting to create a clock that supports both real-time updates and user-defined time inputs.

<img width="450" alt="Raspberry Pi Sense HAT Binary Clock" src="https://github.com/user-attachments/assets/2231b695-d9bc-4395-a8b8-4ead617fe1b5" />
The Raspberry Pi Sense HAT displaying 21:12:11 (9:12:11 PM) in binary using its 8×8 LED matrix.

The clock represents hours, minutes, and seconds using three color-coded sections: blue for hours, green for minutes, and red for seconds. Each illuminated LED represents a binary digit of 1, while an unlit LED represents 0. The binary digits are read vertically from bottom to top, with each row representing a power of two (1, 2, 4, 8, 16, and 32). White LEDs serve as separators between the time components.

## Features

- Displays time in **24-hour binary format (HH:MM:SS)**.
- Supports both real-time clock updates and manually entered time values.
- Uses distinct LED colors to represent hours, minutes, and seconds.
- Updates the display every second when running in real-time mode.
- Uses a Bash pipe to communicate between the timekeeping script and C program.
- Includes a Makefile for automated compilation and execution.

## How It Works

The clock consists of two main components: a Bash script responsible for timekeeping and a C program responsible for displaying the time.

### 1. Timekeeping (`clock.sh`)

A Bash script retrieves the current system time in `HH:MM:SS` format and outputs the updated time every second.

### 2. Binary Display (`clockdisplay`)

A C program continuously reads time values from standard input, converts the hours, minutes, and seconds into binary representations, and displays them on the Sense HAT's LED matrix.

The LED matrix is divided into three sections:

- **Left:** Hours (0–23)
- **Center:** Minutes (0–59)
- **Right:** Seconds (0–59)

Each section uses a distinct color, with illuminated LEDs representing binary digits. White LEDs separate the sections.

### 3. Operating Modes

**Real-Time Mode**

The Bash script continuously sends the current system time to the C program using a pipe:

```bash
./clock.sh | ./clockdisplay
```

This allows the display to update automatically every second.

**Manual Input Mode**

The C program can also run independently, allowing users to enter custom time values directly into the terminal.

```bash
./clockdisplay
```

For example, entering:

```text
14:35:27
```

displays 14 hours, 35 minutes, and 27 seconds in binary on the LED matrix.

Users can enter multiple time values to update the display without restarting the program.

## Technologies Used

- **C** — Binary representation, input processing, and LED display control
- **Bash** — Timekeeping and shell scripting
- **Raspberry Pi & Sense HAT** — Hardware interfacing and LED visualization
- **GCC & Make** — Compilation and build automation
- **Linux** — Command-line development and execution

## Project Structure

```text
binary-clock/
├── clock.sh       # Bash script for timekeeping
├── main.c         # Reads and processes time input
├── display.c      # Controls the Sense HAT LED display
├── display.h      # Function declarations
├── Makefile       # Compilation and execution
└── README.md      # Project documentation
```

## How to Run

**Requirements:** A Raspberry Pi with a Sense HAT, the required Sense HAT libraries, GCC, Bash, and Make.

### 1. Clone the Repository

```bash
git clone <repository-url>
cd <repository-name>
```

### 2. Compile the Program

```bash
make
```

### 3. Run the Clock

**Option A: Real-Time Clock**

```bash
make run
```

Displays the current system time and updates automatically every second.

**Option B: Manual Time Input**

```bash
./clockdisplay
```

Enter a time in 24-hour format:

```text
HH:MM:SS
```

For example:

```text
09:45:30
```

The corresponding binary representation will appear on the LED matrix. Additional time values can be entered to update the display.

### Troubleshooting

If `make run` fails because `clock.sh` does not have execution permission, run:

```bash
chmod +x clock.sh
```

Then try `make run` again.

Press `Ctrl+C` to stop the real-time clock. In manual mode, entering an incomplete or invalid-format time input ends the program.
