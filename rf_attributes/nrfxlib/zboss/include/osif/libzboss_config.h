/*
 * Copyright (c) 2020 Nordic Semiconductor ASA
 *
 * SPDX-License-Identifier: LicenseRef-BSD-5-Clause-Nordic
 */

#ifndef LIBZBOSS_CONFIG_H__
#define LIBZBOSS_CONFIG_H__

/**
 * This is an autogenerated file.
 * Please use Kconfig to change it.
 */


/**
 * NCP trasnport type - Serial (UART)
 */
/* #undef CONFIG_ZB_NCP_TRANSPORT_TYPE_SERIAL */

/**
 * Enable UART serial interface for ZBOSS CLI
 */
/* #undef CONFIG_ZB_HAVE_SERIAL */

/**
 * Serial (SPI) [UNSUPPORTED]
 */
/* #undef CONFIG_ZB_NCP_TRANSPORT_TYPE_SPI */

/**
 * Simulator (linux pipe) [UNSUPPORTED]
 */
/* #undef CONFIG_ZB_NCP_TRANSPORT_TYPE_NSNG */

/**
 * Enable ZBOSS TRACE subsystem in NCP firmware
 */
/* #undef CONFIG_ZB_NCP_DEBUG */

/**
 * Compiled-in trace mask of ZBOSS stack logs
 *
 * Selectively enable Zigbee binary trace logs.
 * The mask value should be a bitwise OR of values assigned to selected modules.
 *
 * Available modules are:
 *
 * - 0x4000 Zigbee Green Power
 * - 0x0800 Application
 * - 0x0200 Zigbee Light Link
 * - 0x0100 Zigbee Cluster Library
 * - 0x0080 Security
 * - 0x0040 Zigbee Device Object
 * - 0x0010 Application Support layer
 * - 0x0008 Network layer
 * - 0x0004 MAC layer
 * - 0x0002 Memory management
 * - 0x0001 Common
 *
 * For example, in order to enable traces related to OTA DFU,
 * one should set this option to 0x4100.
 *
 * Note: For general debugging purposes, please use 0x0C48.
 */
#define CONFIG_ZB_TRACE_MASK 0x0000

/**
 * Max compiled-in log level for ZBOSS traces - Off
 */
/* #undef CONFIG_ZB_LOG_LEVEL_OFF */

/**
 * Max compiled-in log level for ZBOSS traces - Error
 */
/* #undef CONFIG_ZB_LOG_LEVEL_ERR */

/**
 * Max compiled-in log level for ZBOSS traces - Warning
 */
#define CONFIG_ZB_LOG_LEVEL_WRN y

/**
 * Max compiled-in log level for ZBOSS traces - Info
 */
/* #undef CONFIG_ZB_LOG_LEVEL_INF */

/**
 * Max compiled-in log level for ZBOSS traces - Debug
 */
/* #undef CONFIG_ZB_LOG_LEVEL_DBG */

/**
 * ZB_TRACE_LOG_LEVEL
 */
#define CONFIG_ZB_TRACE_LOG_LEVEL 2

/**
 * Initialize and flush logger directly from ZBOSS kernel
 */
/* #undef CONFIG_ZB_ASYNC_TRACE_CONTROL */

/**
 * Enable test commands
 *
 * Enable reception of test commands on UART interface
 * (enabled in ZBOSS test configs only)
 */
/* #undef CONFIG_ZB_NRF_TRACE_RX_ENABLE */

/**
 * NVRAM migration
 *
 * Include procedures to migrate legacy NVRAM structures
 */
#define CONFIG_ZB_NVRAM_ENABLE_VER_MIGRATION y

/**
 * Finding and Binding
 *
 * Enable finding and binding, as defined in BDB specification
 */
#define CONFIG_ZB_BDB_ENABLE_FINDING_BINDING y

/**
 * Distributed security
 *
 * Enable forming and joining Zigbee networks with distributed security
 */
#define CONFIG_ZB_DISTRIBUTED_SECURITY_ON y

/**
 * Install codes
 *
 * Enable commissioning with install codes
 */
#define CONFIG_ZB_SECURITY_INSTALLCODES y

/**
 * Production configuration
 *
 * Enable production configuration
 */
