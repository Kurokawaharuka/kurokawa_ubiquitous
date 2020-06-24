// -*- C++ -*-
/*!
 * @file  SpeedTranspose.cpp
 * @brief Change the wind power data to speed data 
 * @date $Date$
 *
 * $Id$
 */

#include "SpeedTranspose.h"

// Module specification
// <rtc-template block="module_spec">
static const char* speedtranspose_spec[] =
  {
    "implementation_id", "SpeedTranspose",
    "type_name",         "SpeedTranspose",
    "description",       "Change the wind power data to speed data ",
    "version",           "1.0.0",
    "vendor",            "VenderName",
    "category",          "Category",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
SpeedTranspose::SpeedTranspose(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_power1In("power1", m_power1),
    m_power2In("power2", m_power2),
    m_speedoutOut("speedout", m_speedout)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
SpeedTranspose::~SpeedTranspose()
{
}



RTC::ReturnCode_t SpeedTranspose::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("power1", m_power1In);
  addInPort("power2", m_power2In);
  
  // Set OutPort buffer
  addOutPort("speedout", m_speedoutOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SpeedTranspose::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SpeedTranspose::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SpeedTranspose::onDeactivated(RTC::UniqueId ec_id)
{
    m_speedout.data.vx = 0;
    m_speedoutOut.write();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SpeedTranspose::onExecute(RTC::UniqueId ec_id)
{
  
    if (m_power1In.isNew()) {
        m_power1In.read();

    }
    if (m_power2In.isNew()) {
        m_power2In.isNew();
    }
    
        m_speedout.data.vx = (1.5 * (m_power1.data - m_power2.data)) / 100;
        m_speedoutOut.write();

  return RTC::RTC_OK;
} 

/*
RTC::ReturnCode_t SpeedTranspose::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTranspose::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SpeedTransposeInit(RTC::Manager* manager)
  {
    coil::Properties profile(speedtranspose_spec);
    manager->registerFactory(profile,
                             RTC::Create<SpeedTranspose>,
                             RTC::Delete<SpeedTranspose>);
  }
  
};


