/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#ifndef	_UplinkPowerControlCommon_v1020_H_
#define	_UplinkPowerControlCommon_v1020_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10 {
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF_1	= 0,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF0	= 1,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF1	= 2,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF2	= 3,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF3	= 4,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF4	= 5,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF5	= 6,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10_deltaF6	= 7
} e_UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format3_r10;
typedef enum UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10 {
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10_deltaF1	= 0,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10_deltaF2	= 1,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10_spare2	= 2,
	UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10_spare1	= 3
} e_UplinkPowerControlCommon_v1020__deltaF_PUCCH_Format1bCS_r10;

/* UplinkPowerControlCommon-v1020 */
typedef struct UplinkPowerControlCommon_v1020 {
	long	 deltaF_PUCCH_Format3_r10;
	long	 deltaF_PUCCH_Format1bCS_r10;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} UplinkPowerControlCommon_v1020_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_deltaF_PUCCH_Format3_r10_2;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_deltaF_PUCCH_Format1bCS_r10_11;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_UplinkPowerControlCommon_v1020;

#ifdef __cplusplus
}
#endif

#endif	/* _UplinkPowerControlCommon_v1020_H_ */
#include <asn_internal.h>
