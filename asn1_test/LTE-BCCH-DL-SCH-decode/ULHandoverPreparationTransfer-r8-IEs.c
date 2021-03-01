/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "EUTRA-RRC-Definitions"
 * 	found in "36331-c10.asn"
 * 	`asn1c -S /usr/local/share/asn1c -fcompound-names -fskeletons-copy -gen-PER`
 */

#include "ULHandoverPreparationTransfer-r8-IEs.h"

static int
memb_meid_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const BIT_STRING_t *st = (const BIT_STRING_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if(st->size > 0) {
		/* Size in bits */
		size = 8 * st->size - (st->bits_unused & 0x07);
	} else {
		size = 0;
	}
	
	if((size == 56)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_meid_constr_3 GCC_NOTUSED = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 0,  0,  56,  56 }	/* (SIZE(56..56)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_ULHandoverPreparationTransfer_r8_IEs_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ULHandoverPreparationTransfer_r8_IEs, cdma2000_Type),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_CDMA2000_Type,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"cdma2000-Type"
		},
	{ ATF_POINTER, 1, offsetof(struct ULHandoverPreparationTransfer_r8_IEs, meid),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BIT_STRING,
		memb_meid_constraint_1,
		&asn_PER_memb_meid_constr_3,
		0,
		"meid"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ULHandoverPreparationTransfer_r8_IEs, dedicatedInfo),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DedicatedInfoCDMA2000,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dedicatedInfo"
		},
	{ ATF_POINTER, 1, offsetof(struct ULHandoverPreparationTransfer_r8_IEs, nonCriticalExtension),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ULHandoverPreparationTransfer_v8a0_IEs,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"nonCriticalExtension"
		},
};
static int asn_MAP_ULHandoverPreparationTransfer_r8_IEs_oms_1[] = { 1, 3 };
static ber_tlv_tag_t asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ULHandoverPreparationTransfer_r8_IEs_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* cdma2000-Type */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* meid */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dedicatedInfo */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 } /* nonCriticalExtension */
};
static asn_SEQUENCE_specifics_t asn_SPC_ULHandoverPreparationTransfer_r8_IEs_specs_1 = {
	sizeof(struct ULHandoverPreparationTransfer_r8_IEs),
	offsetof(struct ULHandoverPreparationTransfer_r8_IEs, _asn_ctx),
	asn_MAP_ULHandoverPreparationTransfer_r8_IEs_tag2el_1,
	4,	/* Count of tags in the map */
	asn_MAP_ULHandoverPreparationTransfer_r8_IEs_oms_1,	/* Optional members */
	2, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ULHandoverPreparationTransfer_r8_IEs = {
	"ULHandoverPreparationTransfer-r8-IEs",
	"ULHandoverPreparationTransfer-r8-IEs",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1,
	sizeof(asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1)
		/sizeof(asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1[0]), /* 1 */
	asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1,	/* Same as above */
	sizeof(asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1)
		/sizeof(asn_DEF_ULHandoverPreparationTransfer_r8_IEs_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ULHandoverPreparationTransfer_r8_IEs_1,
	4,	/* Elements count */
	&asn_SPC_ULHandoverPreparationTransfer_r8_IEs_specs_1	/* Additional specs */
};

