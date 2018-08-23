#include <Arduino.h>
#include <send_data.h>
#include <VirtualWire.h>

#include <send_data.h>

char transmissionMessage[50];
bool pingSend;

void setupSendData()
{
    // Initialise the IO and ISR
    vw_set_tx_pin(RF_OUTPUT);
    vw_set_ptt_inverted(true); // Required for DR3100
    vw_setup(2000);            // Bits per sec
}

void sendData()
{
    vw_send((uint8_t *)transmissionMessage, strlen(transmissionMessage));
    vw_wait_tx(); // Wait until the whole message is gone
    Serial.print("Send data: ");
    Serial.println(transmissionMessage);
}

void sendPing(bool force)
{
    if (!force && pingSend)
    {
        return;
    }

    sprintf(transmissionMessage, "%s-ping", NODE_HASH);

    sendData();
    Serial.println("Send ping");
    pingSend = true;
}
