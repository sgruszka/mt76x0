/*
 Repeat this from vendor driver, RF sections
*/
#ifndef _MT76X0_PHY_H_
#define _MT76X0_PHY_H_

#define RF_R00			0
#define RF_R01			1
#define RF_R02			2
#define RF_R03			3
#define RF_R04			4
#define RF_R05			5
#define RF_R06			6
#define RF_R07			7
#define RF_R08			8
#define RF_R09			9
#define RF_R10			10
#define RF_R11			11
#define RF_R12			12
#define RF_R13			13
#define RF_R14			14
#define RF_R15			15
#define RF_R16			16
#define RF_R17			17
#define RF_R18			18
#define RF_R19			19
#define RF_R20			20
#define RF_R21			21
#define RF_R22			22
#define RF_R23			23
#define RF_R24			24
#define RF_R25			25
#define RF_R26			26
#define RF_R27			27
#define RF_R28			28
#define RF_R29			29
#define RF_R30			30
#define RF_R31			31
#define	RF_R32			32
#define	RF_R33			33
#define	RF_R34			34
#define	RF_R35			35
#define	RF_R36			36
#define	RF_R37			37
#define	RF_R38			38
#define	RF_R39			39
#define	RF_R40			40
#define	RF_R41			41
#define	RF_R42			42
#define	RF_R43			43
#define	RF_R44			44
#define	RF_R45			45
#define	RF_R46			46
#define	RF_R47			47
#define	RF_R48			48
#define	RF_R49			49
#define	RF_R50			50
#define	RF_R51			51
#define	RF_R52			52
#define	RF_R53			53
#define	RF_R54			54
#define	RF_R55			55
#define	RF_R56			56
#define	RF_R57			57
#define	RF_R58			58
#define	RF_R59			59
#define	RF_R60			60
#define	RF_R61			61
#define	RF_R62			62
#define	RF_R63			63
#define	RF_R64			64
#define	RF_R65			65
#define	RF_R66			66
#define	RF_R67			67
#define	RF_R68			68
#define	RF_R69			69
#define	RF_R70			70
#define	RF_R71			71
#define	RF_R72			72
#define	RF_R73			73
#define	RF_R74			74
#define	RF_R75			75
#define	RF_R76			76
#define	RF_R77			77
#define	RF_R78			78
#define	RF_R79			79
#define	RF_R126			126
#define	RF_R127			127

#define RF_G_BAND 	0x0100
#define RF_A_BAND 	0x0200
#define RF_A_BAND_LB	0x0400
#define RF_A_BAND_MB	0x0800
#define RF_A_BAND_HB	0x1000
#define RF_A_BAND_11J	0x2000

#define RF_BW_20        1
#define RF_BW_40        2
#define RF_BW_10        4
#define RF_BW_80        8

#define RF_BANK0	0
#define RF_BANK1	1
#define RF_BANK2	2
#define RF_BANK3	3
#define RF_BANK4	4
#define RF_BANK5	5
#define RF_BANK6	6
#define RF_BANK7	7
#define RF_BANK8	8
#define RF_BANK9	9
#define RF_BANK10	10
#define RF_BANK11	11
#define RF_BANK12	12
#define RF_BANK13	13
#define RF_BANK14	14
#define RF_BANK15	15

#define MT_RF(bank, reg) ((bank) << 16 | (reg))
#define MT_RF_BANK(offset) (offset >> 16)
#define MT_RF_REG(offset) (offset & 0xff)

struct mt76x0_bbp_switch_item {
	u16 bw_band;
	struct mt76_reg_pair reg_pair;
};

struct mt76x0_rf_switch_item {
	u32 rf_bank_reg;
	u16 bw_band;
	u8 value;
};

struct mt76x0_freq_item {
	u8 channel;
	u32 band;
	u8 pllR37;
	u8 pllR36;
	u8 pllR35;
	u8 pllR34;
	u8 pllR33;
	u8 pllR32_b7b5;
	u8 pllR32_b4b0; /* PLL_DEN (Denomina - 8) */
	u8 pllR31_b7b5;
	u8 pllR31_b4b0; /* PLL_K (Nominator *)*/
	u8 pllR30_b7;	/* sdm_reset_n */
	u8 pllR30_b6b2; /* sdmmash_prbs,sin */
	u8 pllR30_b1;	/* sdm_bp */
	u16 pll_n;	/* R30<0>, R29<7:0> (hex) */	
	u8 pllR28_b7b6; /* isi,iso */
	u8 pllR28_b5b4;	/* pfd_dly */
	u8 pllR28_b3b2;	/* clksel option */
	u32 pll_sdm_k;	/* R28<1:0>, R27<7:0>, R26<7:0> (hex) SDM_k */
	u8 pllR24_b1b0;	/* xo_div */
};

struct mt76x0_rate_pwr_item {
	s8 mcs_power;
	u8 rf_pa_mode;
};

struct mt76x0_rate_pwr_tab {
	struct mt76x0_rate_pwr_item cck[4];
	struct mt76x0_rate_pwr_item ofdm[8];
	struct mt76x0_rate_pwr_item ht[8];
	struct mt76x0_rate_pwr_item vht[10];
	struct mt76x0_rate_pwr_item stbc[8];
	struct mt76x0_rate_pwr_item mcs32;
};

#endif /* _MT76X0_PHY_H_ */
