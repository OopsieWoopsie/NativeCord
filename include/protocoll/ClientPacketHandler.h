//
// Created by wolverindev on 23.08.16.
//

#ifndef CBUNGEE_CLIENTPACKETHANDLER_H
#define CBUNGEE_CLIENTPACKETHANDLER_H


#include "PacketHandler.h"

class PlayerConnection;
class ClientPacketHandler : public PacketHandler {
public:
        friend class PlayerConnection;
    ClientPacketHandler(PlayerConnection* connection) : PacketHandler((Connection*) connection){
        this->pconnection = connection;
    }

    PlayerConnection* getPlayerConnection(){
        return pconnection;
    }

private:
    void handlePacket(DataBuffer* buffer);
    void handlePacketHandschake(int packetId,DataBuffer* buffer);
    void handlePacketStatus(int packetId,DataBuffer* buffer);
    void handlePacketLogin(int packetId,DataBuffer *buffer);
    void handlePacketPlay(int packetId,DataBuffer *buffer);


private:
    PlayerConnection* pconnection;
};


#endif //CBUNGEE_CLIENTPACKETHANDLER_H
