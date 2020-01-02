
#ifndef __BQ25892_HEADER__
#define __BQ25892_HEADER__

/* Variant-specific configuration */
#ifndef BQ25892_DEVICE_ID
#define BQ25892_ADDR			   0x6B
#define BQ25892_DEVICE_ID          BQ25892_ADDR
#else
#error BQ2589X unknown variant
#endif

/* Register 00h */
#define BQ25892_REG_00      		0x00
#define BQ25892_ENHIZ_MASK		    0x80
#define BQ25892_ENHIZ_SHIFT		    7
#define BQ25892_HIZ_ENABLE          1
#define BQ25892_HIZ_DISABLE         0
#define BQ25892_ENILIM_MASK		    0x40
#define BQ25892_ENILIM_SHIFT		6
#define BQ25892_ENILIM_ENABLE       1
#define BQ25892_ENILIM_DISABLE      0

#define BQ25892_IINLIM_MASK		    0x3F
#define BQ25892_IINLIM_SHIFT		0
#define BQ25892_IINLIM_BASE         100
#define BQ25892_IINLIM_LSB          50

/* Register 01h */
#define BQ25892_REG_01		    	0x01
#define BQ25892_BHOT_MASK           0xC0
#define BQ25892_BHOT_SHIFT          6
#define BQ25892_BCOLD_MASK          0x20
#define BQ25892_BCOLD_SHIFT         5
#define BQ25892_VINDPMOS_MASK       0x1F
#define BQ25892_VINDPMOS_SHIFT      0

#define BQ25892_VINDPMOS_BASE       0
#define BQ25892_VINDPMOS_LSB        100


/* Register 0x02 */
#define BQ25892_REG_02              0x02
#define BQ25892_CONV_START_MASK      0x80
#define BQ25892_CONV_START_SHIFT     7
#define BQ25892_CONV_START           0
#define BQ25892_CONV_RATE_MASK       0x40
#define BQ25892_CONV_RATE_SHIFT      6
#define BQ25892_ADC_CONTINUE_ENABLE  1
#define BQ25892_ADC_CONTINUE_DISABLE 0

#define BQ25892_BOOST_FREQ_MASK      0x20
#define BQ25892_BOOST_FREQ_SHIFT     5
#define BQ25892_BOOST_FREQ_1500K     0
#define BQ25892_BOOST_FREQ_500K      0

#define BQ25892_ICOEN_MASK          0x10
#define BQ25892_ICOEN_SHIFT         4
#define BQ25892_ICO_ENABLE          1
#define BQ25892_ICO_DISABLE         0
#define BQ25892_HVDCPEN_MASK        0x08
#define BQ25892_HVDCPEN_SHIFT       3
#define BQ25892_HVDCP_ENABLE        1
#define BQ25892_HVDCP_DISABLE       0
#define BQ25892_MAXCEN_MASK         0x04
#define BQ25892_MAXCEN_SHIFT        2
#define BQ25892_MAXC_ENABLE         1
#define BQ25892_MAXC_DISABLE        0

#define BQ25892_FORCE_DPDM_MASK     0x02
#define BQ25892_FORCE_DPDM_SHIFT    1
#define BQ25892_FORCE_DPDM          1
#define BQ25892_AUTO_DPDM_EN_MASK   0x01
#define BQ25892_AUTO_DPDM_EN_SHIFT  0
#define BQ25892_AUTO_DPDM_ENABLE    1
#define BQ25892_AUTO_DPDM_DISABLE   0


/* Register 0x03 */
#define BQ25892_REG_03              0x03
#define BQ25892_BAT_LOADEN_MASK     0x80
#define BQ25892_BAT_LOAEN_SHIFT     7
#define BQ25892_WDT_RESET_MASK      0x40
#define BQ25892_WDT_RESET_SHIFT     6
#define BQ25892_WDT_RESET           1

#define BQ25892_OTG_CONFIG_MASK     0x20
#define BQ25892_OTG_CONFIG_SHIFT    5
#define BQ25892_OTG_ENABLE          1
#define BQ25892_OTG_DISABLE         0

