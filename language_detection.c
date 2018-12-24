#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include <unistd.h>

#include "language_detection.h"
//#include "../nbsis_public.h"

#define DEST_MAXLEN 1024*100
#define strlcpy strncpy

char Unicode[65535] = {0};


typedef struct lang_key_info_
{
	const char *lang_full_name;
}lang_key_info;


lang_key_info language_key[LANG_MAX] = 
	{{""},
	 {"en"},
	 {"en"},
	 {"zh"},
	 {"ja"},
	 {"ko"},
	 {"ru"},
	 {"ar"},
	 {"av&pa"},
	 {"arm"},
	 {"bgd"},
	 {"bl"},
	 {"ck"},
	 {"ae"},
	 {"dh"},
	 {"el"},
	 {"es"},
	 {"gm"},
	 {"gj"},
	 {"gg"},
	 {"iw"},
	 {"kn"},
	 {"km"},
	 {"lao"},
	 {"lc"},
	 {"md"},
	 {"ma"},
	 {"mm"},
	 {"mg"},
	 {"mp"},
	 {"nk"},
	 {"ntl"},
	 {"or"},
	 {"og"},
	 {"rn"},
	 {"syr"},
	 {"sm"},
	 {"sn"},
	 {"sd"},
	 {"th"},
	 {"tm"},
	 {"tl"},
	 {"tt"},
	 {"tg"},
	 {"tal"},
	 {"ucas"},
	 {"bp"},
	 {"ys"},
	 {"vt"},
	 {"eu"},
	 {"in"}};


