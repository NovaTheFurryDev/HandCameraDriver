#include <openvr_driver.h>
#include <iostream>
#include <thread>
#include <winsock2.h>
#include <sstream>
#include "HandDevice.h"
// Thanks ChatGPT for the help now to test this 

// Use the vr namespace for convenience
using namespace vr;

// Hand tracking data will be sent over this port from the Python app
#define HAND_TRACKING_PORT 65432

// Server socket setup
SOCKET setup_socket() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;

    WSAStartup(MAKEWORD(2,2), &wsa);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(HAND_TRACKING_PORT);

    bind(sock, (struct sockaddr *)&server, sizeof(server));
    listen(sock, 3);

    return sock;
}

// Function to receive data from Python hand tracking app and update hand positions
void listen_for_hand_data(HandDevice* handDevice) {
    SOCKET client_sock;
    char buffer[1024] = {0};
    
    SOCKET sock = setup_socket(); // Assuming setup_socket() is defined elsewhere
    client_sock = accept(sock, NULL, NULL);
    
    while (true) {
        int recv_size = recv(client_sock, buffer, sizeof(buffer), 0);
        if (recv_size > 0) {
            std::string data(buffer);
            std::istringstream iss(data);
            std::vector<float> hand_data;
            float value;

            // Parse the comma-separated hand data
            while (iss >> value) {
                hand_data.push_back(value);
                if (iss.peek() == ',') iss.ignore();
            }

            // Update hand positions (first 3 values in `hand_data`)
            if (hand_data.size() >= 3) {
                handDevice->setHandX(hand_data[0]);
                handDevice->setHandY(hand_data[1]);
                handDevice->setHandZ(hand_data[2]);
            }
        }
    }

    closesocket(client_sock);
    closesocket(sock);
    WSACleanup();
}

class CHandTrackingDriver : public IServerTrackedDeviceProvider {
public:
    EVRInitError Init(vr::IVRDriverContext* pDriverContext) override {
        VR_INIT_SERVER_DRIVER_CONTEXT(pDriverContext);
        m_pHandDevice = new HandDevice();
        vr::VRServerDriverHost()->TrackedDeviceAdded("HandDevice", TrackedDeviceClass_Controller, m_pHandDevice);
        std::thread hand_data_thread(listen_for_hand_data, m_pHandDevice);
        hand_data_thread.detach();
        return VRInitError_None;
    }

    void Cleanup() override { delete m_pHandDevice; }
    const char* const* GetInterfaceVersions() override { return vr::k_InterfaceVersions; }
    void RunFrame() override { }
    bool ShouldBlockStandbyMode() override { return false; }
    void EnterStandby() override { }
    void LeaveStandby() override { }

private:
    HandDevice* m_pHandDevice;
};

CHandTrackingDriver g_HandTrackingDriver;

extern "C" __declspec(dllexport) void* HmdDriverFactory(const char* pInterfaceName, int* pReturnCode) {
    if (0 == strcmp(IServerTrackedDeviceProvider_Version, pInterfaceName)) {
        return &g_HandTrackingDriver;
    }
    return nullptr;
}
