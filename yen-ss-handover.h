
/*
This file is writen by yenchu hsu
here is the email you can contect: yenchsu@gmail.com
*/

#ifndef YEN_SS_HANDOVER_H
#define YEN_SS_HANDOVER_H

#include "wimax-net-device.h"
#include "wimax-mac-queue.h"
#include "ns3/event-id.h"
#include "ns3/uinteger.h"
#include "ns3/packet.h"
#include "ss-net-device.h"
namespace ns3 {

//class Packet
/*class HdrCmn
class HdrMac80216
class Mac80216MobMshoReqFrame
class NeighborDB
class WimaxNeighborEntry*/

class YenSSHandover : public WimaxNetDevice
{
public:
  static TypeId GetTypeId (void);//each class must implement a static public member function called GetTypeId (void)
  YenSSHandover (void);
  ~YenSSHandover (void);

  //void send_msho_req (void);
  void InitYenSSHandover(void);
  void send_msho_req (Ptr<Packet> packet, const MacHeaderType &hdrType);

  uint8_t getMOB_MSHO_REQ_size(MshoReq *mshoreq);
  uint8_t getNbNeighbor (void) const;
  
  bool isDetected(void) const;//for inheritance from wimaxnetdevice
  void Start (void);
  void Stop (void);
  bool Enqueue (Ptr<Packet> packet, const MacHeaderType &hdrType, Ptr<WimaxConnection> connection);


private:
    void DoDispose (void);
    bool DoSend (Ptr<Packet> packet, const Mac48Address &source, const Mac48Address &dest, uint16_t protocolNumber);
    void DoReceive (Ptr<Packet> packet);
	
	//parameter from getMOB_MSHO_REQ_size
	uint8_t m_size;
	uint8_t m_tmp;
	uint8_t m_tmpB;

	//parameter from send_msho_req ()
	double rssi;
	uint8_t m_nbPref;
    uint8_t m_detected_;
	// set pointer for send_msho_req (void)
	
	Ptr<WimaxConnection> m_nbrdb;
	Ptr<WimaxConnection> m_entry;

};//class YenSSHandover

} // namespace ns3

#endif /* YEN_SS_HANDOVER_H */