#define CONFIG_ZB_PRODUCTION_CONFIG y

/**
 * APS user frames
 *
 * Include API to send raw APS frames
 */
#define CONFIG_ZB_APS_USER_PAYLOAD y

/**
 * NWK security API
 *
 * Include API to disable NWK security
 */
#define CONFIG_ZB_LOW_SECURITY_MODE y

/**
 * APS fragmentation
 *
 * Enable APS fragmentation inside ZBOSS
 */
#define CONFIG_ZB_APS_FRAGMENTATION y

/**
 * PAN ID blacklist
 *
 * Enable PAN ID blacklisting during rejoin
 */
#define CONFIG_ZB_NWK_BLACKLIST y

/**
 * PAN ID blacklist length
 */
#define CONFIG_ZB_NWK_BLACKLIST_SIZE 16

/**
 * WWAH cluster
 *
 * Include Works With All Hubs cluster
 */
#define CONFIG_ZB_ZCL_SUPPORT_CLUSTER_WWAH y

/**
 * WWAH cluster - WWAHu client
 *
 * Include WWAHu cluster client implementation
 */
#define CONFIG_ZB_ZCL_ENABLE_WWAH_CLIENT y

/**
 * WWAH cluster - WWAHu server
 *
 * Include WWAHu cluster server implementation
 */
#define CONFIG_ZB_ZCL_ENABLE_WWAH_SERVER y

/**
 * WWAHu server - NWK retransmissions
 *
 * Enable retransmissions on NWK layer
 */
#define CONFIG_ZB_NWK_RETRY_COUNT y

/**
 * WWAHu server - Beacon survey
 *
 * Enable beacon survey
 */
#define CONFIG_ZB_BEACON_SURVEY y

/**
 * WWAHu server - Parent classification
 *
 * Enable parent classification
 */
#define CONFIG_ZB_PARENT_CLASSIFICATION y

/**
 * Check for Out Of Memory state
 *
 * If Zigbee packet buffer pool is in OOM state for a period, specified
 * by ZB_OOM_THRESHOLD, then assertion is triggered.
 */
/* #undef CONFIG_ZB_CHECK_OOM_STATUS */

/**
 * Check for Out Of Memory state - Generate NWK status frame in OOM
 *
 * Send broadcast frame once OOM state is detected.
 */
/* #undef CONFIG_ZB_SEND_OOM_STATUS */

/**
 * Touchlink commissioning (experimental)
 */
/* #undef CONFIG_ZB_BDB_TOUCHLINK */

/**
 * Certification specific behavior
 *
 * Enable behaviors specific to golden devices used during certification
 */
/* #undef CONFIG_ZB_CERTIFICATION_HACKS */

/**
 * Enable Zigbee profile, used by verification framework
 */
/* #undef CONFIG_ZB_TEST_PROFILE */

/**
 * Serial console RX timeout
 */
#define CONFIG_ZB_MULTITEST_CONSOLE_SLEEP_TIMEOUT 4000000

/**
 * Disable TRACE_FILE_ID assert
 *
 * Disable sanity check for ZB_TRACE_FILE_ID macro definition in each file
 */
#define CONFIG_ZB_DONT_NEED_TRACE_FILE_ID y

/**
 * Enable busy loop in GP implementation
 *
 * While communicating with Green Power device, ZBOSS will wait before issuing
 * mcps-data.req in a busy loop instead of using MAC features
 */
/* #undef CONFIG_ZB_MAC_AUTO_DELAY_IN_MAC_GP_SEND */

/**
 * NWK requests with aliases
 *
 * Enables making NWK requests with aliases (see sec. 3.2.1.1.1) or
 * R21 Zigbee PRO specification)
 */
/* #undef CONFIG_ZB_USEALIAS */

/**
 * MAC filtering
 *
 * Enables filtering frames at MAC level, based on device's short or
 * long address
 */
/* #undef CONFIG_ZB_LIMIT_VISIBILITY */

/**
 * PAN ID translation table size
 *
 * NWK: size of the long-short Pan ID translation table
 *
 * Must be <= (packet buffer size - sizeof(*discovery_confirm)) /
 *            sizeof(*network_descriptor)
 * That value limits number of Pan IDs visible for device during active scan.
 */
