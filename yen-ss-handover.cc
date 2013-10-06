/*
This file is writen by yenchu hsu
here is the email you can contect: yenchsu@gmail.com
*/

#include "yen-ss-handover.h"
#include "ss-link-manager.h"
#include "bs-net-device.h"
#include "ss-net-device.h"
#include <stdint.h>
#include "ns3/node.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
#include "ns3/pointer.h"
#include "ns3/enum.h"
#include "ss-link-manager.h"

NS_LOG_COMPONENT_DEFINE ("YenSSHandover");

namespace ns3 {
NS_OBJECT_ENSURE_REGISTERED (YenSSHandover);

TypeId YenSSHandover::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::YenSSHandover")
    .SetParent<Object> ();
  return tid;
}

YenSSHandover::YenSSHandover (Ptr<WimaxNetDevice> device)
  : m_device (0)
    //m_bsEirp (65535),
    //m_eirXPIrMax (65535),
    //m_ss (0)
{
    //m_device = device;
}

YenSSHandover::~YenSSHandover (void)
{
  //m_ss = 0;
}

void 
YenSSHandover::DoDispose (void)
{
  m_device = 0; 
  m_nbrdb = 0;
  m_entry = 0;
  //m_ss = 0;
}

/*t
bool
YenSSHandover::isDetected(void) const
{
	return m_detected_;
}*/

void
YenSSHandover::InitYenSSHandover (void)
{
	m_size = 0;
	m_tmp = 0;
	m_tmpB = 0;
    m_123 = 0;
    //m_rssi = CreateObject<SSLinkManager> ();   
    //m_ss = CreateObject<SubscriberStationNetDevice> (this);
}

uint8_t
YenSSHandover::GetNbNeighbor (void) const
{
	return m_nbentry;
}
uint8_t
YenSSHandover::GetNeighbors (void) const
{
	return m_nbs;
}

/*void
YenSSHandover::SetBsEirp (uint16_t bs_eirp)
{
  m_bsEirp = bs_eirp;
}

void
YenSSHandover::SetEirXPIrMax (uint16_t eir_x_p_ir_max)
{
  m_eirXPIrMax = eir_x_p_ir_max;
}*/

uint8_t
YenSSHandover::GetMOB_MSHO_REQ_size ()
{	
    MshoReq mshoreq;
    std::cout << "yensshandover" << std::endl;
	
	if (mshoreq.GetNNewBsIndex () !=0) 
    	m_size++;

	if (mshoreq.GetReportMetric () & 0x1) m_tmp++;
  	if (mshoreq.GetReportMetric () & 0x2) m_tmp++;
  	if (mshoreq.GetReportMetric () & 0x4) m_tmp++;

	/*for (uint8_t i = 0 ; i < m_n_new_bs_index ; i++) {
	    m_tmpB += 20 + 8*m_tmp;    
      if (bs_index[i].arrival_time_diff_ind & 0x1)//000000000000000000000000000000000
      	m_tmpB += 4;
  }*/

    //m_123 = CalculateMaxIRSignalStrength ();

  	m_size += m_tmp/8;
  	if ((m_tmp%8)!=0)
    	m_size ++;  //includes padding
  
  	return m_size;
}

void
YenSSHandover::SetParametersToAdjust (MshoReq *mshoreq)
{
  mshoreq->SetReportMetric (0x2);
  mshoreq->SetNNewBsIndex (0);
}

/*void 
YenSSHandover::send_msho_req ()
{
    
    //Ptr<SubscriberStationNetDevice> ss = m_device->GetObject<SubscriberStationNetDevice> ();
    MshoReq mshoreq;//define at mac-messages.cc, replace Mac80216MobMshoReqFrame *m_req_frame;
	
	m_nbPref = 0;
  	for (uint8_t i = 0 ; i < GetNbNeighbor() ; i++) {
   	  m_entry = GetNeighbors();
		if (m_entry->isDetected()){
			//NS_LOG_DEBUG ("At: " << NOW << " Mac address : " << addr() << 
						 // "Found new AP: " << m_entry->getID() << "..need to send HO message\n");
		  m_nbPref++;
 	 }
 	//}
		//if (m_nbPref=0) 
			//return ; //no other BS found*/

//create packet for request
   /*Ptr<Packet> p = Create<Packet> ();//
   p->AddHeader (mshoreq);
   p->AddHeader (ManagementMessageType (
                       ManagementMessageType::MESSAGE_TYPE_MOB_MSHO_REQ));
   //ss->Enqueue (p, MacHeaderType (), connection);

   //p->sizeof(MshoReq) + m_nbPref*sizeof(MshoReqBsIndex); //replace ns2 p = getPacket ();
   m_rssi = CalculateMaxIRSignalStrength ();

}*/

/*Ptr<SSLinkManager>
YenSSHandover::GetRSSI (void) const
{
  return m_rssi;
}

void 
YenSSHandover::SetRSSI (Ptr<SSLinkManager> rssi)
{
  m_rssi= rssi;
}*/

/*uint16_t
YenSSHandover::CalculateMaxIRSignalStrength (void)
{
  // SS obtains RSSI measurement from the OFDM downlink preambles using a complex formula, page 486
  uint16_t rss = 1;

  if (m_bsEirp == 65535 || m_eirXPIrMax == 65535)
    {
      return GetMinTransmitPowerLevel ();
    }
  else
    {
      return m_eirXPIrMax + m_bsEirp - rss;
    }

  return 0;
}

uint16_t
YenSSHandover::GetMinTransmitPowerLevel (void)
{
  // code to calculate minimum transmit power level of the SS, see page 189 of ammendment
  return 10; // temp
}

Ptr<SubscriberStationNetDevice>
YenSSHandover::GetSS (void) const;
{
  return m_ss;
}

void 
YenSSHandover::SetSS (Ptr<SubscriberStationNetDevice> ss);
{
  m_ss= ss
}*/


/*void
YenSSHandover::Start (void)
{*/
/*inoder to let ss-net-device.cc compiler successful, add it */
//}

/*void
YenSSHandover::Stop (void)
{*/
/*inoder to let ss-net-device.cc compiler successful, add it */
//}

/*bool
YenSSHandover::DoSend (Ptr<Packet> packet,
                       const Mac48Address &source,
                       const Mac48Address &dest,
                       uint16_t protocolNumber)
{
  return 0;*/
/*inoder to let ss-net-device.cc compiler successful, add it */
//}

/*void
YenSSHandover::DoReceive (Ptr<Packet> packet)
{*/
/*inoder to let ss-net-device.cc compiler successful, add it */
//}

/*bool
YenSSHandover::Enqueue (Ptr<Packet> packet,
                        const MacHeaderType &hdrType,
                        Ptr<WimaxConnection> connection)
{
  return 0;*/
/*inoder to let ss-net-device.cc compiler successful, add it */
//}

}// namespace ns3
