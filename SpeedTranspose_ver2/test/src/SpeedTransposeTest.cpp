// -*- C++ -*-
/*!
 * @file  SpeedTransposeTest.cpp
 * @brief Change the wind power data to speed data 
 * @date $Date$
 *
 * $Id$
 */

#include "SpeedTransposeTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* speedtranspose_spec[] =
  {
    "implementation_id", "SpeedTransposeTest",
    "type_name",         "SpeedTransposeTest",
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
SpeedTransposeTest::SpeedTransposeTest(RTC::Manager* manager)
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
SpeedTransposeTest::~SpeedTransposeTest()
{
}



RTC::ReturnCode_t SpeedTransposeTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("speedout", m_speedoutIn);
  
  // Set OutPort buffer
  addOutPort("power1", m_power1Out);
  addOutPort("power2", m_power2Out);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SpeedTransposeTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t SpeedTransposeTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SpeedTransposeTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t SpeedTransposeTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t SpeedTransposeTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t SpeedTransposeTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void SpeedTransposeTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(speedtranspose_spec);
    manager->registerFactory(profile,
                             RTC::Create<SpeedTransposeTest>,
                             RTC::Delete<SpeedTransposeTest>);
  }
  
};


