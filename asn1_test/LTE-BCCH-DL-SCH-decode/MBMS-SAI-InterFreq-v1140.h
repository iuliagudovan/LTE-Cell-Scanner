/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#ifndef	_MBMS_SAI_InterFreq_v1140_H_
#define	_MBMS_SAI_InterFreq_v1140_H_


#include <asn_application.h>

/* Including external dependencies */
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct MultiBandInfoList_r11;

/* MBMS-SAI-InterFreq-v1140 */
typedef struct MBMS_SAI_InterFreq_v1140 {
	struct MultiBandInfoList_r11	*multiBandInfoList_r11	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMS_SAI_InterFreq_v1140_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMS_SAI_InterFreq_v1140;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "MultiBandInfoList-r11.h"

#endif	/* _MBMS_SAI_InterFreq_v1140_H_ */
#include <asn_internal.h>
