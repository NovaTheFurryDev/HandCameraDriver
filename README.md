# HandCameraDriver: [Built with SteamVR Input 2.0](https://docs.vrchat.com/docs/steamvr-input-20#hand-tracking)

A SteamVR hand tracking solution using a Webcam or [Phone Camera](https://reincubate.com/camo/) to track hand movements and send the data to SteamVR for VR interactions.  
**This is still a Work-In-Progress!!**

## Overview

This project enables hand tracking using a webcam or [phone camera](https://reincubate.com/camo/) and integrates with SteamVR through a custom driver. It utilizes the MediaPipe library for hand tracking and sends hand joint positions to SteamVR using a local socket connection.

## Features

- **Webcam/Phone-Camera-Based Hand Tracking**: Uses MediaPipe to detect and track hand landmarks.
- **SteamVR Integration**: Sends hand tracking data to SteamVR for VR applications.
- **Configurable Settings**: Adjustable camera settings, hand tracking parameters, and network configuration through `config.json`.
- **Built for VRChat**: The reason i made this project is because of VRChat's new [SteamVR Input 2.0](https://docs.vrchat.com/docs/steamvr-input-20#hand-tracking)

## Getting Started

### Prerequisites

- **Python 3.x**: Ensure Python is installed.
- **Required Python Libraries**:
  - [OpenCV](https://pypi.org/project/opencv-python/)
  - [MediaPipe](https://pypi.org/project/mediapipe/)
  - [TensorFlow](https://pypi.org/project/tensorflow/)
- **SteamVR**: Installed and configured on your system.
- **Custom SteamVR Driver**: C++ driver code for receiving hand tracking data (see `src/driver`).
- **A Camera**: You need either a Webcam or an App that allows you to use your Phone Camera as a camera on your PC I will link some below:
### [Camo](https://reincubate.com/camo/):
**From the sites description**:  
Camo is a video app that lets you improve your camera quality, add overlays, filters, and effects to your video. Whether you use it for meetings, streaming, recording, or content creation, Camo can help you create great video with any device.  
### [Iriun Webcam](https://iriun.com/):
**From the sites description**:  
Use your phone's camera as a wireless webcam in your PC or Mac.
Install Webcam for Windows, Mac or Linux, download Iriun Webcam app to your mobile phone and start using the phone with your favourite video applications.

## Building & Installation
### Prerequisites

### Step 1: Clone the Repository:
Run this Command in a Terminal / Command Prompt:
   ```bash
   git clone https://github.com/NovaTheFurryDev/HandCameraDriver.git
   cd HandCameraDriver
   ```
### Step 2. Install Python Dependencies:
Run this Command in a Terminal / Command Prompt:
```bash
pip install opencv-python mediapipe tensorflow
```
### Step 3. Compile the SteamVR Driver (Optional):
Follow the instructions in the [src/driver/README.md)](https://github.com/NovaTheFurryDev/HandCameraDriver/blob/main/SteamVR%20Driver/src/README.md) to build the custom SteamVR driver.

### Step 4. Set Up Configuration:
 Edit config.json to match your camera settings and network configuration.  
## Example:
```json
Empty till i make a Proper JSON For this...
```

# Usage:
### Step 1. Start the SteamVR Driver:
 Ensure that the driver is running and listening for connections.
### Step 2. Run the Hand Tracking Script:
Run this Command in a Terminal / Command Prompt:
```bash
python camera.py
```
This will start the webcam feed, perform hand tracking, and send the data to the SteamVR driver.
## This is all you really need to do to get it working, everything below this is optional
### Step 3. JSON Configuration (Optional):

Modify config.json to adjust settings for your camera, hand tracking model, network, and debug options.
Troubleshooting

    Connection Issues: Ensure the SteamVR driver is running and configured to listen on the specified port.
    Model Path Errors: Verify the path to the hand tracking model file in config.json.


# Contributing:

Feel free to open issues or submit pull requests to contribute to the project.

# License:

This project is licensed under the [MIT License](https://github.com/aws/mit-0). See the [LICENSE file](https://github.com/NovaTheFurryDev/HandCameraDriver/blob/main/LICENSE) for details.
