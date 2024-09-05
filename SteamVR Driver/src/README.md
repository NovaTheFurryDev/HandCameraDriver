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

### Step 1. **Install CMake**:
   - **Windows**: Download and install from [CMake’s official site](https://cmake.org/download/).
   - **Linux**: Install via your package manager (e.g., `sudo apt-get install cmake`).
   - **MacOS**: Not Supported.

### Step 2. **Install Boost Libraries**:
   - **Windows**: Download and install from the [Boost website](https://www.boost.org/users/download/).
   - **Linux**: Install via your package manager (e.g., `sudo apt-get install libboost-all-dev`).
   - **MacOS**: Not Supported.
### Todo: Finish this...

## **Building the Driver**

### Step 1. Navigate to the Driver Directory:
**Run this Command in a Terminal / Command Prompt**:
```bash
cd src/driver
```
### Step 2. Create a Build Directory::
**Run this Command in a Terminal / Command Prompt**:
```bash
mkdir build
cd build
``` 
### Step 3. Run CMake to Configure the Build:
**Run this Command in a Terminal / Command Prompt**:
```bash
cmake ..
```
### Step 4. Build the Driver:
**Windows**: Open the generated .sln file in Visual Studio and build the project.

**Linux**: Run make to compile the driver:  
```bash
make
```
**MacOS**: **Not Supported** (I hate Apple and Swift so no MacOS Support)

### Step 5. Install the Driver:
**Windows**: Copy the compiled .dll file to the SteamVR drivers directory (e.g., C:\Program Files (x86)\Steam\steamapps\common\SteamVR\drivers).  

**Linux**: Copy the compiled .seo file to the SteamVR drivers directory (e.g., ~/.steam/steam/steamapps/common/SteamVR/drivers).

**MacOS**: **Not Supported...**

### Step 6. Configuration:
**Create or Edit the config.json File (Unused For Now)**:  
Ensure the config.json file is correctly placed in the driver's directory and configured according to your setup.

**Edit the driver.vrdrivermanifest File**:  
Ensure this file is present and correctly configured to point to your driver binary. Here is an example `driver.vrdrivermanifest` file:

```json
{
	"alwaysActivate": true,
	"name" : "HandCameraDriver",
	"directory" : "/HandCameraDriver/SteamVR Driver/bin/",
	"resourceOnly" : false,

	"hmd_presence" : []
}
```
### Step 7. Running the Driver:
**Launch SteamVR**: 

Ensure SteamVR is running.

**Start the Driver & Run The Python Script**:

Make Sure the Python Script is running and The driver should automatically be recognized by SteamVR.

## Troubleshooting:

    Driver Not Detected: Verify the driver binary is placed in the correct SteamVR drivers directory.
    Connection Issues: Ensure the Python script is running and configured to communicate with the correct port and address.
    Build Errors: Verify that all dependencies are correctly installed and paths are correctly configured in CMakeLists.txt.

## Contributing

Contributions to the driver are welcome! Open issues or submit pull requests with improvements or bug fixes.

## License
This driver is licensed under the [MIT License](https://github.com/aws/mit-0). See the [LICENSE](https://github.com/NovaTheFurryDev/HandCameraDriver/blob/main/LICENSE) file for details.

## To Do: 
Add Linux Support or Something...  
Add Support For A Custom JSON File...  
Clean This Up...  
And Other things...  