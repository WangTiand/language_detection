#ifndef __LANGUAGE_DETECTION_H__
#define __LANGUAGE_DETECTION_H__ 

typedef enum
{
	SMALL_EN = 1,	//0061-007a    					  		      		小写英语
	BIG_EN,			//0041-005a    							      		大写英语
	ZH,     	    //2e80-2fdf, 3400-4dbf, 4e00-9fff 					汉语
	JA,				//3040-30ff, 31f0-31ff								日语
	KO,				//1100-11ff, 3130-318f, ac00-d7af    				朝鲜语
	RU,				//0400-052f, 0500-052f								俄语(西里尔语)	
	AR,				//0600-06ff, 0750-077f, FB50-FDFF, FE70-FEFF		阿拉伯语
	AV_PA,			//0800-085f						阿维斯塔语与巴列维语	
	ARM,			//0530-058f						亚美尼亚
	BE,				//0980-09FF						孟加拉语
	BL,				//1B00-1B7F						巴厘语
	CK,				//13A0-13FF						切罗基
	CP,				//2c80-2cff						古埃及
	DH,				//0780-07bf						迪维希语(马尔代夫)
	EL,				//0370-03ff,1F00-1FFF								希腊
	ES,				//1200-137F, 1380-139f			埃塞俄比亚
	GM,				//0a00-0a7f						锡克教
	GJ,				//0A80-0AFF						古吉拉特
	GG,				//10A0-10FF						格鲁吉亚
	IW,				//0590-05ff						希伯来
	KN,				//0c80-0cff						卡纳尔
	KM,				//1780-17FF, 19e0-19ff			高棉
	LAO,			//0E80-0EFF											老挝
	LC,				//1C00-1C4F						雷布查语
	MD,				//0860-087f						曼达语
	MA,				//0D00-0D7F						德拉维族
	MM,				//1000-109F											缅甸
	MG,				//1800-18AF						蒙古语
	MP,				//1C80-1CDF						曼尼普尔语
	NK,				//07c0-077f						西非书面语言
	NTL,			//1980-19df						新傣仂语
	OR,				//0b00-0b7f						奥里亚
	OG,				//1680-169F						欧甘字母
	RN,				//16A0-16FF						如尼文
	SYR,			//0700-074f         			叙利亚
	SM,				//0880-08AF						撒玛利亚(巴勒斯坦)
	SN,				//0D80-0DFF											僧伽罗语
	SD,				//1B80-1BB0						巽他语
	TH,				//0e00-0e7f											泰语	
	TM,				//0B80-0BFF											泰米尔
	TL,				//0c00-0c7f						泰卢固
	TT,				//0F00-0FFF						藏文
	TG,				//1700-171F						塔加拉语
	TAL,			//1950-197f						德宏泰语
	UCAS,			//1400-167F						加拿大土著
	BP,				//2800-28FF						盲文
	YS,				//A000-A4CF						彝文	
	VT,				//ab00-ab5f											越南傣语
	EU,				//0-7F,80-FF,100-17F,180-24F,2C60-2C7F,A720-A7FF,AB30-AB6F,1E00-1EFF,FB00-FB06,250-2AF,1D80-1DBF,2100-214F,2460-24FF   印欧语种
	IN,				//0900-097f                                            印度
	LANG_MAX,
	
}LANG_NUM;

void language_init();

int language_detection(char *body, char *language);


#endif
