#include <openvr_driver.h>
#include <iostream>
#include <thread>
#include <winsock2.h>
#include <sstream>

// Use the vr namespace for convenience
using namespace vr;

// Base class for hand tracking device
class HandDevice : public vr::ITrackedDeviceServerDriver {
public:
    void setHandX(float x) { hand_x = x; }
    void setHandY(float y) { hand_y = y; }
    void setHandZ(float z) { hand_z = z; }
    
    DriverPose_t GetPose() override {
        DriverPose_t pose = { 0 };
        pose.poseIsValid = true;
        pose.deviceIsConnected = true;
        pose.vecPosition[0] = getHandX();
        pose.vecPosition[1] = getHandY();
        pose.vecPosition[2] = getHandZ();
        return pose;
    }

    // Correctly implement the DebugRequest method
    void DebugRequest(const char* pchRequest, char* pchResponseBuffer, uint32_t unResponseBufferSize) override {
        // Handle debug requests here
        if (pchResponseBuffer && unResponseBufferSize > 0) {
            strncpy(pchResponseBuffer, "Debug response", unResponseBufferSize - 1);
            pchResponseBuffer[unResponseBufferSize - 1] = '\0'; // Ensure null-termination
        }
    }

    vr::EVRInitError Activate(uint32_t unObjectId) override {
        // Initialize the device here
        vr::VRDriverInput()->CreateBooleanComponent(unObjectId, "/input/system/click", &m_clickComponent);
        return vr::VRInitError_None;
    }

    void Deactivate() override {
        // Cleanup
    }

    void EnterStandby() override {
        // Handle standby mode
    }

    void* GetComponent(const char* pchComponentNameAndVersion) override {
        // Return the requested component
        return nullptr;
    }

    void PowerOff() {
        // Handle power off
    }

    // Public getter methods
    float getHandX() const { return hand_x; }
    float getHandY() const { return hand_y; }
    float getHandZ() const { return hand_z; }

private:
    float hand_x = 0.0f, hand_y = 0.0f, hand_z = 0.0f;
    vr::VRInputComponentHandle_t m_clickComponent;
};