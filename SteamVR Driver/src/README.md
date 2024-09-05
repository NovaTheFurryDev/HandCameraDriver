# SteamVR Webcam Hand Tracking Driver

This document provides instructions for building and configuring the custom SteamVR driver for integrating webcam-based hand tracking.

## Overview

The SteamVR driver allows SteamVR to receive hand tracking data from a webcam. This driver communicates with the Python script using a local socket to receive hand tracking data.

## Prerequisites

- **SteamVR SDK**: Ensure that you have SteamVR and its SDK installed.
- **C++ Development Environment**:
  - **Windows**: Visual Studio (2019 or later recommended)
  - **Linux**: g++ or clang++
- **CMake**: Required for configuring the build process.
- **Boost Libraries**: Required for network communication.

## Installation

### Setting Up Your Development Environment

1. **Install SteamVR SDK**:
   Follow the instructions on the [SteamVR GitHub repository](https://github.com/ValveSoftware/steamvr_unity_plugin) to set up the SteamVR SDK.

2. **Install CMake**:
   - **Windows**: Download and install from [CMake’s official site](https://cmake.org/download/).
   - **Linux**: Install via your package manager (e.g., `sudo apt-get install cmake`).

3. **Install Boost Libraries**:
   - **Windows**: Download and install from the [Boost website](https://www.boost.org/users/download/).
   - **Linux**: Install via your package manager (e.g., `sudo apt-get install libboost-all-dev`).

### Building the Driver

1. **Navigate to the Driver Directory**:
   ```bash
   cd src/driver
