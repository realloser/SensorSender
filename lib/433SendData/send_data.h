
#define RF_OUTPUT 3

// 433 rf
#define NODE_HASH "DEFINE_NODE_HASH"

extern char transmissionMessage[50];
extern int messageIndex;

void setupSendData();

void sendData();

void sendPing(bool force = false);
