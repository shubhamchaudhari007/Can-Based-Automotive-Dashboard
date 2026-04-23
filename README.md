# 🚗 CAN-Based Automotive Dashboard – Multi ECU System (Embedded C)

## 🚀 Overview

This project implements a **multi-node automotive dashboard system** using **CAN (Controller Area Network)** protocol and **PIC microcontrollers**.

The system consists of **three ECUs**:

* **ECU1 & ECU2** → Sensor nodes (data generation)
* **ECU3** → Dashboard node (data processing & display)

All ECUs communicate over CAN bus to simulate real-time vehicle behavior.

---

## 🧩 System Architecture

```id="arch"}
ECU1 (Speed + Gear)  ─┐
                      ├──► CAN BUS ───► ECU3 (Dashboard Display)
ECU2 (RPM + Indicator) ─┘
```

---

## 🎯 Features

### 🔧 ECU1 (Sensor Node)

* ✅ Reads speed using ADC
* ✅ Detects gear position using keypad
* ✅ Sends data via CAN

### 🔧 ECU2 (Sensor Node)

* ✅ Reads RPM using ADC
* ✅ Controls indicator input
* ✅ Sends RPM and indicator status via CAN

### 📟 ECU3 (Dashboard Node)

* ✅ Receives CAN messages
* ✅ Processes data using message handler
* ✅ Displays Speed, Gear, RPM on CLCD
* ✅ Controls LED indicators (Left/Right/Off)
* ✅ Uses timer interrupt for blinking logic

---

## 📡 CAN Communication

* ✅ Standard CAN message transmission

* ✅ Unique message IDs for each parameter:

  * Speed → `0x10`
  * Gear → `0x20`
  * RPM → `0x30`
  * Indicator → `0x50` 

* ✅ Block-based data transfer between ECUs

* ✅ Real-time data synchronization

---

## ⚙️ Technologies Used

* **Microcontroller:** PIC18 Series
* **Language:** Embedded C
* **Protocol:** CAN
* **Compiler:** MPLAB XC8
* **Peripherals:** ADC, CLCD, SSD, Keypad, UART

---

## 🏗️ Project Structure

```id="canstruct2"
CAN_Dashboard/
│── ecu1_main.c
│── ecu1_sensor.c
│── ecu2_main.c
│── ecu2_sensor.c
│── main.c                (ECU3 Dashboard)
│── message_handler.c
│── message_handler.h
│── can.c
│── can.h
│── adc.c
│── adc.h
│── clcd.c
│── clcd.h
│── uart.c
│── uart.h
│── keypad files
│── msg_id.h
│── Makefile
```

---

## ▶️ Working Principle

1. ECU1 reads speed & gear → sends via CAN
2. ECU2 reads RPM & indicator → sends via CAN
3. ECU3 receives all CAN messages
4. Message handler processes data
5. Dashboard displays values and controls LEDs

---

## 💻 Key Functionalities

* CAN data transmission & reception 
* Message handling and routing 
* ADC-based sensor input
* CLCD display output
* Interrupt-based timing for indicators 

---

## ⚠️ Limitations

* ❌ No real vehicle hardware integration
* ❌ Basic CAN error handling
* ❌ Limited scalability beyond 3 ECUs

---

## 🔮 Future Enhancements

* 🔹 Add more ECUs (engine temp, fuel level, etc.)
* 🔹 Implement CAN error detection & recovery
* 🔹 Integrate real vehicle sensors
* 🔹 Add graphical dashboard (GUI)

---

## 🧩 Challenges Faced

* Synchronizing multiple ECUs over CAN
* Designing message ID-based routing
* Handling real-time display updates
* Managing interrupts and timing correctly

---

## 📚 Learning Outcomes

* Deep understanding of CAN protocol
* Multi-node embedded system design
* Real-time communication handling
* Integration of multiple hardware modules

---

## 📌 Author

**Shubham Chaudhari**
