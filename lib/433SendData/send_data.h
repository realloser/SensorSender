
#define RF_OUTPUT 3

extern char transmissionMessage[50];

void setupSendData();

void sendData();

void sendPing(bool force, char *nodeName);
