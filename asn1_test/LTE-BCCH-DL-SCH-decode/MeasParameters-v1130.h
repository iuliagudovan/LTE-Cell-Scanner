/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#ifndef	_MeasParameters_v1130_H_
#define	_MeasParameters_v1130_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeEnumerated.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MeasParameters_v1130__rsrqMeasWideband_r11 {
	MeasParameters_v1130__rsrqMeasWideband_r11_supported	= 0
} e_MeasParameters_v1130__rsrqMeasWideband_r11;

/* MeasParameters-v1130 */
typedef struct MeasParameters_v1130 {
	long	*rsrqMeasWideband_r11	/* OPTIONAL */;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MeasParameters_v1130_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_rsrqMeasWideband_r11_2;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_MeasParameters_v1130;

#ifdef __cplusplus
}
#endif

#endif	/* _MeasParameters_v1130_H_ */
#include <asn_internal.h>