#define CONFIG_ZB_PANID_TABLE_SIZE 28

/**
 * long addresses compression table size
 *
 * Size of table used for long addresses compression: 3 bytes of
 * manufacturer id.
 *
 * ZBOSS implements long address compression: 3 bytes of manufacturer
 * id are stored in the separate table; reference to manufacturer
 * entry is stored in the long address giving 2 bytes economy.
 *
 * That is an absolute limit of number of manufacturers known to the device.
 *
 * Note: All that machinery will not work if instead of legal
 * manufacturer ids (or illegal, but fixed ids) use random values.
 */
#define CONFIG_ZB_DEV_MANUFACTURER_TABLE_SIZE 32

/**
 * Packet buffer wait queue size
 *
 * Size of queue for wait for free packet buffer
 *
 * Note: To prevent deadlocks ZB_BUF_Q_SIZE must be < ZB_IOBUF_POOL_SIZE/2
 */
#define CONFIG_ZB_BUF_Q_SIZE 8

/**
 * ZDO transactions table size
 */
#define CONFIG_ZB_ZDO_TRAN_TABLE_SIZE 16

/**
 * number of endpoints per APS group table entry
 */
#define CONFIG_ZB_APS_ENDPOINTS_IN_GROUP_TABLE 8

/**
 * Broadcast transaction record table size
 *
 * See Zigbee Specification subclause 3.6.5
 */
#define CONFIG_ZB_NWK_BTR_TABLE_SIZE 16

/**
 * Broadcast Retransmission table size
 */
#define CONFIG_ZB_NWK_BRR_TABLE_SIZE 16

/**
 * Number of endpoints
 *
 * Maximum number of supported endpoints per device
 */
#define CONFIG_ZB_MAX_EP_NUMBER 6

/**
 * Number of supported APS groups
 */
#define CONFIG_ZB_APS_GROUP_TABLE_SIZE 16

/**
 * Green Power Sink table size
 */
#define CONFIG_ZB_ZGP_SINK_TBL_SIZE 24

/**
 * Green Power Proxy table size
 */
#define CONFIG_ZB_ZGP_PROXY_TBL_SIZE 5

/**
 * Dynamic memory configuration
 *
 * Enable dynamic memory configuration feature that allows to change memory
 * footprint if application uses ZBOSS binaries
 */
#define CONFIG_ZB_CONFIGURABLE_MEM y

/**
 * Dynamic memory configuration - Expected overall network size
 */
#define CONFIG_ZB_CONFIG_OVERALL_NETWORK_SIZE 128

/**
 * Expected Zigbee traffic intensity - high
 */
#define CONFIG_ZB_CONFIG_HIGH_TRAFFIC y

/**
 * Expected Zigbee traffic intensity - moderate
 */
/* #undef CONFIG_ZB_CONFIG_MODERATE_TRAFFIC */

/**
 * Expected Zigbee traffic intensity - light
 */
/* #undef CONFIG_ZB_CONFIG_LIGHT_TRAFFIC */

/**
 * Expected Zigbee application complexity - complex
 */
#define CONFIG_ZB_CONFIG_APPLICATION_COMPLEX y

/**
 * Expected Zigbee application complexity - moderate
 */
/* #undef CONFIG_ZB_CONFIG_APPLICATION_MODERATE */

/**
 * Expected Zigbee application complexity - simple
 */
/* #undef CONFIG_ZB_CONFIG_APPLICATION_SIMPLE */

/**
 * Dynamic memory configuration - Source APS binding table size
 */
/* #undef CONFIG_ZB_APS_SRC_BINDING_TABLE_SIZE */

/**
 * Dynamic memory configuration - Destination APS binding table size
 */
/* #undef CONFIG_ZB_APS_DST_BINDING_TABLE_SIZE */

/**
 * Dynamic memory configuration - Number of packet buffers
 */
/* #undef CONFIG_ZB_IOBUF_POOL_SIZE */

/**
 * Dynamic memory configuration - Packet buffer wait queue size
 *
 * Scheduler callbacks queue size
 */
/* #undef CONFIG_ZB_SCHEDULER_Q_SIZE */

#endif /* LIBZBOSS_CONFIG_H__ */
