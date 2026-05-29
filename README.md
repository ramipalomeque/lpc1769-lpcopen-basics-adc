# LPC1769 LPCOpen Basics: ADC Example

[![MCU](https://shields.io)](https://nxp.com)
[![SDK](https://shields.io)](https://nxp.com)
[![IDE](https://shields.io)](https://nxp.com)
[![Language](https://shields.io)](https://wikipedia.org)

A clean, production-ready example demonstrating how to configure and read the Analog-to-Digital Converter (ADC) peripheral on the **NXP LPC1769** microcontroller using the **LPCOpen v2.xx** firmware libraries inside **MCUXpresso IDE**.

This repository serves as a starter guide for firmware engineers learning bare-metal or low-level driver integration for the Cortex-M3 architecture.

---

## 🚀 Key Features

* **ADC Peripheral Initialization:** Step-by-step configuration of the internal ADC clock and sample rate.
* **Channel Selection:** Seamless setup for reading analog inputs (e.g., ADC channel 0 / Pin P0.23).
* **Polled Mode Conversion:** Basic software-triggered (polling) conversion execution flow.
* **Modular Codebase:** Clean separation of concerns between header (`inc/`) and source (`src/`) files.

---

## 🛠️ Hardware & Software Requirements

### Hardware
* **Microcontroller:** NXP LPC1769 (Cortex-M3)
* **Development Board:** LPCXpresso LPC1769 board (or custom hardware layout)
* **Debugger:** Integrated LinkServer probe, CMSIS-DAP, or J-Link

### Software
* **IDE:** MCUXpresso IDE (v11.x or newer recommended)
* **Software Library:** LPCOpen Platform v2.xx for LPC17xx family

---

## 📁 Repository Structure

```text
├── inc/               # C Header files (.h) with register mappings and function prototypes
├── src/               # C Source files (.c) containing main loop and peripheral drivers
├── .cproject          # MCUXpresso IDE compiler and toolchain configurations
├── .project           # MCUXpresso project structure markers
└── .gitignore         # Tailored ignore paths for Eclipse/MCUXpresso build artifacts
```

---

## 💻 How to Import and Run

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/ramipalomeque/lpc1769-lpcopen-basics-adc.git
   ```
2. **Import into MCUXpresso:**
   * Open MCUXpresso IDE.
   * Go to **File > Import > General > Existing Projects into Workspace**.
   * Select the cloned repository root folder as the root directory.
   * Ensure `lpc1769_lpcOpen_basicsADC` is checked, then click **Finish**.
3. **Link LPCOpen Library:**
   * Make sure your workspace contains the `lpc_chip_175x_6x` base library from NXP.
   * Right-click the project -> **Properties > C/C++ Build > Settings > MCU Linker > Libraries** to verify paths if necessary.
4. **Build & Debug:**
   * Click the **Build** (Hammer) icon to compile.
   * Click the **Debug** (Blue Bug) icon to flash the `.axf` bin onto your LPC1769 board.

---

## 🔍 Code Walkthrough (Brief Overview)

The firmware performs the following operational loop:
1. **System Initialization:** `SystemInit()` configures internal core clocks.
2. **Peripheral Setup:** `Chip_ADC_Init()` sets up the ADC clock and internal dividers.
3. **Pin Muxing:** Configures the target GPIO pin to functional mode `ADC`.
4. **Data Acquisition:** Triggers a conversion, awaits the `DONE` flag via software polling, and extracts the 12-bit digital conversion result.

---

## 🏷️ Meta Keywords & SEO Tags
`lpc1769-adc-example` | `lpcopen-adc-sample` | `mcuxpresso-lpc1769-project` | `cortex-m3-adc-polling` | `nxp-lpc1769-tutorial` | `embedded-c-adc`

