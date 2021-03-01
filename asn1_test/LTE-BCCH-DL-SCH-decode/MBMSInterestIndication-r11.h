/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#ifndef	_MBMSInterestIndication_r11_H_
#define	_MBMSInterestIndication_r11_H_


#include <asn_application.h>

/* Including external dependencies */
#include "MBMSInterestIndication-r11-IEs.h"
#include <NULL.h>
#include <constr_CHOICE.h>
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum MBMSInterestIndication_r11__criticalExtensions_PR {
	MBMSInterestIndication_r11__criticalExtensions_PR_NOTHING,	/* No components present */
	MBMSInterestIndication_r11__criticalExtensions_PR_c1,
	MBMSInterestIndication_r11__criticalExtensions_PR_criticalExtensionsFuture
} MBMSInterestIndication_r11__criticalExtensions_PR;
typedef enum MBMSInterestIndication_r11__criticalExtensions__c1_PR {
	MBMSInterestIndication_r11__criticalExtensions__c1_PR_NOTHING,	/* No components present */
	MBMSInterestIndication_r11__criticalExtensions__c1_PR_interestIndication_r11,
	MBMSInterestIndication_r11__criticalExtensions__c1_PR_spare3,
	MBMSInterestIndication_r11__criticalExtensions__c1_PR_spare2,
	MBMSInterestIndication_r11__criticalExtensions__c1_PR_spare1
} MBMSInterestIndication_r11__criticalExtensions__c1_PR;

/* MBMSInterestIndication-r11 */
typedef struct MBMSInterestIndication_r11 {
	struct MBMSInterestIndication_r11__criticalExtensions {
		MBMSInterestIndication_r11__criticalExtensions_PR present;
		union MBMSInterestIndication_r11__criticalExtensions_u {
			struct MBMSInterestIndication_r11__criticalExtensions__c1 {
				MBMSInterestIndication_r11__criticalExtensions__c1_PR present;
				union MBMSInterestIndication_r11__criticalExtensions__c1_u {
					MBMSInterestIndication_r11_IEs_t	 interestIndication_r11;
					NULL_t	 spare3;
					NULL_t	 spare2;
					NULL_t	 spare1;
				} choice;
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} c1;
			struct MBMSInterestIndication_r11__criticalExtensions__criticalExtensionsFuture {
				
				/* Context for parsing across buffer boundaries */
				asn_struct_ctx_t _asn_ctx;
			} criticalExtensionsFuture;
		} choice;
		
		/* Context for parsing across buffer boundaries */
		asn_struct_ctx_t _asn_ctx;
	} criticalExtensions;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} MBMSInterestIndication_r11_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_MBMSInterestIndication_r11;

#ifdef __cplusplus
}
#endif

#endif	/* _MBMSInterestIndication_r11_H_ */
#include <asn_internal.h>
