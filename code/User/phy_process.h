#ifndef __FOLD_H__ 
#define __FOLD_H__ 

#include "includes.h"
#include "radio_para.h"

#define FRAME_TYPE_TIME_SYNCH   0x01
#define FRAME_TYPE_BSM          0x02
#define FRAME_TYPE_WARN_ACK     0x03
#define FRAME_TYPE_WARN         0x04//簇间通信类型




#define SLOT_LENGTH (1000)//假设簇内10个节点,periodlength 
#define PEROID_LENGTH (10000)
#define GUARD_PERIOD 100



void packet_input_arch(void);

typedef struct PhyRadioMsg {
	uint8_t fcfl;
        uint8_t fcfh;
	uint8_t seq;
        
        uint8_t dest_pidl;
        uint8_t dest_pidh; 

        uint8_t des_addrl;
        uint8_t des_addrh;
        
        uint8_t src_addrl;
        uint8_t src_addrh;

        uint8_t frame_type;

        uint16_t danger;
        uint16_t moteid;
        uint16_t network_id;
        uint32_t time_stamp;
}PhyRadioMsg;

typedef struct mac {
        uint8_t  IsSyched;
        uint32_t time_stamp;
        int32_t  time_offset;
        void (*timeoffset)(struct mac *macpara,uint32_t time);
        rtimer_clock_t (*get_synch_time)(struct mac *macpara);
}macfct;

extern macfct mac;
void frame_init(PhyRadioMsg * msg,uint16_t frametype);   
rtimer_clock_t get_synch_time();
void timeoffset_calc(macfct *macpara,uint32_t time);
void tdmasend(void *ptr);
#endif