#define BQ25892_CHG_CONFIG_MASK     0x10
#define BQ25892_CHG_CONFIG_SHIFT    4
#define BQ25892_CHG_ENABLE          1
#define BQ25892_CHG_DISABLE         0


#define BQ25892_SYS_MINV_MASK       0x0E
#define BQ25892_SYS_MINV_SHIFT      1

#define BQ25892_SYS_MINV_BASE       3000
#define BQ25892_SYS_MINV_LSB        100


/* Register 0x04*/
#define BQ25892_REG_04              0x04
#define BQ25892_EN_PUMPX_MASK       0x80
#define BQ25892_EN_PUMPX_SHIFT      7
#define BQ25892_PUMPX_ENABLE        1
#define BQ25892_PUMPX_DISABLE       0
#define BQ25892_ICHG_MASK           0x7F
#define BQ25892_ICHG_SHIFT          0
#define BQ25892_ICHG_BASE           0
#define BQ25892_ICHG_LSB            64

/* Register 0x05*/
#define BQ25892_REG_05              0x05
#define BQ25892_IPRECHG_MASK        0xF0
#define BQ25892_IPRECHG_SHIFT       4
#define BQ25892_ITERM_MASK          0x0F
#define BQ25892_ITERM_SHIFT         0
#define BQ25892_IPRECHG_BASE        64
#define BQ25892_IPRECHG_LSB         64
#define BQ25892_ITERM_BASE          64
#define BQ25892_ITERM_LSB           64

/* Register 0x06*/
#define BQ25892_REG_06              0x06
#define BQ25892_VREG_MASK           0xFC
#define BQ25892_VREG_SHIFT          2
#define BQ25892_BATLOWV_MASK        0x02
#define BQ25892_BATLOWV_SHIFT       1
#define BQ25892_BATLOWV_2800MV      0
#define BQ25892_BATLOWV_3000MV      1
#define BQ25892_VRECHG_MASK         0x01
#define BQ25892_VRECHG_SHIFT        0
#define BQ25892_VRECHG_100MV        0
#define BQ25892_VRECHG_200MV        1
#define BQ25892_VREG_BASE           3840
#define BQ25892_VREG_LSB            16

/* Register 0x07*/
#define BQ25892_REG_07              0x07
#define BQ25892_EN_TERM_MASK        0x80
#define BQ25892_EN_TERM_SHIFT       7
#define BQ25892_TERM_ENABLE         1
#define BQ25892_TERM_DISABLE        0

#define BQ25892_WDT_MASK            0x30
#define BQ25892_WDT_SHIFT           4
#define BQ25892_WDT_DISABLE         0
#define BQ25892_WDT_40S             1
#define BQ25892_WDT_80S             2
#define BQ25892_WDT_160S            3
#define BQ25892_WDT_BASE            0
#define BQ25892_WDT_LSB             40

#define BQ25892_EN_TIMER_MASK       0x08
#define BQ25892_EN_TIMER_SHIFT      3

#define BQ25892_CHG_TIMER_ENABLE    1
#define BQ25892_CHG_TIMER_DISABLE   0

#define BQ25892_CHG_TIMER_MASK      0x06
#define BQ25892_CHG_TIMER_SHIFT     1
#define BQ25892_CHG_TIMER_5HOURS    0
#define BQ25892_CHG_TIMER_8HOURS    1
#define BQ25892_CHG_TIMER_12HOURS   2
#define BQ25892_CHG_TIMER_20HOURS   3

#define BQ25892_JEITA_ISET_MASK     0x01
#define BQ25892_JEITA_ISET_SHIFT    0
#define BQ25892_JEITA_ISET_50PCT    0
#define BQ25892_JEITA_ISET_20PCT    1


/* Register 0x08*/
#define BQ25892_REG_08              0x08
#define BQ25892_BAT_COMP_MASK       0xE0
#define BQ25892_BAT_COMP_SHIFT      5
#define BQ25892_VCLAMP_MASK         0x1C
#define BQ25892_VCLAMP_SHIFT        2
#define BQ25892_TREG_MASK           0x03
#define BQ25892_TREG_SHIFT          0
#define BQ25892_TREG_60C            0
#define BQ25892_TREG_80C            1
#define BQ25892_TREG_100C           2
#define BQ25892_TREG_120C           3

