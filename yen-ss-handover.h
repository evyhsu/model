
/*
This file is writen by yenchu hsu
here is the email you can contect: yenchsu@gmail.com
*/

#ifndef YEN_SS_HANDOVER_H
#define YEN_SS_HANDOVER_H

#include "ns3/event-id.h"
#include "ns3/uinteger.h"
#include "ns3/packet.h"
#include "ss-net-device.h"
#include "wimax-net-device.h"
#include "wimax-mac-queue.h"
#include "mac-messages.h"
#include "dl-mac-messages.h"
#include <stdint.h>


#include "cid.h"
#include "ns3/nstime.h"
//class SSRecord;
//class ServiceFlow;
//class UlJob;
//class UplinkScheduler;
class SSLinkManager;
//class SubscriberStationNetDevice;

namespace ns3 {

class YenSSHandover : public Object
{
public:
  static TypeId GetTypeId (void);//each class must implement a static public member function called GetTypeId (void)
  YenSSHandover (Ptr<WimaxNetDevice> device);
  ~YenSSHandover (void);
  void DoDispose (void);

  void InitYenSSHandover(void);
  void send_msho_req (/*Cid cid*/);

  uint8_t GetMOB_MSHO_REQ_size();

  uint8_t GetNeighbors (void) const;
  uint8_t GetNbNeighbor (void) const;

  void SetBsEirp (uint16_t bs_eirp);
  void SetEirXPIrMax (uint16_t eir_x_p_ir_max);

  //uint8_t GetNbNeighbor (void) const;
  //bool isDetected(void) const;//for inheritance from wimaxnetdevice
  //void Start (void);
  //void Stop (void);
  //bool Enqueue (Ptr<Packet> packet, const MacHeaderType &hdrType, Ptr<WimaxConnection> connection);
  
  /*Ptr<SSLinkManager> m_rssi;
  Ptr<SSLinkManager> GetRSSI (void) const;
  void SetRSSI (Ptr<SSLinkManager> );*/

  /*Ptr<SubscriberStationNetDevice> m_ss;
  Ptr<SubscriberStationNetDevice> GetSS;
  void SetSS (Ptr<SubscriberStationNetDevice> );*/
private:
    YenSSHandover (const YenSSHandover&);
    YenSSHandover & operator= (const YenSSHandover &);
    //bool DoSend (Ptr<Packet> packet, const Mac48Address &source, const Mac48Address &dest, uint16_t protocolNumber);
    //void DoReceive (Ptr<Packet> packet);
	
    void SetParametersToAdjust (MshoReq *mshoreq);
    //uint16_t CalculateMaxIRSignalStrength (void);
    //uint16_t GetMinTransmitPowerLevel (void);
	//parameter from getMOB_MSHO_REQ_size
	uint8_t m_size;
	uint8_t m_tmp;
	uint8_t m_tmpB;
    uint8_t m_123;
    uint8_t m_nbrdb;
    uint8_t m_entry;
	//parameter from send_msho_req ()
	double rssi;
	uint8_t m_nbPref;
    uint8_t m_nbentry;
    uint8_t m_nbs;


    //uint8_t m_bsEirp;
    //uint8_t m_eirXPIrMax;
    //uint16_t m_rssi;

	// set pointer for send_msho_req (void)
	//Ptr<WimaxConnection> m_nbrdb;
	//Ptr<WimaxConnection> m_entry;
    //Ptr<SubscriberStationNetDevice> m_ss;

    Ptr<WimaxNetDevice> m_device;
    //Ptr<SSLinkManager>  m_rssi;

};//class YenSSHandover

} // namespace ns3

#endif /* YEN_SS_HANDOVER_H */