void language_init()
{
	int i = 0;
	
	memset(Unicode, 0, sizeof(Unicode));

//------------------英语---------------------
	for (i = 0x0061; i <= 0x007a; i++)		//小写英语
		Unicode[i] = SMALL_EN;
	for (i = 0x0041; i <= 0x005a; i++)		//大写英语
		Unicode[i] = SMALL_EN;
	
//------------------汉语---------------------	
	for (i = 0x2e80; i <= 0x2fdf; i++)		
		Unicode[i] = ZH;
	for (i = 0x3400; i <= 0x4dbf; i++)
		Unicode[i] = ZH;
	for (i = 0x4e00; i <= 0x9fff; i++)
		Unicode[i] = ZH;

//------------------日语----------------------
	for (i = 0x3040; i <= 0x30ff; i++)
		Unicode[i] = JA;
	for (i = 0x31f0; i <= 0x31ff; i++)
		Unicode[i] = JA;
	
//------------------朝鲜----------------------
	for (i = 0x1100; i <= 0x11ff; i++)
		Unicode[i] = KO;
	for (i = 0x3130; i <= 0x318f; i++)
		Unicode[i] = KO;
	for (i = 0xac00; i <= 0xd7af; i++)
		Unicode[i] = KO;

//---------------俄语(西里尔语)---------------
	for (i = 0x0400; i <= 0x052f; i++)
		Unicode[i] = RU;

//------------------阿拉伯语------------------
	for (i = 0x0600; i <= 0x06ff; i++)
		Unicode[i] = AR;
	for (i = 0x0750; i <= 0x077f; i++)
		Unicode[i] = AR;
	for (i = 0xFB50; i <= 0xFDFF; i++)
		Unicode[i] = AR;
	for (i = 0xFE70; i <= 0xFEFF; i++)
		Unicode[i] = AR;

//------------阿维斯塔与巴列维�?-------------
	for (i = 0x0800; i <= 0x085f; i++)
		Unicode[i] = AV_PA;

//----------------亚美尼亚�?-----------------
	for (i = 0x0530; i <= 0x058f; i++)
		Unicode[i] = ARM;

//-----------------孟加拉语-------------------
	for (i = 0x0980; i <= 0x09FF; i++)
		Unicode[i] = BE;

//------------------巴厘�?-------------------
	for (i = 0x1B00; i <= 0x1B7F; i++)
		Unicode[i] = BL;
	
//-----------------切罗基语-------------------	
	for (i = 0x13A0; i <= 0x13FF; i++)
		Unicode[i] = CK;

//-----------------古埃及语-------------------
	for (i = 0x2c80; i <= 0x2cff; i++)
		Unicode[i] = CP;

//-----------------迪维希语-------------------
	for (i = 0x0780; i <= 0x07bf; i++)
		Unicode[i] = DH;

//-------------------希腊�?------------------	
	for (i = 0x0370; i <= 0x03ff; i++)
		Unicode[i] = EL;
	for (i = 0x1F00; i <= 0x1FFF; i++)
		Unicode[i] = EL;

//----------------埃塞俄比亚语----------------
	for (i = 0x1200; i <= 0x137F; i++)
		Unicode[i] = ES;
	for (i = 0x1380; i <= 0x139f; i++)
		Unicode[i] = ES;

//------------------锡克教语------------------
	for (i = 0x0a00; i <= 0x0a7f; i++)
		Unicode[i] = GM;

//-----------------古吉拉特�?----------------
	for (i = 0x0A80; i <= 0x0AFF; i++)
		Unicode[i] = GJ;
	
//-----------------格鲁吉亚�?----------------
	for (i = 0x10A0; i <= 0x10FF; i++)
		Unicode[i] = GG;

//------------------希伯来语------------------
	for (i = 0x0590; i <= 0x05ff; i++)
		Unicode[i] = IW;
	
//------------------卡纳尔语------------------
	for (i = 0x0c80; i <= 0x0cff; i++)
		Unicode[i] = KN;

//-------------------高棉�?------------------
	for (i = 0x1780; i <= 0x17FF; i++)
		Unicode[i] = KM;
	for (i = 0x19e0; i <= 0x19ff; i++)
		Unicode[i] = KM;
	
//-------------------老挝�?------------------
	for (i = 0x0E80; i <= 0x0EFF; i++)
		Unicode[i] = LAO;

//------------------雷布查语------------------
	for (i = 0x1C00; i <= 0x1C4F; i++)
		Unicode[i] = LC;
	
//-------------------曼达�?------------------
	for (i = 0x0860; i <= 0x087f; i++)
		Unicode[i] = MD;

//-----------------德拉维族�?----------------
	for (i = 0x0D00; i <= 0x0D7F; i++)
		Unicode[i] = MA;
	
//-------------------缅甸�?------------------
	for (i = 0x1000; i <= 0x109F; i++)
		Unicode[i] = MM;

//-------------------蒙古�?------------------
	for (i = 0x1800; i <= 0x18AF; i++)
		Unicode[i] = MG;

//-----------------曼尼普尔�?----------------
	for (i = 0x1C80; i <= 0x1CDF; i++)
		Unicode[i] = MP;

//-----------------西非书面语言---------------
	for (i = 0x07c0; i <= 0x077f; i++)
		Unicode[i] = NK;
	
//------------------新傣仂语------------------
	for (i = 0x1980; i <= 0x19df; i++)
		Unicode[i] = NTL;

//------------------奥里亚语------------------
	for (i = 0x0b00; i <= 0x0b7f; i++)
		Unicode[i] = OR;

//------------------欧甘字母------------------
	for (i = 0x1680; i <= 0x169F; i++)
		Unicode[i] = OG;
		
//-------------------如尼�?------------------
	for (i = 0x16A0; i <= 0x16FF; i++)
		Unicode[i] = RN;

//------------------叙利亚语------------------
	for (i = 0x0700; i <= 0x074f; i++)
		Unicode[i] = SYR;

//-------------撒玛利亚(巴勒斯坦)-------------
	for (i = 0x0880; i <= 0x08AF; i++)
		Unicode[i] = SM;

//------------------僧伽罗语------------------
	for (i = 0x0D80; i <= 0x0DFF; i++)
		Unicode[i] = SN;
	
//-------------------巽他�?------------------
	for (i = 0x1B80; i <= 0x1BB0; i++)
		Unicode[i] = SD;

//--------------------泰语--------------------
	for (i = 0x0e00; i <= 0x0e7f; i++)
		Unicode[i] = TH;
	
//------------------泰米尔语------------------
	for (i = 0x0B80; i <= 0x0BFF; i++)
		Unicode[i] = TM;
	
//------------------泰卢固语------------------
	for (i = 0x0c00; i <= 0x0c7f; i++)
		Unicode[i] = TL;

//--------------------藏文--------------------
	for (i = 0x0F00; i <= 0x0FFF; i++)
		Unicode[i] = TT;

//------------------塔加拉语------------------
	for (i = 0x1700; i <= 0x171F; i++)
		Unicode[i] = TG;

//------------------德宏泰语------------------
	for (i = 0x1950; i <= 0x197f; i++)
		Unicode[i] = TAL;

//----------------加拿大土著语----------------
	for (i = 0x1400; i <= 0x167F; i++)
		Unicode[i] = UCAS;

//--------------------盲文--------------------
	for (i = 0x2800; i <= 0x28FF; i++)
		Unicode[i] = BP;

//--------------------彝文--------------------
	for (i = 0xA000; i <= 0xA4CF; i++)
		Unicode[i] = YS;

//------------------越南傣语------------------
	for (i = 0xab00; i <= 0xab5f; i++)
		Unicode[i] = VT;

//------------------欧盟语种------------------
//德语,法语,意大利语,葡萄牙语,西班牙语,匈牙利语�?
	for (i = 0x0080; i <= 0x00ff; i++)
		Unicode[i] = EU;
	for (i = 0x0100; i <= 0x017f; i++)
		Unicode[i] = EU;
	for (i = 0x0180; i <= 0x024f; i++)
		Unicode[i] = EU;
	for (i = 0x2c60; i <= 0x2c7f; i++)
		Unicode[i] = EU;
	for (i = 0xa720; i <= 0xa7ff; i++)
		Unicode[i] = EU;
	for (i = 0xab30; i <= 0xab6f; i++)
		Unicode[i] = EU;
	for (i = 0x1eff; i <= 0x1e00; i++)
		Unicode[i] = EU;
	for (i = 0xfb00; i <= 0xfb06; i++)
		Unicode[i] = EU;
	for (i = 0x0250; i <= 0x02af; i++)
		Unicode[i] = EU;
	for (i = 0x1d80; i <= 0x1dbf; i++)
		Unicode[i] = EU;
	for (i = 0x2100; i <= 0x214f; i++)
		Unicode[i] = EU;
	for (i = 0x2460; i <= 0x24ff; i++)
		Unicode[i] = EU;
	
//----------------------��-----------------------
	for (i = 0x0900; i <= 0x097f; i++)
		Unicode[i] = IN;

	//����������
	setlocale(LC_CTYPE, "");

	return ;
}