#define BQ25892_BAT_COMP_BASE       0
#define BQ25892_BAT_COMP_LSB        20
#define BQ25892_VCLAMP_BASE         0
#define BQ25892_VCLAMP_LSB          32


/* Register 0x09*/
#define BQ25892_REG_09              0x09
#define BQ25892_FORCE_ICO_MASK      0x80
#define BQ25892_FORCE_ICO_SHIFT     7
#define BQ25892_FORCE_ICO           1
#define BQ25892_TMR2X_EN_MASK       0x40
#define BQ25892_TMR2X_EN_SHIFT      6
#define BQ25892_BATFET_DIS_MASK     0x20
#define BQ25892_BATFET_DIS_SHIFT    5
#define BQ25892_BATFET_OFF          1

#define BQ25892_JEITA_VSET_MASK     0x10
#define BQ25892_JEITA_VSET_SHIFT    4
#define BQ25892_JEITA_VSET_N150MV   0
#define BQ25892_JEITA_VSET_VREG     1
#define BQ25892_BATFET_RST_EN_MASK  0x04
#define BQ25892_BATFET_RST_EN_SHIFT 2
#define BQ25892_PUMPX_UP_MASK       0x02
#define BQ25892_PUMPX_UP_SHIFT      1
#define BQ25892_PUMPX_UP            1
#define BQ25892_PUMPX_DOWN_MASK     0x01
#define BQ25892_PUMPX_DOWN_SHIFT    0
#define BQ25892_PUMPX_DOWN          1


/* Register 0x0A*/
#define BQ25892_REG_0A              0x0A
#define BQ25892_BOOSTV_MASK         0xF0
#define BQ25892_BOOSTV_SHIFT        4
#define BQ25892_BOOSTV_BASE         4550
#define BQ25892_BOOSTV_LSB          64


#define BQ25892_BOOST_LIM_MASK      0x07
#define BQ25892_BOOST_LIM_SHIFT     0
#define BQ25892_BOOST_LIM_500MA     0x00
#define BQ25892_BOOST_LIM_700MA     0x01
#define BQ25892_BOOST_LIM_1100MA    0x02
#define BQ25892_BOOST_LIM_1300MA    0x03
#define BQ25892_BOOST_LIM_1600MA    0x04
#define BQ25892_BOOST_LIM_1800MA    0x05
#define BQ25892_BOOST_LIM_2100MA    0x06
#define BQ25892_BOOST_LIM_2400MA    0x07


/* Register 0x0B*/
#define BQ25892_REG_0B              0x0B
#define BQ25892_VBUS_STAT_MASK      0xE0           
#define BQ25892_VBUS_STAT_SHIFT     5
#define BQ25892_CHRG_STAT_MASK      0x18
#define BQ25892_CHRG_STAT_SHIFT     3
#define BQ25892_CHRG_STAT_IDLE      0
#define BQ25892_CHRG_STAT_PRECHG    1
#define BQ25892_CHRG_STAT_FASTCHG   2
#define BQ25892_CHRG_STAT_CHGDONE   3

#define BQ25892_PG_STAT_MASK        0x04
#define BQ25892_PG_STAT_SHIFT       2
#define BQ25892_SDP_STAT_MASK       0x02
#define BQ25892_SDP_STAT_SHIFT      1
#define BQ25892_VSYS_STAT_MASK      0x01
#define BQ25892_VSYS_STAT_SHIFT     0


/* Register 0x0C*/
#define BQ25892_REG_0C              0x0c
#define BQ25892_FAULT_WDT_MASK      0x80
#define BQ25892_FAULT_WDT_SHIFT     7
#define BQ25892_FAULT_BOOST_MASK    0x40
#define BQ25892_FAULT_BOOST_SHIFT   6
#define BQ25892_FAULT_CHRG_MASK     0x30
#define BQ25892_FAULT_CHRG_SHIFT    4
#define BQ25892_FAULT_CHRG_NORMAL   0
#define BQ25892_FAULT_CHRG_INPUT    1
#define BQ25892_FAULT_CHRG_THERMAL  2
#define BQ25892_FAULT_CHRG_TIMER    3

