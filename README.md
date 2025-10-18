# Model-Based-Software-Design-for-Ultrasonic-Level-Indicator
Model-Based Design (MBD) for an Ultrasonic Level Indicator. Developed in Simulink/Stateflow, verified with Google Test (100% statement coverage), and deployed on Arduino UNO hardware.

This project implements and verifies an **Ultrasonic Level Indicator** using the **Model-Based Software Design (MBSD)** methodology with MATLAB/Simulink and Stateflow, and deployment on Arduino UNO hardware.

## Key Project Features

* **Architecture:** The system is modeled in Simulink, consisting of a **Controller** (Ranging Estimator) and a simulated **Plant** (Ultrasonic Ranging Sensor).
* **Control Logic:** The Controller uses Stateflow to calculate the distance with a **sliding window moving average** over four measures and determines the level status (IN\_RANGE, OUT\_RANGE, ERROR).
* **Time Solver:** A **FixedStep Discrete Time solver** was used, set at $1 \mu s$ for accurate signal representation.

## Verification and Code Quality

The project emphasized rigorous testing of the model and the generated code.

* **Simulink Test:** The model was tested using equivalence classes, achieving **100% of Decision Coverage**.
* **Google Test:** The generated C code was verified using sampled stimuli, achieving **100.00% of Statement Coverage**.

## Hardware Deployment

* The model was deployed to an **Arduino UNO**.
* The sample time was adjusted to $100 \mu s$ to match the minimum step size the hardware could handle.

---
*Project for the Model-Based Software Design course, Politecnico di Torino (A.Y. 2020-2021).*