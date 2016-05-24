#ifndef TCM_CRYPTO_DEFINE
#define TCM_CRYPTO_DEFINE

#ifdef __cplusplus
extern "C"
{
#endif //__cplusplus

extern int nTCM_Crypto;

int fnTCM_Crypto(void);

unsigned char SMS4_Encryption(
	unsigned char *key,			/* 16�ֽ� */
	unsigned char *plaintext,		/* ���� */
	unsigned short plaintextlen,	/* ���ĳ��� */
	unsigned char *ciphertext,	/* ������� */
	unsigned short *ciphertextlen, /* ������16��������,�������ĳ��ȶ�16�ֽ� ( plaintextlen /16 +1) * 16 */
	unsigned char *IV				/* ��ʼ���� 16�ֽ� */
	);

unsigned char SMS4_Decryption(
	unsigned char *key,				/* �̶�����Ϊ16�ֽ� */
	unsigned char *ciphertext,		/* ���� */
	unsigned short ciphertextlen,		/* ���ĳ���,�϶���16�ֽڶ��� */
	unsigned char *plaintext,			/* ���� */
	unsigned short *plaintextlen,		/* ���ĳ��� */
	unsigned char *IV					/* ��ʼ����,16�ֽڳ�*/
	);

unsigned char eccDecrypt(unsigned char *pM,unsigned char *pPDKey,unsigned char *pC,unsigned long Clen);
unsigned char eccEncrypt(unsigned char *pC,unsigned char *pPxKey, unsigned char *pPyKey,unsigned char *pM, unsigned long MLen);
void eccHash(unsigned char *pHV,unsigned char *pSV,unsigned short SLen);
unsigned char eccKeyGen(unsigned char * pDKey,unsigned char *pPxKey,unsigned char *pPyKey);
//unsigned char eccSign(unsigned char *pR, unsigned char *pS, unsigned char *pDa, unsigned char *pZa, unsigned char *pM, unsigned long MLen);
//unsigned char eccCfm(unsigned char *pPkx, unsigned char *pPky, unsigned char *pR, unsigned char *pS, unsigned char *pZa, unsigned char *pM, unsigned long MLen);
unsigned char hash_start(unsigned int *maxinlen);

unsigned char hash_updata(
	unsigned char *pText,		/* SM3 ��������Ϣ */
	unsigned short TextLength	/* SM3������Ϣ���� */
	);

unsigned char hash_complete(  
	unsigned char *pText,		/* SM3 ��������Ϣ */
	unsigned short TextLength,	/* SM3������Ϣ���� */
	unsigned char *pOutputData,
	unsigned int *outputlen
	);
unsigned char eccGetKeyExchange( unsigned char *pAPriKey, unsigned char *pARxPoint, unsigned char *pArx, unsigned char *pIDA, unsigned short ulenIDA, unsigned char tag, unsigned char *pBPubKey, unsigned char *pBRxPoint, unsigned char *pIDB,unsigned short ulenIDB, unsigned char *pKA, unsigned char *pS1, unsigned char *pSA);
void eccSetUserMessageData(unsigned long ulUserIDSize, unsigned char *rgbUserID, unsigned long ulMessageSize, unsigned char *rgbMessage, unsigned char *x, unsigned char *y, unsigned char *rgbHashData);
void eccHashSign(unsigned char *rgbHashData, unsigned char *rgbKeyDb, unsigned char *rs);
unsigned char eccVerifySignature(unsigned char *rgbHashData, unsigned char *rgbKeyPb, unsigned char *rs);
void Z_Gen(unsigned char *z, unsigned int klen, unsigned char *ID, unsigned char *x, unsigned char *y);
#ifdef __cplusplus
}
#endif //__cplusplus
#endif