#define BQ25892_FAULT_BAT_MASK      0x08
#define BQ25892_FAULT_BAT_SHIFT     3
#define BQ25892_FAULT_NTC_MASK      0x07
#define BQ25892_FAULT_NTC_SHIFT     0
#define BQ25892_FAULT_NTC_TSCOLD    1
#define BQ25892_FAULT_NTC_TSHOT     2

#define BQ25892_FAULT_NTC_WARM      2
#define BQ25892_FAULT_NTC_COOL      3
#define BQ25892_FAULT_NTC_COLD      5
#define BQ25892_FAULT_NTC_HOT       6


/* Register 0x0D*/
#define BQ25892_REG_0D              0x0D
#define BQ25892_FORCE_VINDPM_MASK   0x80        
#define BQ25892_FORCE_VINDPM_SHIFT  7
#define BQ25892_FORCE_VINDPM_ENABLE 1
#define BQ25892_FORCE_VINDPM_DISABLE 0
#define BQ25892_VINDPM_MASK         0x7F
#define BQ25892_VINDPM_SHIFT        0

#define BQ25892_VINDPM_BASE         2600
#define BQ25892_VINDPM_LSB          100


/* Register 0x0E*/
#define BQ25892_REG_0E              0x0E
#define BQ25892_THERM_STAT_MASK     0x80
#define BQ25892_THERM_STAT_SHIFT    7
#define BQ25892_BATV_MASK           0x7F
#define BQ25892_BATV_SHIFT          0
#define BQ25892_BATV_BASE           2304
#define BQ25892_BATV_LSB            20


/* Register 0x0F*/
#define BQ25892_REG_0F              0x0F
#define BQ25892_SYSV_MASK           0x7F
#define BQ25892_SYSV_SHIFT          0
#define BQ25892_SYSV_BASE           2304
#define BQ25892_SYSV_LSB            20


/* Register 0x10*/
#define BQ25892_REG_10              0x10
#define BQ25892_TSPCT_MASK          0x7F
#define BQ25892_TSPCT_SHIFT         0
#define BQ25892_TSPCT_BASE          21
#define BQ25892_TSPCT_LSB           465//should be 0.465,kernel does not support float

/* Register 0x11*/
#define BQ25892_REG_11              0x11
#define BQ25892_VBUS_GD_MASK        0x80
#define BQ25892_VBUS_GD_SHIFT       7
#define BQ25892_VBUSV_MASK          0x7F
#define BQ25892_VBUSV_SHIFT         0
#define BQ25892_VBUSV_BASE          2600
#define BQ25892_VBUSV_LSB           100


/* Register 0x12*/
#define BQ25892_REG_12              0x12
#define BQ25892_ICHGR_MASK          0x7F
#define BQ25892_ICHGR_SHIFT         0
#define BQ25892_ICHGR_BASE          0
#define BQ25892_ICHGR_LSB           50


/* Register 0x13*/
#define BQ25892_REG_13              0x13
#define BQ25892_VDPM_STAT_MASK      0x80
#define BQ25892_VDPM_STAT_SHIFT     7
#define BQ25892_IDPM_STAT_MASK      0x40
#define BQ25892_IDPM_STAT_SHIFT     6
#define BQ25892_IDPM_LIM_MASK       0x3F
#define BQ25892_IDPM_LIM_SHIFT      0
#define BQ25892_IDPM_LIM_BASE       100
#define BQ25892_IDPM_LIM_LSB        50


/* Register 0x14*/
#define BQ25892_REG_14              0x14
#define BQ25892_RESET_MASK          0x80             
#define BQ25892_RESET_SHIFT         7
#define BQ25892_RESET               1
#define BQ25892_ICO_OPTIMIZED_MASK  0x40
#define BQ25892_ICO_OPTIMIZED_SHIFT 6
#define BQ25892_PN_MASK             0x38
#define BQ25892_PN_SHIFT            3
#define BQ25892_TS_PROFILE_MASK     0x04
#define BQ25892_TS_PROFILE_SHIFT    2
#define BQ25892_DEV_REV_MASK        0x03
#define BQ25892_DEV_REV_SHIFT       0


#endif
