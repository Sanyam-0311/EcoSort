# EcoSort

Welcome to the Waste Management System project! This system helps in managing different types of waste using sensors and relay modules. It can detect and manage metallic waste, moisture waste, and toxic gas waste.

## Introduction

This project is designed to efficiently handle waste disposal based on waste type. It uses various sensors to detect waste types and then controls the conveyor belt using relay modules.

## Components

- **Moisture Sensor**: To detect moisture in waste.
- **Gas Sensor**: To detect toxic gas in waste.
- **Proximity Sensor**: To detect metallic waste.
- **Relay Modules**: To control the conveyor belts for waste management.

## Setup

### Pin Configuration

- Moisture Sensor Pin: A0
- Gas Sensor Pin: A1
- Metallic Proximity Sensor Pin: 2
- Proximity Sensor Pin: 3
- Relay Module Pin: 9 (For metallic waste)
- Relay Module Pin: 10 (For moisture and gas waste)

### Thresholds

- Moisture Threshold: 37 mm/m^3 (Adjust as needed)
- Gas Threshold: 200 ppm

### Initial State

- Metallic Waste Relay: Initially off
- Moisture and Gas Waste Relay: Initially off

## Usage

1. Ensure the sensors and relay modules are correctly connected to the specified pins.
2. Upload the code to your microcontroller (e.g., Arduino).
3. The system will continuously monitor waste types and control the conveyor belts accordingly.
4. When metallic waste is detected, the metallic waste relay will be turned on for 5 seconds.
5. If moisture or toxic gas waste is detected, the respective relay will be turned on.

## Sensors

- Moisture Sensor: Monitors the moisture level in the waste.
- Gas Sensor: Detects toxic gases in the waste.
- Proximity Sensor: Identifies metallic waste.

## Acknowledgments

- Special thanks to the creators of Arduino and the sensor manufacturers for enabling this waste management system.
