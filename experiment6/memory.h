#ifndef DRAM_H
#define DRAM_H

#include <systemc.h>
#include <iostream>
#include <tlm.h>

// TODO add your code here
#define MEM_ACCESS_TIME_NS 20

template<int mem_size = 1024>
class memory : sc_module, tlm::tlm_fw_transport_if<>
{
private:
   unsigned char mem[mem_size];

public:
   tlm::tlm_target_socket<> tSocket;

   SC_CTOR(memory) : tSocket("tSocket")
   {
       tSocket.bind(*this); /* "inform" to the tSocket that this class is implementing it */
   }


   void b_transport(tlm::tlm_generic_payload &trans, sc_time &delay)
   {
       if (trans.get_address() >= mem_size) {
           trans.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
           SC_REPORT_FATAL(this->name(), "Memory address out or range");
           return;
       }
/*
       if (trans.get_data_length() != 1) {
           trans.set_response_status(tlm::TLM_ADDRESS_ERROR_RESPONSE);
           SC_REPORT_FATAL(this->name(), "Memory word is 1 byte long, data length = sizeof(char)");
       }
*/
       if (trans.get_command() == tlm::TLM_WRITE_COMMAND) {
           memcpy(&mem[trans.get_address()],
                  trans.get_data_ptr(),
                  trans.get_data_length());
       }
       else if (trans.get_command() == tlm::TLM_READ_COMMAND) {
           memcpy(trans.get_data_ptr(),
                  &mem[trans.get_address()],
                  trans.get_data_length());
       }

       delay = delay + sc_time(MEM_ACCESS_TIME_NS, SC_NS);
       trans.set_response_status(tlm::TLM_OK_RESPONSE);
   }

   /* Dummy method, must be implemented by the interface */
   virtual tlm::tlm_sync_enum nb_transport_fw(tlm::tlm_generic_payload &trans,
                                              tlm::tlm_phase &phase,
                                              sc_time &t)
   {
       SC_REPORT_FATAL(this->name(), "nb_transport_fw is not implemented");
       return tlm::TLM_ACCEPTED;
   }

   /* Dummy method, must be implemented by the interface */
   bool get_direct_mem_ptr(tlm::tlm_generic_payload &trans,
                           tlm::tlm_dmi &dmi_data)
   {
       SC_REPORT_FATAL(this->name(), "get_direct_mem_ptr is not implemented");
       return false;
   }

   /* Dummy method, must be implemented by the interface */
   unsigned int transport_dbg(tlm::tlm_generic_payload& trans)
   {
       SC_REPORT_FATAL(this->name(),"transport_dbg is not implemented");
       return 0;
   }
};
#endif // DRAM_H
