# AVR-Multiplexed-7Seg-Display

> Drive a 4-digit common cathode 7-segment display using AVR microcontroller with multiplexing.

![Schematic](schematic.png)  
*Example schematic using Proteus or similar tool*

---

## 🧩 Features

- ✅ Drives 4-digit common cathode 7-segment display
- ✅ Uses multiplexing for efficient hardware usage
- ✅ Direct port manipulation for speed
- ✅ Configurable digit patterns via `seg[]` array
- ✅ Tested on ATmega32/ATmega16 (adjust pins if needed)

---

## 🔧 Hardware Requirements

- AVR Microcontroller (ATmega32 / ATmega16)
- 4-digit common cathode 7-segment display (e.g., CC-4DIGIT)
- 8x 220Ω–470Ω resistors (for segments A–G + DP)
- 4x 220Ω–470Ω resistors (for digit enables DIG1–DIG4)
- Breadboard & jumper wires
- Power supply (5V)

---

## 📐 Pin Mapping (ATmega32)

| Function | Port Pin     |
|----------|--------------|
| Segment A | PC0          |
| Segment B | PB5          |
| Segment C | PC1          |
| Segment D | PC2          |
| Segment E | PC3          |
| Segment F | PC4          |
| Segment G | PC5          |
| DP       | PD0          |
| DIG1     | PD1          |
| DIG2     | PD2          |
| DIG3     | PD3          |
| DIG4     | PD4          |

> ⚠️ Ensure your hardware matches this mapping. Adjust `#define`s if needed.

---

## 💡 How It Works

The program:
1. Initializes all segment and digit pins as outputs.
2. Loops through each digit:
   - Turns off all digits.
   - Sets the correct segment pattern for current digit.
   - Turns on only that digit for ~2ms.
   - Repeats for next digit.
3. Creates persistence of vision effect — appears as if all digits are lit at once.

---

## 🛠️ Build & Flash

1. Compile with AVRGCC or Atmel Studio.
2. Flash to your AVR using USBasp, PonyProg, or similar programmer.
3. Power on and observe `1379` displayed.

---

## 📁 File Structure
