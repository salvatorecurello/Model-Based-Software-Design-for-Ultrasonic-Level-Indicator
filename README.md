# Model-Based-Software-Design-for-Ultrasonic-Level-Indicator
Model-Based Design (MBD) for an Ultrasonic Level Indicator. Developed in Simulink/Stateflow, verified with Google Test (100% statement coverage), and deployed on Arduino UNO hardware.


# Ultrasonic Level Indicator (Model-Based Design with Simulink & Arduino)

[cite_start]This project implements and verifies an **Ultrasonic Level Indicator** using the **Model-Based Software Design (MBSD)** methodology [cite: 1] [cite_start]with MATLAB/Simulink and Stateflow [cite: 26][cite_start], and deployment on Arduino UNO hardware[cite: 93].

## Key Project Features

* [cite_start]**Architecture:** The system is modeled in Simulink, consisting of a **Controller** (Ranging Estimator) and a simulated **Plant** (Ultrasonic Ranging Sensor)[cite: 18, 19, 20].
* [cite_start]**Control Logic:** The Controller's logic is implemented in Stateflow[cite: 26]. [cite_start]It calculates the distance using a **sliding window moving average** over four measures and determines the level status (IN\_RANGE, OUT\_RANGE, ERROR)[cite: 39, 40, 42].
* [cite_start]**Time Solver:** A **FixedStep Discrete Time solver** was used, set at $1 \mu s$ for accurate representation of the square waveform signal[cite: 14, 17].

## Verification and Code Quality

The project emphasized rigorous testing of the model and the generated code.

* [cite_start]**Simulink Test:** The model was tested using equivalence classes ($x<10, 10 \le x \le 100, x>100$) [cite: 64][cite_start], achieving **100% of Decision Coverage**[cite: 74].
* [cite_start]**Google Test:** The generated C code was verified [cite: 60] [cite_start]using the sampled stimuli, achieving **100.00% of Statement Coverage**[cite: 83, 87].

## Hardware Deployment

* [cite_start]The model was deployed to an **Arduino UNO**[cite: 93].
* [cite_start]The sample time was adjusted to $100 \mu s$ to match the minimum step size the hardware could handle[cite: 97].

---
[cite_start]*Project for the Model-Based Software Design course, Politecnico di Torino (A.Y. 2020-2021).* [cite: 7]