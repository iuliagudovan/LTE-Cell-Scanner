/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#ifndef	_SupportedBandCombination_r10_H_
#define	_SupportedBandCombination_r10_H_


#include <asn_application.h>

/* Including external dependencies */
#include <asn_SEQUENCE_OF.h>
#include <constr_SEQUENCE_OF.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Forward declarations */
struct BandCombinationParameters_r10;

/* SupportedBandCombination-r10 */
typedef struct SupportedBandCombination_r10 {
	A_SEQUENCE_OF(struct BandCombinationParameters_r10) list;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} SupportedBandCombination_r10_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_SupportedBandCombination_r10;

#ifdef __cplusplus
}
#endif

/* Referred external types */
#include "BandCombinationParameters-r10.h"

#endif	/* _SupportedBandCombination_r10_H_ */
#include <asn_internal.h>