/* 返回ch字符在sign数组中的序号 */
int getIndexOfSigns(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return ch - '0';
    }
    if(ch >= 'A' && ch <='F') 
    {
        return ch - 'A' + 10;
    }
    if(ch >= 'a' && ch <= 'f')
    {
        return ch - 'a' + 10;
    }
    return -1;
}

/* 十六进制数转换为十进制数 */
int hexToDec(char *source)
{
    int sum = 0;
    int t = 1;
    int i, len;
 
    len = strlen(source);
    for(i=len-1; i>=0; i--)
    {
        sum += t * getIndexOfSigns(*(source + i));
        t *= 16;
    }  
 
    return sum;
}

int language_detection(char *body, char *language)
{
	int ret = 0;
	int w_size = 0;
	int bodylength = 0;
	int wcharlen = 0;

	if (body == NULL || body[0] == '\0')
		return ret;

	bodylength = strlen(body);

	// 设置转义的长度; 最大为10240
	wcharlen = bodylength > 10240 ? 10240 : bodylength;

	// 定义指定长度的缓存空间
	wchar_t dst[wcharlen];
	memset(&dst, 0, sizeof(dst));
	
	//转成宽字�?
	wcharlen = mbstowcs(dst, body, 1000);
	if (wcharlen <= 0)
	{       
		return ret;
	}

	//printf("-------------- bodylen[%d] w_size [%d] --------------\n", bodylength, wcharlen);

	int j = 0;
	int dec = 0;
	int check = 0;
	int lang_det[LANG_MAX];

	memset(lang_det, 0, sizeof(lang_det));

	// 判断内容的语言属性
	for (int i = 0; i < wcharlen; i++)
	{
		dec = dst[i];
		//printf("%d. %x[%d][%d]\n", i+1, u_buf[i], u_buf[i], dec);

		if (dec < 64 || ((dec > 91) && (dec < 96)) || ((dec > 123) && (dec < 191)))
		{
			j++;
		}
		else
		{
			check = Unicode[dec];
			lang_det[check]++;
		}
	}

	// 获取语言
	int first = 0;
	int second = 0;
	int max = 0;
	int premax = 0;
	for (int i = 0; i < LANG_MAX; i++)
	{
		if (lang_det[i] > max)
		{
			premax = max;
			max = lang_det[i];
			second = first;
			first = i;
		}
		else
		{
			if (lang_det[i] > premax)
			{
	
				premax = lang_det[i];
				second = i;
			}
		}
	}

/*
	printf("j = [%d]-- [%d][%d][%d]\n", j, max, premax, wcharlen);

	if (first > 0)
		printf("fount first language [%s][%f]\n", language_key[first].lang_full_name, (max*1.0)/(wcharlen-j));
	if (second > 0)
		printf("fount second language [%s][%f]\n", language_key[second].lang_full_name, (premax*1.0)/(wcharlen-j));
*/
	if (first > 0 && second > 0)
	{
		sprintf(language, "%s,%s", language_key[first].lang_full_name, language_key[second].lang_full_name);
		ret = 2;
	}
	else if (first > 0)
	{
		sprintf(language, "%s", language_key[first].lang_full_name);
		ret = 1;
	}

	//printf("language --- [%s]\n",language);

	return ret;
}

